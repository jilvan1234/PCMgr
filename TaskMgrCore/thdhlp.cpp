#include "stdafx.h"
#include "ntdef.h"
#include "thdhlp.h"
#include "prochlp.h"
#include <Psapi.h>

extern NtSuspendThreadFun NtSuspendThread;
extern NtResumeThreadFun NtResumeThread;
extern NtTerminateThreadFun NtTerminateThread;
extern NtOpenThreadFun NtOpenThread;
extern NtQueryInformationThreadFun NtQueryInformationThread;
extern RtlNtStatusToDosErrorFun RtlNtStatusToDosError;
extern RtlGetLastWin32ErrorFun RtlGetLastWin32Error;
extern NtQuerySystemInformationFun NtQuerySystemInformation;

M_API NTSTATUS MOpenThreadNt(DWORD dwId, PHANDLE pLandle, DWORD dwPId)
{
	HANDLE hThread;
	OBJECT_ATTRIBUTES ObjectAttributes;
	CLIENT_ID ClientId;

	ObjectAttributes.Length = sizeof(OBJECT_ATTRIBUTES);
	ObjectAttributes.RootDirectory = NULL;
	ObjectAttributes.ObjectName = NULL;
	ObjectAttributes.Attributes = OBJ_KERNEL_HANDLE | OBJ_CASE_INSENSITIVE;
	ObjectAttributes.SecurityDescriptor = NULL;
	ObjectAttributes.SecurityQualityOfService = NULL;

	ClientId.UniqueThread = ((PVOID)(ULONG_PTR)dwId);
	ClientId.UniqueProcess = ((PVOID)(ULONG_PTR)dwPId);

	DWORD NtStatus = NtOpenThread(
		&hThread,
		THREAD_ALL_ACCESS,
		&ObjectAttributes,
		&ClientId);

	if (NtStatus == 0) {
		*pLandle = hThread;
		return 0;
	}
	else {
		return 0;
	}
}
M_API NTSTATUS MGetThreadBasicInformation(HANDLE ThreadHandle, PTHREAD_BASIC_INFORMATION BasicInformation)
{
	return NtQueryInformationThread(
		ThreadHandle,
		ThreadBasicInformation,
		BasicInformation,
		sizeof(THREAD_BASIC_INFORMATION),
		NULL
	);
}
M_API NTSTATUS MGetThreadTeb(HANDLE hThread, PTEB*pPTeb) {
	THREAD_BASIC_INFORMATION tbi;
	NTSTATUS status = MGetThreadBasicInformation(hThread, &tbi);
	if (NT_SUCCESS(status))
		if (pPTeb)*pPTeb = tbi.TebBaseAddress;
	return status;
}
M_API NTSTATUS MGetThreadWin32StartAddress(HANDLE hThread, PVOID * outStartAddress) {
	PVOID startaddr = 0;
	NTSTATUS status = NtQueryInformationThread(hThread, ThreadQuerySetWin32StartAddress, &startaddr, sizeof(startaddr), NULL);
	if (NT_SUCCESS(status))
		if (outStartAddress)*outStartAddress = startaddr;
	return status;
}

M_API NTSTATUS MTerminateThreadNt(HANDLE handle)
{
	return NtTerminateThread(handle, 0);
}
M_API NTSTATUS MResumeThreadNt(HANDLE handle)
{
	ULONG count = 0;
	return NtResumeThread(handle, &count);
}
M_API NTSTATUS MSuspendThreadNt(HANDLE handle)
{
	ULONG count = 0;
	return NtSuspendThread(handle, &count);
}



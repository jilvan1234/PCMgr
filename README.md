PCMgr [![License](https://img.shields.io/badge/Licence-MIT-blue.svg)]()
=======================
 Windows 任务管理器重制版 Rebulid of Windows task manager
===
这是一个 Windows 任务管理器重制版，添加了任务管理器不具有的功能，并且已有与Windows任务管理器可以媲美。<br/>
使用WinAPI以及C#开发，可以进行查看进程、进程信息、结束进程等。<br/>
目前只完成部分功能。<br/>

This is an rebulid version of the Windows Task Manager that adds features that the Task Manager does not have, And it is very similar to the Windows task manager. <br/>
Use WinAPI and C# development, you can view the process, process information, end the process, etc. <br/>
At present, only part of the functions are completed.

特点 Features
---
- 完全的进程查看以及结束、暂停运行、继续运行进程
- 查看进程线程、模块、窗口、句柄
- 与自带任务管理器非常相似
- 最低支持 Windows7
- 一些任务管理器没有的功能
- 内核还未完全开发完成，完成以后可以获取更多更强的权限
- 这是完全开源的软件，你可以学习其中的原理

编译 Bulid
---
你至少需要使用 Visual Studio 2017 进行编译，需要C#和C++的生成工具。其中内核驱动最好使用WDK10<br/>
You need to use Visual Studio 2017 to compile at least, and must install C# and C++ in Visual studio. The kernel driver is best to use WDK10.

需求 Requirement
---
至少需要Windows7，并且需要.Net Framework 4.0<br/>
At least in Windows7 and installed .Net Framework 4.0<br/>

截图 ScreenShot
---
![Image1](https://raw.githubusercontent.com/717021/PCMgr/master/image1.png)<br/>
![Image11](https://raw.githubusercontent.com/717021/PCMgr/master/image11.png)<br/>
![Image6](https://raw.githubusercontent.com/717021/PCMgr/master/image6.png)<br/>
![Image10](https://raw.githubusercontent.com/717021/PCMgr/master/image10.png)<br/>
![Image2](https://raw.githubusercontent.com/717021/PCMgr/master/image2.png)<br/>
![Image3](https://raw.githubusercontent.com/717021/PCMgr/master/image3.png)<br/>
![Image4](https://raw.githubusercontent.com/717021/PCMgr/master/image4.png)<br/>
![Image5](https://raw.githubusercontent.com/717021/PCMgr/master/image5.png)<br/>

![Image7](https://raw.githubusercontent.com/717021/PCMgr/master/image7.png)<br/>
![Image8](https://raw.githubusercontent.com/717021/PCMgr/master/image8.png)<br/>
![Image9](https://raw.githubusercontent.com/717021/PCMgr/master/image9.png)<br/>

许可 License
---
本程序遵循 MIT 协议
Theme PCMgr is covered with MIT license

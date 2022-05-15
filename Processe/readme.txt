

1.信号

    产生信号的几种方式:  内核通知、 硬件终端、前台程序输入指定字符、 系统状态、 运行kill

   1) SIGHUP        挂断。本信号在用户终端连接(正常或非正常)结束时发出
   2) SIGINT	    通知前台进程终止进程
   3) SIGQUIT	    与SIGINT相似，但会产生core文件
   4) SIGILL	    执行了非法指令或是堆栈溢出
   5) SIGTRAP       由断点指令或其它陷阱（trap）指令产生. 由debugger使用
   9) SIGKILL	    强制杀死进程，本信号不能被阻塞、处理和忽略
  11) SIGSEGV       段错误，访问非法内存
  13) SIGPIPE	    管道破裂。读管道没打开或者意外终止就往管道写，写进程会收到SIGPIPE信号。用Socket通信的两个进程，写进程在写Socket的时候，读进程已经终止。
  14) SIGALRM	    时钟定时信号,
  15) SIGTERM       程序结束(terminate)信号, 与SIGKILL不同的是该信号可以被阻塞和处理
  17) SIGCHLD	    子进程（child）结束时, 父进程会收到这个信号。
  18) SIGCONT
  19) SIGSTOP






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






生产者-消费者模型


互斥锁
    线程抢到互斥锁的几率应该是随机的，关键是线程的执行顺序问题。
    linux在没有设定线程调度策略的时，默认采用的是时间片轮转的调度策略。
    多线程中子线程是在主线程有空闲的条件下才执行的。所以主线程忙，或者没有执行等待。那么子线程是不会执行的。

条件变量
    条件变量不是锁，但是它可以阻塞线程或者释放线程

    pthread_cond_t  类型
    pthread_cond_wait(pthread_cond_t *restrict cond, pthread_mutex_t *restrict mutex)   // 阻塞线程
    pthread_cond_signal(pthread_cond_t *cond)       // 唤醒一个线程
    pthread_cond_broadcast(pthread_cond_t *cond)    // 唤醒所有线程



信号量
    类似于条件变量，用于阻塞线程.

    sem_t   类型

    sem_init(sem_t *sem, int pshared, unsigned int value)        // 初始化信号量
            pshared来指定是使用于线程还是进程: 0线程 非0进程
    sem_destroy(sem_t * sem)    // 释放资源
    sem_wait(sem_t * sem);      // 消耗一个值,如果值为0则阻塞线程直到信号量里的值超过0
    sem_post(sem_t * sem);      // 增加一个值,唤醒处于sem_wait的线程



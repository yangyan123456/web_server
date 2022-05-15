////
//// Created by yyq on 2022/5/10.
////
//#include <sys/time.h>
//#include <iostream>
//
//using namespace std;
//
//int main(){
//
//    struct itimerval new_timer;
//
//    // 间隔时间
//    new_timer.it_interval.tv_sec = 2;
//    new_timer.it_interval.tv_usec = 2;
//
//    // 延迟时间
//    new_timer.it_value.tv_sec = 3;
//    new_timer.it_value.tv_usec = 0;
//
//
//    setitimer(ITIMER_REAL, &new_timer, nullptr);
//
//    return  0;
//}

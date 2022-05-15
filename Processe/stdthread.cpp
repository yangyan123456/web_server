////
//// Created by yyq on 2022/5/10.
////
//
//#include <thread>
//#include <iostream>
//
//using std::cout;
//using std::cin;
//using std::endl;
//using std::thread;
//
//int val = 10000;
//
//void work(){
//    for(int i = 0; i < 1000000; ++i) {
//        ++val;
//        --val;
//    }
//    cout << std::this_thread::get_id() << "\tover" << endl;
//}
//
//
//int main() {
//    int j  = 0;
//    std::thread a(work);
//    std::thread b(work);
//    std::thread c(work);
//
//    a.join();
//    b.join();
//    c.join();
//
//    cout << "val:" <<val << endl;
//}
////
//// Created by yyq on 2022/5/10.
////
//#include <iostream>
//#include <chrono>
//#include <mutex>
//#include <thread>
//#include <atomic>
//#include <condition_variable>
//#include <functional>
//
//class Timer{
//public:
//    Timer(): _expired(true), _try_to_expire(false){}
//
//    Timer(const Timer& timer){
//        _expired = timer._expired.load();
//        _try_to_expire = timer._try_to_expire.load();
//
//    }
//
//    ~Timer(){
//        stop();
//    }
//
//    void start(int interval, std::function<void()> task){
//        // 如果定时器已经启动了，就不再启动
//        if (_expired == false) return;
//
//        // 启动异步定时器， 启动线程并在该线程中等待
//        _expired = false;
//        std::thread([this, interval, task]() {
//            while (!_try_to_expire) {
//                // 定期做这个任务，直到时间到了
//                std::this_thread::sleep_for(std::chrono::milliseconds(interval)) ;
//                task();
//            }
//            {
//                //计时器停止，更新条件变量expired并唤醒主线程
//                std::unique_lock<std::mutex> locker(_mutex);
//                _expired = true;
//                _expired_cond.notify_one();
//            }
//        }).detach();
//    }
//
//    void startOnce(int delay, std::function<void()> task) {
//        std::thread([delay, task]() {
//            std::this_thread::sleep_for(std::chrono::milliseconds(delay));
//            task();
//        }).detach();
//    }
//
//    void stop() {
//
//        //不要重复去停止时间
//        if(_expired) return;
//        if(_try_to_expire) return;
//
//        // 等待定时器
//        _try_to_expire = true; // 使计时器在循环停止时结束
//
//        std::unique_lock<std::mutex> locker(_mutex);
//        _expired_cond.wait(locker, [this]{return _expired == true;});
//
//        // 重置定时器
//        if (_expired == true)
//            _try_to_expire = false;
//    }
//
//
//private:
//    std::atomic<bool> _expired;     // 计时器停止状态
//    std::atomic<bool> _try_to_expire;   // 计时器正在停止运行
//    std::mutex _mutex;
//    std::condition_variable _expired_cond;
//};
//
//
//
//void func1()
//{
//    std::cout << std::this_thread::get_id << "trigger func1" << std::endl;
//}
//
//void func2(int x)
//{
//    std::cout << std::this_thread::get_id <<" trigger func2, x: " << x << std::endl;
//}
//
//int main(int argc, char* argv[])
//{
//    Timer timer;
//
//    // execute task every timer interval
//    std::cout << "--- start period timer ----" << std::endl;
//    timer.start(1000, std::bind(func2, 1));
//    timer.start(1000, std::bind(func2, 2));
//    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
//    timer.stop();
//    std::cout << "--- stop period timer ----" << std::endl;
//
//    // execute task once after delay
//    std::cout << "--- start one shot timer ----" << std::endl;
//    timer.startOnce(1000, func1);
//    std::cout << "--- stop one shot timer ----" << std::endl;
//
//    getchar();
//    return 0;
//}
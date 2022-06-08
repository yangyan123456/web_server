/*
 *
 *      int select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval *timeout);
 *      // nfds 被监听的文件描述符的总数，同时也是监听的文件描述符的最大值
 *      // readfds, writefds, exceptfds 分别指向可读可写和异常事件对应的文件描述符集合
 *      // timeout设置超时值， 0可以表示非阻塞，NULL表示一直阻塞直到有文件描述符发生变化
 *
 *      void FD_CLR(int fd, fd_set *set);
 *      // 清除所有文件描述符
 *
 *      int  FD_ISSET(int fd, fd_set *set);
 *      // 测试fd_set的fd位是否被设置
 *
 *      void FD_SET(int fd, fd_set *set);
 *      // 设置fd_set的fd位
 *
 *      void FD_ZERO(fd_set *set);
 *      // 清除fd_set的fd位
 *
 *
 */

//#include <unistd.h>
//#include <string>
//#include <sys/select.h>
//#include <arpa/inet.h>
//#include <cstring>
//#include <cassert>
//#include <iostream>
//
//using std::string;
//using std::cout;
//using std::cin;
//using std::endl;
//
//int main() {
//
//    sockaddr_in address;
//    memset(&address,  0, sizeof(address));
//
//    address.sin_family = AF_INET;
//    address.sin_port = htons(9999);
//    inet_pton(AF_INET, "127.0.0.1", &address);
//
//    int listenfd = socket(PF_INET, SOCK_STREAM, 0);
//    assert(listenfd != -1);
//
//    int ret = bind(listenfd, reinterpret_cast<sockaddr*>(&address), sizeof(address));
//    assert(ret != -1);
//
//    ret = listen(listenfd, 100);
//    assert(ret != -1);
//
//    sockaddr_in client_addr;
//    socklen_t client_addr_length = sizeof(client_addr);
//
//    int connfd = accept(listenfd, reinterpret_cast<sockaddr*>(&client_addr), &client_addr_length);
//
//    if(connfd < 0) {
//        cout << " errno is " << errno << endl;
//    }
//
//    string buf[1024];
//    fd_set read_fds;
//    fd_set exception_fds;
//    FD_ZERO(&read_fds);
//    FD_ZERO(&exception_fds);
//
//    while(true) {
//        memset(buf, 0, sizeof(buf));
//
//        FD_SET(connfd, &read_fds);
//        FD_SET(connfd, &exception_fds);
//
//        ret = select(connfd + 1, &read_fds, nullptr, &exception_fds, nullptr);
//
//        if (ret < 0) {
//            cout << "selection failure" << endl;
//            break;
//        }
//
//        if (FD_ISSET(connfd, &read_fds)) {
//
//            ret = recv(connfd, buf, sizeof(buf), 0);
//            if (ret <= 0) {
//                break;
//            }
//            cout << "get " << ret << " bytes of normal data" << buf << endl;
//        }
//    }
//
//    close(listenfd);
//    return 0;
//}

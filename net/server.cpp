////
//// Created by yyq on 2022/5/31.
////
//
//#include <pthread.h>
//#include <iostream>
//#include <arpa/inet.h>
//#include <sys/socket.h>
//#include <unistd.h>
//
//int main() {
//    while (true) {
//        int cfd = socket(AF_INET, SOCK_STREAM, 0);
//        sockaddr_in server_addr;
//        server_addr.sin_port = htons(9999);
//        server_addr.sin_family = AF_INET;
//        inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);
//
//        int ret = connect(cfd, (sockaddr *) &server_addr, sizeof(server_addr));
//        if (ret == 0) std::cout << "client connect" << std::endl;
//        sleep(5);
//    }
//    return 0;
//}
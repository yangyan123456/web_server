////
//// Created by yyq on 2022/5/24.
////
//#include <arpa/inet.h>
//#include <bits/socket.h>
//#include <sys/socket.h>
//#include <string>
//#include <cassert>
//#include <unistd.h>
//#include <iostream>
//
//
//int main(int argc, char* argv[]) {
//
//   int listenFd =  socket(AF_INET, SOCK_STREAM, 0);  // 给了地址族
//
//   sockaddr_in listenAddr;
//   listenAddr.sin_family = AF_INET;
//   listenAddr.sin_addr.s_addr = INADDR_ANY; // 地址
//   int port = std::stoi("9999");    // 字符串转数字
//   listenAddr.sin_port = htons(port);
//
//   int ret = bind(listenFd, (sockaddr*)&listenAddr, sizeof(listenAddr));
//   assert(ret != -1);
//   int reuse = 1;
//   setsockopt(listenFd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));   // 端口复用
//   ret = listen(listenFd, 10);
//   assert(ret != -1);
//
//   sleep(5);
//
//   while(true) {
//       sockaddr_in client;
//       socklen_t client_addr_length = sizeof(client);
//       int connfd = accept(listenFd, (sockaddr *) &client, &client_addr_length);
//       while (connfd > 0) {
//           std::cout << "connected" << std::endl;
//           close(connfd);
//           break;
//       }
//       sleep(5);
//   }
//    close(listenFd);
//    return 0;
//}

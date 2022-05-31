//
// Created by yyq on 2022/5/16.
//

#include <unistd.h>
#include <arpa/inet.h>
#include <iostream>
#include <pthread.h>
#include <queue>
#include <sys/syscall.h>

pthread_cond_t cond;
pthread_mutex_t mtx;

std::queue<int> q;
int i = 0;
void * producer(void *pVoid){
    while(i < 10000) {
        pthread_mutex_lock(&mtx);
        q.push(i++);
        std::cout << syscall(SYS_gettid)<<"producer : " << i << std::endl;
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mtx);
        sleep(0.5);
    }
}

void* consumer(void *cVoid){
    while(i < 10000) {
        pthread_mutex_lock(&mtx);
        pthread_cond_wait(&cond, &mtx);
        int b = q.front();
        q.pop();
        std::cout << syscall(SYS_gettid)<<" consumer : " << b << std::endl;
        pthread_mutex_unlock(&mtx);
    }
}

//int main() {
//
//    pthread_t pids[5];
//    pthread_t cids[5];
//    pthread_t cid1s[5];
//    pthread_t cid2s[5];
//    for(int i = 0; i < 5; ++i) {
//        pthread_create(&pids[i], nullptr, producer, nullptr);
//        pthread_create(&cids[i], nullptr, consumer, nullptr);
//        pthread_create(&cid1s[i], nullptr, consumer, nullptr);
//        pthread_create(&cid2s[i], nullptr, consumer, nullptr);
//    }
//    for(int i = 0; i < 5; ++i) {
//        pthread_detach(pids[i]);
//        pthread_detach(cids[i]);
//        pthread_detach(cid1s[i]);
//        pthread_detach(cid2s[i]);
//    }
//
//    getchar();
//    return 0;
//}
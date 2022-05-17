//
// Created by yyq on 2022/5/17.
//

#include <pthread.h>
#include <iostream>
#include <semaphore.h>
#include <unistd.h>
#include <syscall.h>


sem_t psem;
sem_t csem;

pthread_mutex_t mtx;

int i = 0;


void* producer(void* args){
    while(true) {
        sem_wait(&psem);
        pthread_mutex_lock(&mtx);
        std::cout << syscall(SYS_gettid) << "product: " << i++ << std::endl;
        pthread_mutex_unlock(&mtx);
        sem_post(&csem);
        //usleep(100);
    }
}

void* consumer(void* args){
    while(true) {
        sem_wait(&csem);
        pthread_mutex_lock(&mtx);
        std::cout << syscall(SYS_gettid) << "consumer: " << i-- << std::endl;
        pthread_mutex_unlock(&mtx);
        sem_post(&psem);
    }
}

int main(){
    sem_init(&psem, 0, 8);
    sem_init(&csem, 0, 0);

    pthread_t pid[8];
    pthread_t cid[8];

    for(int i = 0; i < 8; ++i){
        pthread_create(&pid[i], nullptr, producer, nullptr);
        pthread_create(&cid[i], nullptr, consumer, nullptr);
    }

    for(int i = 0; i < 8; ++i){
        pthread_detach(pid[i]);
        pthread_detach(cid[i]);
    }

    getchar();
    return 0;
}
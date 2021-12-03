#include "thread.c"
// #include "./kernel/spinlock.h"
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

int passCount;
int numPass;
// struct spinlock *lock;
struct lock_t *lock_t;
int currPID = 0;
int numThread; 

void start_routine(void* arg) {
    int threadID = *((int*)arg);
    while(passCount < numPass) {
        lock_acquire(lock_t);
        if(threadID == currPID) {
            passCount++;
            currPID++;
            if(currPID == numThread) {
                currPID = 0;
            }
            printf("Pass number no: %d, Thread %d is passing the token to thread %d", passCount, threadID, currPID);
        } else {
            lock_release(lock_t);
        }
    }
}

int main(int argc, char *argv) {
    numThread = (int)argv[1];
    numPass = (int)argv[2];
    passCount = 0;
    lock_init(lock_t);

    for(int i = 0; i < numThread; i++) {
        void * ptr = &i;
        thread_create((void *)start_routine, ptr);
    }

    // wait();
    // exit();
    return 0;
}

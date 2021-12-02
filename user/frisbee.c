#include "./kernel/thread_library.h"
#include "spinlock.h"
#include <stdio.h>

int passCount;
int numPass;
struct spinlock *lock;
int currPID = 0;

void start_routine(void *arg) {
    int threadID = (int) arg;
    while(passCount < numPass) {
        lock_acquire();
        if(threadID == currPID) {
            passCount++;
            currPID++;
            if(currPID == numThread) {
                currPID = 0;
            }
            printf("Pass number no: %i, Thread %i is passing the token to thread %i", passCount, threadID, currPID);
        } else {
            lock_release(lock);
        }
    }
}

int main(int argc, char *argv) {
    numThread = argv[1];
    numPass = argv[2];
    passCount = 0;
    lock_init(lock);

    for(int i = 0; i < numThread; i++) {
        thread_create((void *)start_routine, (void *)i);
    }

    wait();
    exit();
}
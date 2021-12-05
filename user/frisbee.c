#include "thread.c"

int passCount;
int numPass;
struct lock_t lock;

int currPID = 0;
int numThread; 


void start_routine(void* arg) {
    // lock_init(lock);
    // printf("in start routine \n");
    int threadID = *((int*)arg);
    // while(passCount < numPass) {
        // lock_acquire(&lock);
        if(threadID == currPID) {
            lock_acquire(&lock);
            passCount++;
            currPID++;
            if(currPID == numThread) {
                currPID = 0;
            }
            printf("Pass number no: %d, Thread %d is passing the token to thread %d \n", passCount, threadID, currPID);
            lock_release(&lock);
        }
    }
// }

int main(int argc, char *argv) {
    numThread = (int)argv[1];
    numPass = (int)argv[2];
    passCount = 0;
    lock_init(&lock);

    for(int i = 0; i < numThread; i++) {
        void * ptr = &i;
        thread_create((void *)start_routine, ptr);
    }

    // wait();
    // exit();
    return 0;
}

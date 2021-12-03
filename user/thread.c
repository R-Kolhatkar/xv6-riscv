// #include "thread_.h"
#include <stdio.h>
#include "./kernel/types.h"
#include "./kernel/param.h"
#include "./kernel/memlayout.h"
#include "./kernel/spinlock.h"
#include "./kernel/riscv.h"
#include "./kernel/proc.h"
#include "./kernel/defs.h"

int thread_create(void*(*start_routine)(void*), void *arg){
    // struct spinlock *lock_t;
    // lock_init(lock_t);
    // void *ptr = malloc(sizeof(int));
    // *((int*)arg)

        clone(&(myproc()->trapframe->sp), *((int*)arg));
        // clone();
        start_routine(arg);
        return 0; 
}
struct lock_t{
    int locked; 
};

void lock_init(struct lock_t* lock_t){
    lock_t->locked = 0; 
    // lock_t->cpu =  0; 
}
void lock_acquire(struct lock_t* lock_t){
    push_off(); // disable interrupts to avoid deadlock.
    // if(holding(lock_t))
    //     panic("acquire");
    while(__sync_lock_test_and_set(&lock_t->locked, 1) != 0)
    ;
    __sync_synchronize();
    // lock_t->cpu = mycpu();

}
void lock_release(struct lock_t* lock_t){
    // if(!holding(lock_t)){
    // panic("release");
    // }
    // lock_t->cpu = 0;
    __sync_synchronize();
    __sync_lock_release(&lock_t->locked);

    pop_off();
}

#include "thread_library.h"
#include <stdio.h>

int thread_create(void *(*start_routine)(void *), void *arg)
{
    // struct spinlock *lock_t;
    // lock_init(lock_t);
    if (clone() == 0)
    {
        return 0; // successful
    }
    return -1; // unsuccessful
}
void lock_init(struct spinlock *lock_t)
{
    lock_t->locked = 0;
    lock_t->cpu = 0;
}
void lock_acquire(struct spinlock *lock_t)
{
    push_off(); // disable interrupts to avoid deadlock.
    if (holding(lock_t))
        panic("acquire");
    while (__sync_lock_test_and_set(&lock_t->locked, 1) != 0)
        ;
    __sync_synchronize();
    lock_t->cpu = mycpu();
}
void lock_release(struct spinlock *lock_t)
{
    if (!holding(lock_t))
    {
        panic("release");
    }
    lock_t->cpu = 0;
    __sync_synchronize();
    __sync_lock_release(&lock_t->locked);

    pop_off();
}
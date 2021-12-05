// #include "./kernel/proc.c"
#include "../kernel/types.h"
#include "../kernel/stat.h"
#include "user.h"
// // #include <stdio.h>
// #include "./kernel/types.h"
// #include "./kernel/param.h"
// #include "./kernel/memlayout.h"
// #include "../kernel/spinlock.c"
// #include "../kernel/spinlock.c"
// #include "./kernel/riscv.h"
// #include "../kernel/proc.c"
// #include "./kernel/defs.h"
// #include <stddef.h>

int thread_create(void*(*start_routine)(void*), void *arg){
        int i = *((int*)arg);
        clone(i+1);

        // clone(p->trapframe->sp, *((int*)arg));
        
        start_routine(arg);
        return 0; 
}


int test_and_set(int* lockPtr){
    int oldValue = *lockPtr;
    *lockPtr = 1;
    return oldValue; 
}

struct lock_t {
    // int ticket; 
    // int turn;
    int locked;
};

void lock_init(struct lock_t *lock)
{
//   lock->ticket = 0;
//   lock->turn = 0;
    lock->locked = 0; 
}

void lock_acquire(struct lock_t *lock)
{
    // push_off();
//   int turn = fetch_and_add(&lock->ticket, 1);
  while(test_and_set(&(lock->locked)) == 1) //spin lock
  {}
}

void lock_release(struct lock_t *lock)
{
//   lock->turn = lock->turn + 1;
     lock->locked = 0;
    //  pop_off();
}








// void lock_init(struct lock_t *lock){
//     lock->locked = 0; 
//     // lock_t->cpu =  0; 
// }
// void lock_acquire(struct lock_t *lock){
//     // push_off(); // disable interrupts to avoid deadlock.

//     // if(holding(lock_t))
//     //     panic("acquire");
//     while (lock->locked == 1){
//         ;
//     }
//     lock->locked = 1;
//     // while(__sync_lock_test_and_set(&lock_t->locked, 1) != 0)
//     // ;
//     // __sync_synchronize();
//     // lock_t->cpu = mycpu();

// }
// void lock_release(struct lock_t *lock){
// //     if(!holding(lock_t)){
// //     panic("release");
// //     }
//     lock->locked = 0;
//     // lock_t->cpu = 0;
//     // __sync_synchronize();
//     // __sync_lock_release(&lock_t->locked);

//     // pop_off();
// }
// void
// pop_off(void)
// {
//   struct cpu *c = mycpu();
//   if(intr_get())
//     panic("pop_off - interruptible");
//   if(c->noff < 1)
//     panic("pop_off");
//   c->noff -= 1;
//   if(c->noff == 0 && c->intena)
//     intr_on();
// }
// void
// push_off(void)
// {
//   int old = intr_get();

//   intr_off();
//   if(mycpu()->noff == 0)
//     mycpu()->intena = old;
//   mycpu()->noff += 1;
// }

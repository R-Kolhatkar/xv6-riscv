#include "spinlock.h"

int thread_create(void*(*start_routine)(void*), void *arg);
void lock_init(struct spinlock *lock_t);
void lock_acquire(struct spinlock *lock_t);
void lock_release(struct spinlock *lock_t);
void start_routine(void *arg);





// struct lock_t{
//     struct lock_t *ptr; 
// };
// struct lock{
//     int locked;
//     public:
//         void lock_init(struct lock_t *);
// };

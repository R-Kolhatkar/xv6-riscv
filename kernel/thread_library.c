#include "thread_library.h"

int thread_create(void*(*start_routine)(void*), void *arg){

}
void lock_init(struct lock_t *){
    
}
void lock_acquire(struct lock_t *);
void lock_release(struct lock_t *);
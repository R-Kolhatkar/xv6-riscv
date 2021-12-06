#include "../kernel/types.h"
#include "../kernel/stat.h"
#include "user.h"
struct lock_t {
    int locked;
};
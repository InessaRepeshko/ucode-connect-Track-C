#include "libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    if (ptr == NULL) {
        return malloc(size);
    }

    if (size == 0) {
        free(ptr);
        return malloc(size);
    }

    size_t prev_size = malloc_size(ptr);

    if (prev_size >= size) {
        return ptr;
    }

    void *new_ptr = malloc(size);

    if (new_ptr == NULL) {
        return NULL;
    }

    new_ptr = mx_memcpy(new_ptr, ptr, prev_size);
    free(ptr);

    return new_ptr;
}


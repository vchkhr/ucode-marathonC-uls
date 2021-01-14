#include "libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t len) {
    for (size_t i = 0; i < len; i++)
        ((unsigned char *)dst)[i] = ((const unsigned char *)src)[i];
        
    return dst;
}

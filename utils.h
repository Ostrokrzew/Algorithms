#ifndef ENGINEERPROJECT_UTILS_H
#define ENGINEERPROJECT_UTILS_H

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <limits.h>

//amount of numbers randomly generated
#define AMOUNT (UINT_MAX)

//change numeric types to faster versions
#define uint8_t uint_fast8_t
#define uint16_t uint_fast16_t
#define uint32_t uint_fast32_t
#define uint64_t uint_fast64_t
#define int8_t int_fast8_t
#define int16_t int_fast16_t
#define int32_t int_fast32_t
#define int64_t int_fast64_t

static void* zmalloc(size_t size) {
    void *ptr = malloc(size);
    memset(ptr, 0, size);
    return ptr;
}

static inline void swap_xor(int32_t &a, int32_t &b) {
    if (a == b)
        return;
    a ^= b;
    b ^= a;
    a ^= b;
}

static void swap_tmp(long &a, long &b) {
    long tmp = a;
    a = b;
    b = tmp;
}

#endif //ENGINEERPROJECT_UTILS_H

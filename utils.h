#ifndef ENGINEERPROJECT_UTILS_H
#define ENGINEERPROJECT_UTILS_H

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <limits.h>

//amount of numbers randomly generated
#define AMOUNT (262144/16)

//change numeric types to faster versions
#define u8 uint_fast8_t
#define u16 uint_fast16_t
#define u32 uint_fast32_t
#define u64 uint_fast64_t
#define i8 int_fast8_t
#define i16 int_fast16_t
#define i32 int_fast32_t
#define i64 int_fast64_t

static void* zmalloc(size_t size) {
	void *ptr = malloc(size);
	memset(ptr, 0, size);
	return ptr;
}

#endif //ENGINEERPROJECT_UTILS_H

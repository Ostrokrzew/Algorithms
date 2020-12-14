#ifndef ENGINEERPROJECT_RUN_ALGORITHMS_H
#define ENGINEERPROJECT_RUN_ALGORITHMS_H

#include "headers.h"

//declare collective functions
uint8_t run_normal_algorithms(const int32_t&);
uint8_t run_normal_sort_algorithms();
uint8_t run_normal_search_algorithms(const int32_t&);

uint8_t run_refactored_algorithms(const int32_t&);
uint8_t run_refactored_sort_algorithms();
uint8_t run_refactored_search_algorithms(const int32_t&);

static uint8_t validate_order(const char *input_file) {
	uint8_t result = SUCCESS;
	int32_t *table = read_to_table(input_file);
	for (size_t i = 0; i < AMOUNT-1; i++) {
		if (*table > *(table + 1)) {
			fprintf(stderr, "%ld should be greater or equal %ld.\n", *(table + 1), *table);
			result = ERR_WRG_ORDR;
		}
	}
	free(table);

	return result;
}


#endif //ENGINEERPROJECT_RUN_ALGORITHMS_H

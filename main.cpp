/*** Licence
 * This code is released under infoanarchistic licence and I, as an author, don't care about its usage.
 * It can be used for all kinds of purposes, but without any warranty and support.
 * It's up to user to be polite and show the source or the author, but it's not necessary at all.
 * You can delete this whole text above and have fun.
 ***/

#include "run_algorithms.h"

//run program
int main() {
	uint8_t result;
	int32_t number = NULL;

	//generate data to sort
	result = random_number_generator(GENERATED_DATA_FILE);
	if(result) {
		fprintf(stderr, "Data wasn't generated successfully. Generation stopped with code %u.", result);
	return GNRT_DATA_FAIL;
	}

	//draw random number from data to search for
	result = draw_number(GENERATED_DATA_FILE.c_str(), number);
	if(result) {
		fprintf(stderr, "Drawing random element from data failed with code %u.", result);
		return DRAW_NMBR_FAIL;
	}

	result = run_normal_algorithms(number);
	if (result)
		return result;

	result = run_refactored_algorithms(number);
	if (result)
		return result;

	//finish program
	fprintf(stdout, "Every algorithm done its work. It's time to say goodbye.\n"
		"Sławomir Jankowski 2020");

	return SUCCESS;
}

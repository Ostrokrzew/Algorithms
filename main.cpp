/*** Licence
 * This code is released under infoanarchistic licence and I, as an author, don't care about its usage.
 * It can be used for all kinds of purposes, but without any warranty and support.
 * It's up to user to be polite and show the source or the author, but it's not necessary at all.
 * You can delete this whole text above and have fun.
 ***/

#include "run_algorithms.h"

//run program
int main(int argc, char **argv) {
	u8 all = 1, table = 0, list = 0, tree = 0, both = 1, normal = 0, refactored = 0;
	u8 result;
	i32 number = NULL;

	//process argues
	if (argc == 1) {
		all = 1;
		both = 1;
	} else if (argc >= 2) {
		if (!strcmp(argv[1], "table")) {
			table = 1;
			all = 0;
		} else if (!strcmp(argv[1], "list")) {
			list = 1;
			all = 0;
		} else if (!strcmp(argv[1], "tree")) {
			tree = 1;
			all = 0;
		} else if (!strcmp(argv[1], "normal")) {
			normal = 1;
			both = 0;
		} else if (!strcmp(argv[1], "refactored")) {
			refactored = 1;
			both = 0;
		}

		if (argv[2]) {
			if (!strcmp(argv[2], "normal")) {
				normal = 1;
				both = 0;
			} else if (!strcmp(argv[2], "refactored")) {
				refactored = 1;
				both = 0;
			} else if (!strcmp(argv[2], "table")) {
				table = 1;
				all = 0;
			} else if (!strcmp(argv[2], "list")) {
				list = 1;
				all = 0;
			} else if (!strcmp(argv[2], "tree")) {
				tree = 1;
				all = 0;
			}
		}
	}

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

	if (all || table) {
		fprintf(stdout, "\n*** TABLE ALGORITHMS ***\n");
		if (both || normal) {
			result = run_normal_table_algorithms(number);
			if (result)
				return result;
		}
		if (both || refactored) {
			result = run_refactored_table_algorithms(number);
			if (result)
				return result;
		}
    	}

	if (all || list) {
		fprintf(stdout, "\n*** LIST ALGORITHMS ***\n");
		if (both || normal) {
		result = run_normal_list_algorithms(number);
		if (result)
			return result;
		}
		if (both || refactored) {
			result = run_refactored_list_algorithms(number);
			if (result)
				return result;
		}
    	}

	if (all || tree) {
		fprintf(stdout, "\n*** TREE ALGORITHMS ***\n");
		if (both || normal) {
			result = run_normal_tree_algorithms(number);
			if (result)
				return result;
		}
		if (both || refactored) {
			result = run_refactored_tree_algorithms(number);
			if (result)
				return result;
		}
    	}

	//finish program
	fprintf(stdout, "\nEvery algorithm done its work. It's time to say goodbye.\n"
		"Sławomir Jankowski 2020-2021");

	return SUCCESS;
}

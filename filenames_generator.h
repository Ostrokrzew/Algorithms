/*
 * Modify this file if You want to change input and output files' names.
 */

#ifndef ENGINEERPROJECT_FILENAMES_GENERATOR_H
#define ENGINEERPROJECT_FILENAMES_GENERATOR_H

#include <sys/stat.h>

//generate timestamp
static const std::string timestamp = std::to_string(std::time(NULL));

static void make_dir(const std::string &name) {
	struct stat st = {0};

	if (stat(name.c_str(), &st) == -1) {
		int result = mkdir(name.c_str(), (S_IREAD | S_IWRITE));
		if (result)
			fprintf(stderr, "Cannot create directory named %s", name.c_str());
	}
}

static std::string name_generator(const std::string &name) {
	make_dir(timestamp);
	return (timestamp + "/" + name + ".txt");
}

//output files' names
const static std::string GENERATED_DATA_FILE = name_generator("data-to-sort");
const static std::string BUBBLESORT_FILE = name_generator("bubblesort");
const static std::string QUICKSORT_FILE = name_generator("quicksort");
const static std::string MERGESORT_FILE = name_generator("mergesort");
const static std::string INSERTIONSORT_FILE = name_generator("insertionsort");
const static std::string HEAPSORT_FILE = name_generator("heapsort");
const static std::string SELECTIONSORT_FILE = name_generator("selectionsort");
const static std::string SHELLSSORT_FILE = name_generator("shellssort");
const static std::string CIURASSORT_FILE = name_generator("ciurassort");
const static std::string LINEARSEARCH_FILE = name_generator("linearsearch");
const static std::string GUARDIANSEARCH_FILE = name_generator("guardiansearch");
const static std::string BINARYSEARCH_FILE = name_generator("binarysearch");
const static std::string MAXMINSEARCH_FILE = name_generator("maxminsearch");
const static std::string REF_BUBBLESORT_FILE = name_generator("bubblesort-refactored");
const static std::string REF_QUICKSORT_FILE = name_generator("quicksort-refactored");
const static std::string REF_MERGESORT_FILE = name_generator("mergesort-refactored");
const static std::string REF_INSERTIONSORT_FILE = name_generator("insertionsort-refactored");
const static std::string REF_HEAPSORT_FILE = name_generator("heapsort-refactored");
const static std::string REF_SELECTIONSORT_FILE = name_generator("selectionsort-refactored");
const static std::string REF_SHELLSSORT_FILE = name_generator("shellssort-refactored");
const static std::string REF_CIURASSORT_FILE = name_generator("ciurassort-refactored");
const static std::string REF_LINEARSEARCH_FILE = name_generator("linearsearch-refactored");
const static std::string REF_GUARDIANSEARCH_FILE = name_generator("guardiansearch-refactored");
const static std::string REF_BINARYSEARCH_FILE = name_generator("binarysearch-refactored");
const static std::string REF_MAXMINSEARCH_FILE = name_generator("maxminsearch-refactored");

#endif //ENGINEERPROJECT_FILENAMES_GENERATOR_H

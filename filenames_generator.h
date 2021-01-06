/*
 * Modify this file if You want to change input and output files' names.
 */

#ifndef ENGINEERPROJECT_FILENAMES_GENERATOR_H
#define ENGINEERPROJECT_FILENAMES_GENERATOR_H

#include <sys/stat.h>
#include <unistd.h>

//generate timestamp
static const std::string timestamp = std::to_string(std::time(nullptr));

static void make_dir(const std::string &name) {
	struct stat st = {0};
	char cwd[PATH_MAX];
	std::string full_name = name;

	if (getcwd(cwd, sizeof(cwd)) != nullptr)
		sprintf(const_cast<char*>(full_name.c_str()), "%s/%s", cwd, timestamp.c_str());

	if (stat(full_name.c_str(), &st) == -1) {
		mkdir(full_name.c_str(), (S_IRWXU | S_IRWXG | S_IRWXO)) ?
		fprintf(stderr, "Cannot create directory named %s\n", full_name.c_str()) :
		fprintf(stdout, "Created directory named %s\n", full_name.c_str());
	}
}

static std::string name_generator(const std::string &name) {
	make_dir(timestamp);
	return (timestamp + "/" + name + ".txt");
}

//output files' names
const static std::string GENERATED_DATA_FILE = name_generator("data-to-sort");
const static std::string BUBBLESORT_FILE = name_generator("sort-bubble");
const static std::string QUICKSORT_FILE = name_generator("sort-quick");
const static std::string MERGESORT_FILE = name_generator("sort-merge");
const static std::string INSERTIONSORT_FILE = name_generator("sort-insertion");
const static std::string HEAPSORT_FILE = name_generator("sort-heap");
const static std::string SELECTIONSORT_FILE = name_generator("sort-selection");
const static std::string SHELLSSORT_FILE = name_generator("sort-shell");
const static std::string CIURASSORT_FILE = name_generator("sort-ciura");
const static std::string LINEARSEARCH_FILE = name_generator("search-linear");
const static std::string GUARDIANSEARCH_FILE = name_generator("search-guardian");
const static std::string BINARYSEARCH_FILE = name_generator("search-binary");
const static std::string MAXMINSEARCH_FILE = name_generator("search-maxmin");
const static std::string REF_BUBBLESORT_FILE = name_generator("refactored-sort-bubble");
const static std::string REF_QUICKSORT_FILE = name_generator("refactored-sort-quick");
const static std::string REF_MERGESORT_FILE = name_generator("refactored-sort-merge");
const static std::string REF_INSERTIONSORT_FILE = name_generator("refactored-sort-insertion");
const static std::string REF_HEAPSORT_FILE = name_generator("refactored-sort-heap");
const static std::string REF_SELECTIONSORT_FILE = name_generator("refactored-sort-selection");
const static std::string REF_SHELLSSORT_FILE = name_generator("refactored-sort-shell");
const static std::string REF_CIURASSORT_FILE = name_generator("refactored-sort-ciura");
const static std::string REF_LINEARSEARCH_FILE = name_generator("refactored-search-linear");
const static std::string REF_GUARDIANSEARCH_FILE = name_generator("refactored-search-guardian");
const static std::string REF_BINARYSEARCH_FILE = name_generator("refactored-search-binary");
const static std::string REF_MAXMINSEARCH_FILE = name_generator("refactored-search-maxmin");

#endif //ENGINEERPROJECT_FILENAMES_GENERATOR_H

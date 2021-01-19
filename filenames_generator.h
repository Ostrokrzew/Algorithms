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
const static std::string TABLE_SORT_BUBBLE = name_generator("table-sort-bubble");
const static std::string TABLE_SORT_QUICK = name_generator("table-sort-quick");
const static std::string TABLE_SORT_MERGE = name_generator("table-sort-merge");
const static std::string TABLE_SORT_INSERTION = name_generator("table-sort-insertion");
const static std::string TABLE_SORT_HEAP = name_generator("table-sort-heap");
const static std::string TABLE_SORT_SELECTION = name_generator("table-sort-selection");
const static std::string TABLE_SORT_SHELL = name_generator("table-sort-shell");
const static std::string TABLE_SORT_CIURA = name_generator("table-sort-ciura");
const static std::string TABLE_SEARCH_LINEAR = name_generator("table-search-linear");
const static std::string TABLE_SEARCH_GUARDIAN = name_generator("table-search-guardian");
const static std::string TABLE_SEARCH_BINARY = name_generator("table-search-binary");
const static std::string TABLE_SEARCH_EXTREMA = name_generator("table-search-extrema");
const static std::string TABLE_SORT_BUBBLE_REF = name_generator("table-sort-bubble-refactored");
const static std::string TABLE_SORT_QUICK_REF = name_generator("table-sort-quick-refactored");
const static std::string TABLE_SORT_MERGE_REF = name_generator("table-sort-merge-refactored");
const static std::string TABLE_SORT_INSERTION_REF = name_generator("table-sort-insertion-refactored");
const static std::string TABLE_SORT_HEAP_REF = name_generator("table-sort-heap-refactored");
const static std::string TABLE_SORT_SELECTION_REF = name_generator("table-sort-selection-refactored");
const static std::string TABLE_SORT_SHELL_REF = name_generator("table-sort-shell-refactored");
const static std::string TABLE_SORT_CIURA_REF = name_generator("table-sort-ciura-refactored");
const static std::string TABLE_SEARCH_LINEAR_REF = name_generator("table-search-linear-refactored");
const static std::string TABLE_SEARCH_GUARDIAN_REF = name_generator("table-search-guardian-refactored");
const static std::string TABLE_SEARCH_BINARY_REF = name_generator("table-search-binary-refactored");
const static std::string TABLE_SEARCH_EXTREMA_REF = name_generator("table-search-extrema-refactored");
const static std::string LIST_SORT_BUBBLE = name_generator("list-sort-bubble");
const static std::string LIST_SORT_QUICK = name_generator("list-sort-quick");
const static std::string LIST_SORT_MERGE = name_generator("list-sort-merge");
const static std::string LIST_SORT_INSERTION = name_generator("list-sort-insertion");
const static std::string LIST_SORT_SELECTION = name_generator("list-sort-selection");
const static std::string LIST_SORT_SHELL = name_generator("list-sort-shell");
const static std::string LIST_SORT_CIURA = name_generator("list-sort-ciura");
const static std::string LIST_SEARCH_LINEAR = name_generator("list-search-linear");
const static std::string LIST_SEARCH_GUARDIAN = name_generator("list-search-guardian");
const static std::string LIST_SEARCH_BINARY = name_generator("list-search-binary");
const static std::string LIST_SEARCH_EXTREMA = name_generator("list-search-extrema");
const static std::string LIST_SORT_BUBBLE_REF = name_generator("list-sort-bubble-refactored");
const static std::string LIST_SORT_QUICK_REF = name_generator("list-sort-quick-refactored");
const static std::string LIST_SORT_MERGE_REF = name_generator("list-sort-merge-refactored");
const static std::string LIST_SORT_INSERTION_REF = name_generator("list-sort-insertion-refactored");
const static std::string LIST_SORT_SELECTION_REF = name_generator("list-sort-selection-refactored");
const static std::string LIST_SORT_SHELL_REF = name_generator("list-sort-shell-refactored");
const static std::string LIST_SORT_CIURA_REF = name_generator("list-sort-ciura-refactored");
const static std::string LIST_SEARCH_LINEAR_REF = name_generator("list-search-linear-refactored");
const static std::string LIST_SEARCH_GUARDIAN_REF = name_generator("list-search-guardian-refactored");
const static std::string LIST_SEARCH_BINARY_REF = name_generator("list-search-binary-refactored");
const static std::string LIST_SEARCH_EXTREMA_REF = name_generator("list-search-extrema-refactored");
const static std::string TREE_SORT_BUBBLE = name_generator("tree-sort-bubble");
const static std::string TREE_SORT_QUICK = name_generator("tree-sort-quick");
const static std::string TREE_SORT_MERGE = name_generator("tree-sort-merge");
const static std::string TREE_SORT_INSERTION = name_generator("tree-sort-insertion");
const static std::string TREE_SORT_HEAP = name_generator("tree-sort-heap");
const static std::string TREE_SORT_SELECTION = name_generator("tree-sort-selection");
const static std::string TREE_SORT_SHELL = name_generator("tree-sort-shell");
const static std::string TREE_SORT_CIURA = name_generator("tree-sort-ciura");
const static std::string TREE_SEARCH_LINEAR = name_generator("tree-search-linear");
const static std::string TREE_SEARCH_GUARDIAN = name_generator("tree-search-guardian");
const static std::string TREE_SEARCH_BINARY = name_generator("tree-search-binary");
const static std::string TREE_SEARCH_EXTREMA = name_generator("tree-search-extrema");
const static std::string TREE_SORT_BUBBLE_REF = name_generator("tree-sort-bubble-refactored");
const static std::string TREE_SORT_QUICK_REF = name_generator("tree-sort-quick-refactored");
const static std::string TREE_SORT_MERGE_REF = name_generator("tree-sort-merge-refactored");
const static std::string TREE_SORT_INSERTION_REF = name_generator("tree-sort-insertion-refactored");
const static std::string TREE_SORT_HEAP_REF = name_generator("tree-sort-heap-refactored");
const static std::string TREE_SORT_SELECTION_REF = name_generator("tree-sort-selection-refactored");
const static std::string TREE_SORT_SHELL_REF = name_generator("tree-sort-shell-refactored");
const static std::string TREE_SORT_CIURA_REF = name_generator("tree-sort-ciura-refactored");
const static std::string TREE_SEARCH_LINEAR_REF = name_generator("tree-search-linear-refactored");
const static std::string TREE_SEARCH_GUARDIAN_REF = name_generator("tree-search-guardian-refactored");
const static std::string TREE_SEARCH_BINARY_REF = name_generator("tree-search-binary-refactored");
const static std::string TREE_SEARCH_EXTREMA_REF = name_generator("tree-search-extrema-refactored");
#endif //ENGINEERPROJECT_FILENAMES_GENERATOR_H

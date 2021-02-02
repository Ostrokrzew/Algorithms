#include "tree_algorithms_refactored.h"

std::chrono::duration<double> tree_search_depth_rfctrd(binary_node_t const &root, const i32 searched_number,
						       bool &result) {
	//start counting time
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

	//start searching
	tree_search_dpth_rfctrd(root, searched_number, result);

	//stop counting time
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	//print searching duration time
	std::chrono::duration<double> diff = end-start;

	// check if number is found
	if (result) {
		fprintf(stdout, "Time to find %ld in binary tree with refactored depth-first search "
		  	"algorithm: %.7f s\n", searched_number, diff.count());
	} else {
		fprintf(stderr, "Depth-first search didn't found %ld in tree.\n", searched_number);
	}

	//return duration time
	return diff;
}

inline void tree_search_dpth_rfctrd(binary_node_t const &root, const i32 searched_number, bool &result) {
	if (result == true)
		return;
	if (root != nullptr) {
		tree_search_dpth_rfctrd(root->left, searched_number, result);
		tree_search_dpth_rfctrd(root->right, searched_number, result);
		if (root->value == searched_number) {
			result = true;
		}
	}
}

std::chrono::duration<double> tree_search_breadth_rfctrd(binary_node_t const &root, const i32 searched_number,
							 bool &result) {
	//start counting time
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

	//start searching
	tree_search_brdth_rfctrd(root, searched_number, result);

	//stop counting time
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	//print searching duration time
	std::chrono::duration<double> diff = end-start;

	// check if number is found
	if (result) {
		fprintf(stdout, "Time to find %ld in binary tree with refactored breadth-first search "
		  	"algorithm: %.7f s\n", searched_number, diff.count());
	} else {
		fprintf(stderr, "Breadth-first search didn't found %ld in tree.\n", searched_number);
	}

	//return duration time
	return diff;
}

inline void tree_search_brdth_rfctrd(binary_node_t const &root, const i32 searched_number, bool &result) {
	u32 height = get_height(root);
	for (int i = 0; i < height; i++) {
		tree_search_traverse_rfctrd(root, i, searched_number, result);
		if (result)
			return;
	}
}

inline void tree_search_traverse_rfctrd(binary_node_t const &root, const u32 level, const i32 searched_number,
					bool &result) {
	if (result == true)
		return;
	if (root != nullptr)
	{
		if (level == 1) {
			if (root->value == searched_number) {
				result = true;
			}
		} else if (level > 1) {
			tree_search_traverse_rfctrd(root->left, level - 1, searched_number, result);
			tree_search_traverse_rfctrd(root->right, level - 1, searched_number, result);
		}
	}
}

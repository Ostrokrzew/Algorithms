#include "tree_algorithms.h"

std::chrono::duration<double> tree_search_depth(binary_node_t &root, long searched_number, bool &result) {
	//start counting time
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

	//start searching
	tree_search_dpth(root, searched_number, result);

	//stop counting time
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	//print searching duration time
	std::chrono::duration<double> diff = end-start;

	// check if number is found
	if (result) {
		fprintf(stdout, "Time to find %ld in binary tree with depth-first search algorithm: %.7f s\n",
			searched_number, diff.count());
	} else {
		fprintf(stderr, "Depth-first search didn't found %ld in tree.\n", searched_number);
	}

	//return duration time
	return diff;
}

void tree_search_dpth(binary_node_t root, long searched_number, bool &result) {
	if (root == nullptr)
		return;
	long current_value = root->value;
	tree_search_dpth(root->left, searched_number, result);
	tree_search_dpth(root->right, searched_number, result);
	if (current_value == searched_number)
		result = true;
}

std::chrono::duration<double> tree_search_breadth(binary_node_t &root, long searched_number, bool &result) {
	//start counting time
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

	//start searching
	tree_search_brdth(root, searched_number, result);

	//stop counting time
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	//print searching duration time
	std::chrono::duration<double> diff = end-start;

	// check if number is found
	if (result) {
		fprintf(stdout, "Time to find %ld in binary tree with breadth-first search algorithm: %.7f s\n",
			searched_number, diff.count());
	} else {
		fprintf(stderr, "Breadth-first search didn't found %ld in tree.\n", searched_number);
	}

	//return duration time
	return diff;
}

void tree_search_brdth(binary_node_t root, long searched_number, bool &result) {
	int height = get_height(root);
	for (int i = 0; i < height; i++) {
		tree_search_traverse(root, i, searched_number, result);
	}
}

void tree_search_traverse(binary_node_t root, int level, long searched_number, bool &result) {
	if (root == nullptr)
		return;
	if (level == 1) {
		long current_value = root->value;
		if (current_value == searched_number)
			result = true;
	} else if (level > 1) {
		if (root->left != nullptr)
			tree_search_traverse(root->left, level - 1, searched_number, result);
		if (root->right != nullptr)
			tree_search_traverse(root->right, level - 1, searched_number, result);
	}

}

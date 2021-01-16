#include "list_algorithms_refactored.h"

std::chrono::duration<double> list_sort_bubble_rfctrd(list_node_t first_node) {
	//start counting time
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

	//start sorting
	list_sort_bbl_rfctrd(first_node);

	//stop counting time
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	//print sorting duration time
	std::chrono::duration<double> diff = end-start;
	fprintf(stdout, "Time to sort list with refactored heap sort algorithm: %f s\n", diff);

	//return duration time
	return diff;
}

void list_sort_bbl_rfctrd(list_node_t first_node) {
	bool change;
	size_t i, j;
	list_node_t left_node = first_node, right_node = left_node->next;
	for (i = 0; i < (AMOUNT - 1); i++) {	// -1 because the right node is the next node
		change = false;
		for (j = 1; j < (AMOUNT - 1 - i); j++) {
			if (left_node->value > right_node->value) {
				swap_xor_list(left_node, right_node);
				change = true;
			}
		}
		if (!change)
			break;
		left_node = left_node->next;
		right_node = left_node->next;
	}
}

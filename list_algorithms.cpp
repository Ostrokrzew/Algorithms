#include "list_algorithms.h"

std::chrono::duration<double> list_sort_bubble_prerefactored(list_node_t first_node) {
    //start counting time
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

    //start sorting
    list_sort_bbl_prerefactored(first_node);

    //stop counting time
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    //print sorting duration time
    std::chrono::duration<double> diff = end-start;
    fprintf(stdout, "Time to sort by bubblesort algorithm: "
                    "%f s\n", diff);

    //return duration time
    return diff;
}

void list_sort_bbl_prerefactored(list_node_t first_node) {
	list_node current_node = *first_node;
	int counter = 1;
	while (current_node.next != nullptr) {
		counter += 1;
		current_node = current_node.next;
	}

	list_node left_node = *first_node;
	for (int i = 0; i < (counter - 1); i++) {
		list_node right_node = *first_node;
		int index = i + 1;
		for (int j = 0; j < index; j++)
			right_node = right_node.next;
		if (left_node.value > right_node.value)
			swap_tmp_list(*first_node, left_node, right_node);
		left_node = left_node.next;
	}

}

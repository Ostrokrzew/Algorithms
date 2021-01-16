#include "list_algorithms.h"

std::chrono::duration<double> list_sort_bubble(list_node_t first_node) {
	//start counting time
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

	//start sorting
	list_sort_bbl(*first_node);

	//stop counting time
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	//print sorting duration time
	std::chrono::duration<double> diff = end-start;
	fprintf(stdout, "Time to sort list with bubble sort algorithm: %f s\n", diff.count());

	//return duration time
	return diff;
}

void list_sort_bbl(list_node first_node) {
	int list_len = get_list_lenght(first_node);

	for (int i = 0; i < list_len; i++) {
		// set left node at position
		list_node left_node = first_node;
		int left_index = i;
		for (int idx_lt = 0; idx_lt < left_index; idx_lt++)
			left_node = *left_node.next;
		// set right node at position
		list_node right_node = first_node;
		int right_index = i + 1;
		for (int idx_rt = 0; idx_rt < right_index; idx_rt++)
			right_node = *left_node.next;

		for (int j = 1; j < list_len; j++) {
			if (left_node.value > right_node.value)
				swap_tmp_list(first_node, left_node, right_node);
		}
	}
}

std::chrono::duration<double> list_sort_heap(list_node_t first_node) {
	//start counting time
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

	//start sorting
	list_sort_hp(*first_node);

	//stop counting time
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	//print sorting duration time
	std::chrono::duration<double> diff = end-start;
	fprintf(stdout, "Time to sort list with heap sort algorithm: %f s\n", diff.count());

	//return duration time
	return diff;
}

//void list_sort_hp(list_node first_node) {
//	int list_len = get_list_lenght(first_node);
//
//	for (int j = list_len / 2; j > 0; --j) {
//		list_restore(table, j, length);
//	}
//	do {
//		swap_tmp_list(first_node, table[length - 1], table[0]);
//		length -= 1;
//		list_restore(table, 1, length);
//	} while (length > 1);
//}
//
//void list_restore(list_node first_node, int j, int length) {
//	long tmp = table[j-1];
//	while (j <= (length / 2)) {
//		int k = j * 2;
//		if ((k < length) && (table[k-1] < table[k]))
//			k += 1;
//		if (tmp >= table[k-1])
//			break;
//		table[j-1] = table[k-1];
//		j = k;
//	}
//	table[j-1] = tmp;
//}
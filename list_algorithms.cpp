#include "list_algorithms.h"

std::chrono::duration<double> list_sort_bubble(list_node_t &first_node) {
	//start counting time
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

	//start sorting
	list_sort_bbl(first_node);

	//stop counting time
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	//print sorting duration time
	std::chrono::duration<double> diff = end-start;
	fprintf(stdout, "Time to sort list with bubble sort algorithm: %f s\n", diff.count());

	//return duration time
	return diff;
}

void list_sort_bbl(list_node_t &first_node) {
	int list_len = get_list_lenght(first_node);

	for (int i = 0; i < list_len; i++) {
		list_node_t left_node = first_node;
		list_node_t right_node = left_node->next;

		for (int j = 0; j < list_len-1; j++) {
			if (left_node->value > right_node->value)
				swap_tmp_list(left_node, right_node);
			left_node = left_node->next;
			right_node = right_node->next;
			if (right_node == nullptr)
				break;
		}
	}
}

///*** HEAP SORT ***/
//std::chrono::duration<double> list_sort_heap(list_node_t &first_node) {
//	//start counting time
//	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
//
//	//start sorting
//	list_sort_hp(first_node);
//
//	//stop counting time
//	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
//
//	//print sorting duration time
//	std::chrono::duration<double> diff = end-start;
//	fprintf(stdout, "Time to sort list with heap sort algorithm: %f s\n", diff.count());
//
//	//return duration time
//	return diff;
//}
//
//void list_sort_hp(list_node_t &first_node) {
//	for (int j = length / 2; j > 0; --j) {
//		list_restore(first_node, j, length);
//	}
//	do {
//		swap_tmp_list(first_node[length - 1], first_node[0]);
//		length -= 1;
//		list_restore(first_node, 1, length);
//	} while (length > 1);
//}
//
//void list_restore(list_node_t &first_node, int j, int length) {
//	long tmp = first_node[j-1];
//	while (j <= (length / 2)) {
//		int k = j * 2;
//		if ((k < length) && (first_node[k-1] < first_node[k]))
//			k += 1;
//		if (tmp >= first_node[k-1])
//			break;
//		first_node[j-1] = first_node[k-1];
//		j = k;
//	}
//	first_node[j-1] = tmp;
//}
//
///*** INSERTION SORT ***/
//std::chrono::duration<double> list_sort_insertion(list_node_t &first_node) {
//	//start counting time
//	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
//
//	//start sorting
//	list_sort_insrt(first_node);
//
//	//stop counting time
//	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
//
//	//print sorting duration time
//	std::chrono::duration<double> diff = end-start;
//	fprintf(stdout, "Time to sort list with insertion sort algorithm: %f s\n", diff.count());
//
//	//return duration time
//	return diff;
//}
//
//void list_sort_insrt(list_node_t &first_node) {
//	for (int i = 1; i < length; i++) {
//		long tmp_i = first_node[i];
//		int j;
//		for (j = (i - 1); j >= 0; j--) {
//			long tmp_j = first_node[j];
//			if (tmp_j <= tmp_i)
//				break;
//			first_node[j+1] = tmp_j;
//		}
//		first_node[j+1] = tmp_i;
//	}
//}
//
///*** MERGE SORT ***/
//std::chrono::duration<double> list_sort_merge(list_node_t &first_node) {
//	//start counting time
//	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
//
//	//start sorting
//	list_sort_mrg(first_node, 0, AMOUNT - 1);
//
//	//stop counting time
//	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
//
//	//print sorting duration time
//	std::chrono::duration<double> diff = end-start;
//	fprintf(stdout, "Time to sort list with merge sort algorithm: %f s\n", diff.count());
//
//	//return duration time
//	return diff;
//}
//
//void list_sort_mrg(list_node_t &first_node, int left, int right) {
//	if (left < right) {
//		int middle = (left + right) / 2;
//		list_sort_mrg(first_node, left, middle);
//		list_sort_mrg(first_node, middle + 1, right);
//		list_merge(first_node, left, middle, right);
//	}
//}
//
//void list_merge(list_node_t &first_node, int left, int middle, int right) {
//	//copy list content to temporary first_node
//	auto *tmp_list = (int*)zmalloc(sizeof(int) * AMOUNT);
//	for (int i = 0; i < AMOUNT; i++)
//		tmp_list[i] = first_node[i];
//
//	//create auxiliary variables
//	int left1 = left, left2 = middle + 1, i = left;
//	while ((left1 <= middle) && (left2 <= right)) {
//		if (first_node[left1] < first_node[left2]) {
//			tmp_list[i] = first_node[left1];
//			i += 1;
//			left1 += 1;
//		}
//		else {
//			tmp_list[i] = first_node[left2];
//			i += 1;
//			left2 += 1;
//		}
//	}
//
//	while (left1 <= middle) {
//		tmp_list[i] = first_node[left1];
//		i += 1;
//		left1 += 1;
//	}
//
//	//copy sorted temporary list content to first_node
//	for (int j = 0; j < AMOUNT; j++)
//		first_node[j] = tmp_list[j];
//	free(tmp_list);
//}
//
///*** QUICK SORT ***/
//std::chrono::duration<double> list_sort_quick(list_node_t &first_node) {
//	//start counting time
//	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
//
//	//start sorting
//	list_sort_qck(first_node, 0, AMOUNT - 1);
//
//	//stop counting time
//	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
//
//	//print sorting duration time
//	std::chrono::duration<double> diff = end-start;
//	fprintf(stdout, "Time to sort list with quick sort algorithm: %f s\n", diff.count());
//
//	//return duration time
//	return diff;
//}
//
//void list_sort_qck(list_node_t &first_node, int left, int right) {
//	if (left < right) {
//		int splitter = left;
//		for (int i = left + 1; i <= right; i++) {
//			if (first_node[i] < first_node[left]) {
//				splitter += 1;
//				swap_tmp_list(first_node[splitter], first_node[i]);
//			}
//		}
//		long tmp = first_node[splitter];
//		first_node[splitter] = first_node[left];
//		first_node[left] = tmp;
//		list_sort_qck(first_node, left, splitter);
//		list_sort_qck(first_node, splitter + 1, right);
//	}
//}
//
///*** SELECTION SORT ***/
//std::chrono::duration<double> list_sort_selection(list_node_t &first_node) {
//	//start counting time
//	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
//
//	//start sorting
//	list_sort_slct(first_node);
//
//	//stop counting time
//	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
//
//	//print sorting duration time
//	std::chrono::duration<double> diff = end-start;
//	fprintf(stdout, "Time to sort list with selection sort algorithm: %f s\n", diff.count());
//
//	//return duration time
//	return diff;
//}
//
//void list_sort_slct(list_node_t &first_node) {
//	for (int i = 0; i < (length - 1); ++i) {
//		int min_val_index = i;
//		for (int j = i + 1; j < length; ++j) {
//			if (first_node[j] < first_node[min_val_index])
//				min_val_index = j;
//		}
//		swap_tmp_list(first_node[i], first_node[min_val_index]);
//	}
//}
//
///*** SHELL'S SORT ***/
//std::chrono::duration<double> list_sort_shell(list_node_t &first_node) {
//	//start counting time
//	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
//
//	//start sorting
//	list_sort_shl(first_node);
//
//	//stop counting time
//	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
//
//	//print sorting duration time
//	std::chrono::duration<double> diff = end-start;
//	fprintf(stdout, "Time to sort list with original Shell's algorithm: %f s\n", diff.count());
//
//	//return duration time
//	return diff;
//}
//
//void list_sort_shl(list_node_t &first_node) {
//	int step = length / 2;
//	while (step >= 1) {
//		for (int i = step; i < length; i++) {
//			long tmp_val;
//			int j;
//			tmp_val = first_node[i];
//			for (j = i; j >= step && first_node[j - step] > tmp_val; j -= step)
//				first_node[j] = first_node[j - step];
//			first_node[j] = tmp_val;
//		}
//		step /= 2;
//	}
//}
//
//std::chrono::duration<double> list_sort_ciura(list_node_t &first_node) {
//	//start counting time
//	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
//
//	//start sorting
//	list_sort_cr(first_node);
//
//	//stop counting time
//	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
//
//	//print sorting duration time
//	std::chrono::duration<double> diff = end-start;
//	fprintf(stdout, "Time to sort list with Ciura's version of Shell's algorithm: %f s\n", diff.count());
//
//	//return duration time
//	return diff;
//}
//
//void list_sort_cr(list_node_t &first_node) {
//	const int size = 8;
//	int steps[size] = {701, 301, 132, 57, 23, 10, 4, 1};
//	for (int i = 0; i < size; i++) {
//		int step = steps[i];
//		for (int j = step; j < length; j++) {
//			long tmp_val;
//			int k;
//			tmp_val = first_node[j];
//			for (k = j; k >= step && first_node[k-step] > tmp_val; k -= step)
//				first_node[k] = first_node[k-step];
//			first_node[k] = tmp_val;
//		}
//	}
//}
//
///*** LINEAR SEARCH ***/
//std::chrono::duration<double> list_search_linear(list_node_t &first_node, long searched_number, bool &result) {
//	//start counting time
//	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
//
//	//start searching
//	result = list_search_lnr(first_node, searched_number);
//
//	//stop counting time
//	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
//
//	//print searching duration time
//	std::chrono::duration<double> diff = end-start;
//
//	// check if number is found
//	if (result) {
//		fprintf(stdout, "Time to find %ld in list with linear search algorithm: %f s\n",
//			searched_number, diff.count());
//	} else {
//		fprintf(stderr, "Linear search didn't found %ld in list.\n", searched_number);
//	}
//
//	//return duration time
//	return diff;
//}
//
//bool list_search_lnr(list_node_t &first_node, long searched_item) {
//	for (int i = 0; i < length; i++) {
//		long current_item = first_node[i];
//		if (current_item == searched_item) {
//			return true;
//		}
//	}
//	return false;
//}
//
//std::chrono::duration<double> list_search_guardian(list_node_t &first_node, long searched_number, bool &result) {
//	//start counting time
//	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
//
//	//start searching
//	result = list_search_grd(first_node, searched_number);
//
//	//stop counting time
//	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
//
//	//print searching duration time
//	std::chrono::duration<double> diff = end-start;
//
//	// check if number is found
//	if (result) {
//		fprintf(stdout, "Time to find %ld in list with linear search with guardian algorithm: %f s\n",
//			searched_number, diff.count());
//	} else {
//		fprintf(stderr, "Linear search with guardian didn't found %ld in list.\n", searched_number);
//	}
//
//	//return duration time
//	return diff;
//}
//
//bool list_search_grd(list_node_t &first_node, long searched_item) {
//	int index = 0;
//	long tmp_list[length+1];
//	for (int i = 0; i <= length; i++)
//		tmp_list[i] = first_node[i];
//	tmp_list[length] = searched_item;  //set guardian
//
//	while (true) {
//		long current_item = tmp_list[index];
//		if (current_item == searched_item) {
//			break;
//		}
//		index += 1;
//	}
//	if (index < length)
//		return true;
//	else
//		return false;
//}
//
///*** BINARY SEARCH ***/
//std::chrono::duration<double> list_search_binary(list_node_t &first_node, long searched_number, bool &result) {
//	//start counting time
//	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
//
//	//start searching
//	result = list_search_bnr(first_node, 0, AMOUNT - 1, searched_number);
//
//	//stop counting time
//	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
//
//	//print searching duration time
//	std::chrono::duration<double> diff = end-start;
//
//	// check if number is found
//	if (result) {
//		fprintf(stdout, "Time to find %ld in list with binary search algorithm: %f s\n",
//			searched_number, diff.count());
//	} else {
//		fprintf(stderr, "Binary search didn't found %ld in list.\n", searched_number);
//	}
//
//	//return duration time
//	return diff;
//}
//
//bool list_search_bnr(list_node_t &first_node, int left, int right, long searched_item) {
//	if (left > right)
//		return false;
//
//	int middle = (left + right) / 2;
//	long current_item = first_node[middle];
//	if (current_item == searched_item)
//		return true;
//
//	if (searched_item < current_item) {
//		list_search_bnr(first_node, left, middle - 1, searched_item);
//	} else {
//		list_search_bnr(first_node, middle + 1, right, searched_item);
//	}
//}
//
///*** MAXIMUM/ MINIMUM SEARCH ***/
//std::chrono::duration<double> list_search_extrema(list_node_t &first_node, long searched_number, bool &result) {
//	//start counting time
//	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
//
//	//start searching
//	long maximum = list_search_max(first_node);
//	long minimum = list_search_min(first_node);
//
//	if (minimum <= maximum)
//		result = true;
//
//	//stop counting time
//	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
//
//	//print searching duration time
//	std::chrono::duration<double> diff = end-start;
//
//	// check if number is found
//	if (result) {
//		fprintf(stdout, "Time to find minimum: %ld and maximum: %ld in list "
//				"with extrema search algorithm: %f s\n", minimum, maximum, diff.count());
//	} else {
//		fprintf(stderr, "Extrema search didn't found minimum: %ld or maximum: %ld in list.\n",
//			minimum, maximum);
//	}
//
//	//return duration time
//	return diff;
//}
//
//long list_search_max(list_node_t &first_node) {
//	long maximum = LONG_MIN;
//	for (int i = 0; i < length; i++) {
//		if (first_node[i] > maximum)
//			maximum = first_node[i];
//	}
//	return maximum;
//}
//
//long list_search_min(list_node_t &first_node) {
//	long minimum = LONG_MAX;
//	for (int i = 0; i < length; i++) {
//		if (first_node[i] < minimum)
//			minimum = first_node[i];
//	}
//	return minimum;
//}
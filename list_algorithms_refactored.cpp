#include "list_algorithms_refactored.h"

std::chrono::duration<double> list_sort_bubble_rfctrd(list_node_t first_node) {
	//start counting time
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

	//start sorting
	list_sort_bbl_rfctrd(first_node, AMOUNT);

	//stop counting time
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	//print sorting duration time
	std::chrono::duration<double> diff = end-start;
	fprintf(stdout, "Time to sort list with refactored heap sort algorithm: %f s\n", diff.count());

	//return duration time
	return diff;
}

void list_sort_bbl_rfctrd(list_node_t first_node, size_t lenght) {
	bool change;
	size_t i, j;
	list_node_t left_node = first_node, right_node = left_node->next;
	for (i = 0; i < (lenght - 1); i++) {	// -1 because the right node is the next node
		change = false;
		for (j = 1; j < (lenght - 1 - i); j++) {
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

/*** HEAP SORT ***/
std::chrono::duration<double> list_sort_heap_rfctrd(list_node_t first_node) {
	//start counting time
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

	//start sorting
	list_sort_hp_rfctrd(first_node, AMOUNT);

	//stop counting time
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	//print sorting duration time
	std::chrono::duration<double> diff = end-start;
	fprintf(stdout, "Time to sort list with refactored heap sort algorithm: %f s\n", diff.count());

	//return duration time
	return diff;
}

inline void list_sort_hp_rfctrd(list_node_t first_node, size_t length) {
	size_t j;
	for (j = (length >> 1); j > 0; --j) {
		list_restore_rfctrd(first_node, j, length);
	}
	do {
		swap_xor_list(first_node[length - 1], first_node[0]);
		--length;
		list_restore_rfctrd(first_node, 1, length);
	} while (length > 1);
}

inline void list_restore_rfctrd(list_node_t first_node, size_t j, size_t length) {
	int32_t tmp = first_node[j-1];
	size_t k;

	while (j <= (length >> 1)) {
		k = j << 1;
		if ((k < length) && (first_node[k-1] < first_node[k]))
			++k;
		if (tmp >= first_node[k-1])
			break;
		first_node[j-1] = first_node[k-1];
		j = k;
	}
	first_node[j-1] = tmp;
}

/*** INSERTION SORT ***/
std::chrono::duration<double> list_sort_insertion_rfctrd(list_node_t first_node) {
	//start counting time
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

	//start sorting
	list_sort_insrt_rfctrd(first_node, AMOUNT);

	//stop counting time
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	//print sorting duration time
	std::chrono::duration<double> diff = end-start;
	fprintf(stdout, "Time to sort list with refactored insertion sort algorithm: %f s\n", diff.count());

	//return duration time
	return diff;
}

inline void list_sort_insrt_rfctrd(list_node_t first_node, size_t length) {
	int32_t tmp;
	size_t i, j;
	for (i = 1; i < length; ++i) {
		tmp = first_node[i];
		j = i - 1;
		while(j < length && tmp < first_node[j]) {
			first_node[j+1] = first_node[j];
			--j;
		}
		first_node[j+1] = tmp;
	}
}

/*** MERGE SORT ***/
std::chrono::duration<double> list_sort_merge_rfctrd(list_node_t first_node) {
	//start counting time
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

	//start sorting
	list_sort_mrg_rfctrd(first_node, 0, AMOUNT - 1);

	//stop counting time
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	//print sorting duration time
	std::chrono::duration<double> diff = end-start;
	fprintf(stdout, "Time to sort list with refactored merge sort algorithm: %f s\n", diff.count());

	//return duration time
	return diff;
}

inline void list_sort_mrg_rfctrd(list_node_t first_node, size_t left, size_t right) {
	if (left < right) {
		size_t middle = (left + right) >> 1;
		list_sort_mrg_rfctrd(first_node, left, middle);
		list_sort_mrg_rfctrd(first_node, middle + 1, right);
		list_merge_rfctrd(first_node, left, middle, right);
	}
}

inline void list_merge_rfctrd(list_node_t first_node, size_t left, size_t middle, size_t right) {
	size_t i, j;
	//copy list content to temporary first_node
	auto *tmp_list = (int32_t*)zmalloc(sizeof(int32_t) * AMOUNT);
	for (i = 0; i < AMOUNT; i++)
		tmp_list[i] = first_node[i];

	//create auxiliary variables
	size_t left1 = left, left2 = middle + 1;
	i = left;
	while (left1 <= middle && left2 <= right) {
		if (first_node[left1] < first_node[left2])
			tmp_list[i++] = first_node[left1++];
		else
			tmp_list[i++] = first_node[left2++];
	}

	while (left1 <= middle)
		tmp_list[i++] = first_node[left1++];

	//copy sorted temporary list content to first_node
	for (j = 0; j < AMOUNT; j++)
		first_node[j] = tmp_list[j];
	free(tmp_list);
}

/*** QUICK SORT ***/
std::chrono::duration<double> list_sort_quick_rfctrd(list_node_t first_node) {
	//start counting time
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

	//start sorting
	list_sort_qck_rfctrd(first_node, 0, AMOUNT - 1);

	//stop counting time
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	//print sorting duration time
	std::chrono::duration<double> diff = end-start;
	fprintf(stdout, "Time to sort list with refactored quick sort algorithm: %f s\n", diff.count());

	//return duration time
	return diff;
}

inline void list_sort_qck_rfctrd(list_node_t first_node, size_t left, size_t right) {
	size_t i;
	if (left < right) {
		size_t splitter = left;
		for (i = left + 1; i <= right; i++) {
			if (first_node[i] < first_node[left])
				swap_xor_list(first_node[++splitter], first_node[i]);
		}
		swap_xor_list(first_node[left], first_node[splitter]);
		list_sort_qck_rfctrd(first_node, left, splitter);
		list_sort_qck_rfctrd(first_node, splitter + 1, right);
	}
}

/*** SELECTION SORT ***/
std::chrono::duration<double> list_sort_selection_rfctrd(list_node_t first_node) {
	//start counting time
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

	//start sorting
	list_sort_slct_rfctrd(first_node, AMOUNT);

	//stop counting time
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	//print sorting duration time
	std::chrono::duration<double> diff = end-start;
	fprintf(stdout, "Time to sort list with refactored selection sort algorithm: %f s\n", diff.count());

	//return duration time
	return diff;
}

inline void list_sort_slct_rfctrd(list_node_t first_node, size_t length) {
	size_t i, j, min_val_index;
	for (i = 0; i < (length - 1); ++i) {
		min_val_index = i;
		for (j = i + 1; j < length; ++j) {
			if (first_node[j] < first_node[min_val_index])
				min_val_index = j;
		}
		swap_xor_list(first_node[i], first_node[min_val_index]);
	}
}

/*** SHELL'S SORT ***/
std::chrono::duration<double> list_sort_shell_rfctrd(list_node_t first_node) {
	//start counting time
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

	//start sorting
	list_sort_shl_rfctrd(first_node, AMOUNT);

	//stop counting time
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	//print sorting duration time
	std::chrono::duration<double> diff = end-start;
	fprintf(stdout, "Time to sort list with refactored original Shell's algorithm: %f s\n", diff.count());

	//return duration time
	return diff;
}

inline void list_sort_shl_rfctrd(list_node_t first_node, size_t length) {
	size_t i, j, step = length / 2;
	int32_t tmp_val;
	while (step >= 1) {
		for (i = step; i < length; i++) {
			tmp_val = first_node[i];
			for (j = i; j >= step && first_node[j-step] > tmp_val; j -= step)
				first_node[j] = first_node[j-step];
			first_node[j] = tmp_val;
		}
		step >>= 1;
	}
}

std::chrono::duration<double> list_sort_ciura_rfctrd(list_node_t first_node) {
	//start counting time
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

	//start sorting
	list_sort_cr_rfctrd(first_node, AMOUNT);

	//stop counting time
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	//print sorting duration time
	std::chrono::duration<double> diff = end-start;
	fprintf(stdout, "Time to sort list with refactored Ciura's version of Shell's algorithm: %f s\n",
		diff.count());

	//return duration time
	return diff;
}

inline void list_sort_cr_rfctrd(list_node_t first_node, size_t length) {
	int32_t tmp_val;
	size_t i, tmp_idx;
	uint16_t steps[8] = {701, 301, 132, 57, 23, 10, 4, 1};
	for (uint16_t step : steps) {
		for (i = step; i < length; i++) {
			tmp_val = first_node[i];
			for (tmp_idx = i; tmp_idx >= step && first_node[tmp_idx-step] > tmp_val; tmp_idx -= step)
				first_node[tmp_idx] = first_node[tmp_idx-step];
			first_node[tmp_idx] = tmp_val;
		}
	}
}

/*** LINEAR SEARCH ***/
std::chrono::duration<double> list_search_linear_rfctrd(list_node_t first_node, const int32_t searched_number, bool &result) {
	//start counting time
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

	//start searching
	result = list_search_lnr_rfctrd(first_node, AMOUNT, searched_number);

	//stop counting time
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	//print searching duration time
	std::chrono::duration<double> diff = end-start;

	// check if number is found
	if (result) {
		fprintf(stdout, "Time to find %ld in list with refactored linear search algorithm: "
				"%f s\n", searched_number, diff.count());
	} else {
		fprintf(stderr, "Refactored linear search didn't found %ld in list.\n", searched_number);
	}

	//return duration time
	return diff;
}

inline bool list_search_lnr_rfctrd(list_node_t first_node, const size_t length, const int32_t searched_item) {
	size_t i;
	for (i = 0; i < length; i++) {
		if (first_node[i] == searched_item)
			return true;
	}
	return false;
}

std::chrono::duration<double> list_search_guardian_rfctrd(list_node_t first_node, const int32_t searched_number,
							   bool &result) {
	//start counting time
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

	//start searching
	result = list_search_grd_rfctrd(first_node, AMOUNT, searched_number);

	//stop counting time
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	//print searching duration time
	std::chrono::duration<double> diff = end-start;

	// check if number is found
	if (result) {
		fprintf(stdout, "Time to find %ld in list with refactored linear search with guardian algorithm: "
				"%f s\n", searched_number, diff.count());
	} else {
		fprintf(stderr, "Refactored linear search with guardian didn't found %ld in list.\n",
			searched_number);
	}

	//return duration time
	return diff;
}

inline bool list_search_grd_rfctrd(list_node_t first_node, const size_t length, const int32_t searched_item) {
	size_t index = 0;
	*(first_node+length) = searched_item;  //set guardian

	while (true) {
		if (*(first_node+index) == searched_item) {
			break;
		}
		++index;
	}

	return index < length;
}

/*** BINARY SEARCH ***/
std::chrono::duration<double> list_search_binary_rfctrd(list_node_t first_node, const int32_t searched_number, bool &result) {
	//start counting time
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

	//start searching
	result = list_search_bnr_rfctrd(first_node, 0, AMOUNT - 1, searched_number);

	//stop counting time
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	//print searching duration time
	std::chrono::duration<double> diff = end-start;

	// check if number is found
	if (result) {
		fprintf(stdout, "Time to find %ld in list with refactored binary search algorithm: "
				"%f s\n", searched_number, diff.count());
	} else {
		fprintf(stderr, "Refactored binary search didn't found %ld in list.\n", searched_number);
	}

	//return duration time
	return diff;
}

inline bool list_search_bnr_rfctrd(list_node_t first_node, size_t left, size_t right, const int32_t searched_item) {
	if (left > right)
		return false;

	size_t middle = (left + right) >> 1;
	if (first_node[middle] == searched_item)
		return true;

	if (searched_item < first_node[middle]) {
		list_search_bnr_rfctrd(first_node, left, middle - 1, searched_item);
	} else {
		list_search_bnr_rfctrd(first_node, middle + 1, right, searched_item);
	}
}

/*** MAXIMUM/ MINIMUM SEARCH ***/
std::chrono::duration<double> list_search_extrema_rfctrd(list_node_t first_node, const int32_t searched_number,
							  bool &result) {
	int32_t minimum = INT32_MAX;
	int32_t maximum = INT32_MIN;

	//start counting time
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

	//start searching
	list_search_ext_rfctrd(first_node, AMOUNT, minimum, maximum);

	if (minimum < INT32_MAX && maximum > INT32_MIN)
		result = true;

	//stop counting time
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	//print searching duration time
	std::chrono::duration<double> diff = end-start;

	// check if number is found
	if (result) {
		fprintf(stdout, "Time to find minimum: %ld and maximum: %ld in list"
				"with refactored extrema search algorithm: %f s\n", minimum, maximum, diff.count());
	} else {
		fprintf(stderr, "Refactored extrema search didn't found minimum: %ld or maximum: %ld in list.\n",
			minimum, maximum);
	}

	//return duration time
	return diff;
}

inline void list_search_ext_rfctrd(list_node_t first_node, const size_t length, int32_t &minimum, int32_t &maximum) {
	size_t i;
	for (i = 0; i < length; i++) {
		if (first_node[i] > maximum)
			maximum = first_node[i];
		if (first_node[i] < minimum)
			minimum = first_node[i];
	}
}

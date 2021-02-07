#include "list_algorithms_refactored.h"

/*** BUBBLE SORT ***/
std::chrono::duration<double> list_sort_bubble_rfctrd(list_node_t &first_node) {
	//start counting time
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

	//start sorting
	list_sort_bbl_rfctrd(first_node, AMOUNT);

	//stop counting time
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	//print sorting duration time
	std::chrono::duration<double> diff = end-start;
	fprintf(stdout, "Time to sort list with refactored bubble sort algorithm: %.7f s\n", diff.count());

	//return duration time
	return diff;
}

inline void list_sort_bbl_rfctrd(list_node_t const &first_node, const size_t lenght) {
	bool change;
	size_t i, j;

	for (i = 0; i < lenght; i++) {	// -1 because the right node is the next node
		change = false;
		list_node_t left_node = first_node, right_node = left_node->next;

		for (j = 0; j < (lenght - i - 1); j++) {
			if (left_node->value > right_node->value) {
				swap_xor_list(left_node, right_node);
				change = true;
			}
			left_node = left_node->next;
			right_node = right_node->next;
			if (right_node == nullptr)
				break;
		}
		if (!change)
			break;
	}
}

/*** INSERTION SORT ***/
std::chrono::duration<double> list_sort_insertion_rfctrd(list_node_t &first_node) {
	//start counting time
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

	//start sorting
	list_sort_insrt_rfctrd(first_node);

	//stop counting time
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	//print sorting duration time
	std::chrono::duration<double> diff = end-start;
	fprintf(stdout, "Time to sort list with refactored insertion sort algorithm: %.7f s\n", diff.count());

	//return duration time
	return diff;
}

inline void list_sort_insrt_rfctrd(list_node_t &first_node) {
	list_controler_t sorted_list = init_metalist();
	list_node_t current_node = first_node, next_node;
	while (current_node != nullptr) {
		next_node = current_node->next;
		list_sort_insert_rfctrd(sorted_list, current_node);
		current_node = next_node;
	}
	first_node = sorted_list->head;
}

inline void list_sort_insert_rfctrd(list_controler_t &sorted_list, list_node_t &new_node) {
	list_node_t current;
	if (sorted_list->head == nullptr || sorted_list->head->value >= new_node->value)
		add_head(sorted_list, new_node);
	else {
		current = sorted_list->head;
		while (current->next != nullptr && current->next->value < new_node->value)
			current = current->next;
		new_node->next = current->next;
		current->next = new_node;
	}
}

/*** MERGE SORT ***/
std::chrono::duration<double> list_sort_merge_rfctrd(list_node_t &first_node) {
	//start counting time
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

	//start sorting
	list_sort_mrg_rfctrd(first_node);

	//stop counting time
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	//print sorting duration time
	std::chrono::duration<double> diff = end-start;
	fprintf(stdout, "Time to sort list with refactored merge sort algorithm: %.7f s\n", diff.count());

	//return duration time
	return diff;
}

inline void list_sort_mrg_rfctrd(list_node_t &first_node) {
	if (first_node == nullptr || first_node->next == nullptr)
		return;

	list_node_t left_head, right_head;
	list_split_to_merge_rfctrd(first_node, left_head, right_head);

	list_sort_mrg_rfctrd(left_head);
	list_sort_mrg_rfctrd(right_head);
	first_node = list_merge_rfctrd(left_head, right_head);
}

inline void list_split_to_merge_rfctrd(list_node_t first_node, list_node_t &sublist_head, list_node_t &sublist_tail)
{
	list_node_t left_tail, right_tail;
	left_tail = first_node;
	right_tail = first_node->next;

	while (right_tail != nullptr) {
		right_tail = right_tail->next;
		if (right_tail != nullptr) {
			left_tail = left_tail->next;
			right_tail = right_tail->next;
		}
	}

	sublist_head = first_node;
	sublist_tail = left_tail->next;
	left_tail->next = nullptr;
}

inline list_node_t list_merge_rfctrd(list_node_t &left_node, list_node_t &right_node) {
	list_node_t temp_node;
	if (left_node == nullptr)
		return right_node;
	else if (right_node == nullptr)
		return left_node;

	if (left_node->value <= right_node->value) {
		temp_node = left_node;
		temp_node->next = list_merge_rfctrd(left_node->next, right_node);
	} else {
		temp_node = right_node;
		temp_node->next = list_merge_rfctrd(left_node, right_node->next);
	}
	return temp_node;
}

/*** QUICK SORT ***/
std::chrono::duration<double> list_sort_quick_rfctrd(list_node_t &first_node) {
	//start counting time
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

	//start sorting
	list_sort_qck_rfctrd(first_node);

	//stop counting time
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	//print sorting duration time
	std::chrono::duration<double> diff = end-start;
	fprintf(stdout, "Time to sort list with refactored quick sort algorithm: %.7f s\n", diff.count());

	//return duration time
	return diff;
}

inline void list_sort_qck_rfctrd(list_node_t &first_node) {
	list_controler_t sorted_list = init_metalist();
	update_metalist(sorted_list, first_node);
	first_node = list_recursion_rfctrd(sorted_list->head, sorted_list->tail);
}

inline list_node_t list_recursion_rfctrd(list_node_t first_node, list_node_t last_node) {
	if (first_node == nullptr || first_node == last_node)
		return first_node;

	list_controler_t sublist = init_metalist();
	list_node_t temp_node;
	list_node_t pivot = list_split_rfctrd(first_node, last_node, sublist->head, sublist->tail);

	if (sublist->head != pivot) {
		temp_node = sublist->head;
		while (temp_node->next != pivot)
			temp_node = temp_node->next;
		temp_node->next = nullptr;

		sublist->head = list_recursion_rfctrd(sublist->head, temp_node);

		temp_node = sublist->head;
		while (temp_node->next != nullptr)
			temp_node = temp_node->next;
		temp_node->next = pivot;
	}
	pivot->next = list_recursion_rfctrd(pivot->next, sublist->tail);

	return sublist->head;
}

inline list_node_t list_split_rfctrd(list_node_t first_node, list_node_t last_node,
				     list_node_t &sublist_head, list_node_t &sublist_tail) {
	list_node_t pivot = last_node;
	list_node_t temp_node;
	list_node_t left_node = nullptr, current_node = first_node, right_node = pivot;

	while (current_node != pivot) {
		if (current_node->value < pivot->value) {
			if (sublist_head == nullptr)
				sublist_head = current_node;
			left_node = current_node;
			current_node = current_node->next;
		} else {
			if (left_node != nullptr)
				left_node->next = current_node->next;
			temp_node = current_node->next;
			current_node->next = nullptr;
			right_node->next = current_node;
			right_node = current_node;
			current_node = temp_node;
		}
	}

	if (sublist_head == nullptr)
		sublist_head = pivot;
	sublist_tail = right_node;

	return pivot;
}

/*** SELECTION SORT ***/
std::chrono::duration<double> list_sort_selection_rfctrd(list_node_t &first_node) {
	//start counting time
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

	//start sorting
	list_sort_slct_rfctrd(first_node);

	//stop counting time
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	//print sorting duration time
	std::chrono::duration<double> diff = end-start;
	fprintf(stdout, "Time to sort list with refactored selection sort algorithm: %.7f s\n", diff.count());

	//return duration time
	return diff;
}

inline void list_sort_slct_rfctrd(list_node_t const &first_node) {
	list_node_t iter_node = first_node;
	list_node_t current_node, min_node;

	while (iter_node != nullptr) {
		current_node = iter_node;
		min_node = iter_node;
		while (current_node != nullptr) {
			if (current_node->value < min_node->value) {
				min_node = current_node;
			}
			current_node = current_node->next;
		}
		swap_xor_list(min_node, iter_node);
		iter_node = iter_node->next;
	}
}

/*** SHELL'S SORT ***/
std::chrono::duration<double> list_sort_shell_rfctrd(list_node_t &first_node) {
	//start counting time
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

	//start sorting
	list_sort_shl_rfctrd(first_node, AMOUNT);

	//stop counting time
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	//print sorting duration time
	std::chrono::duration<double> diff = end-start;
	fprintf(stdout, "Time to sort list with refactored original Shell's algorithm: %.7f s\n", diff.count());

	//return duration time
	return diff;
}

inline void list_sort_shl_rfctrd(list_node_t const &first_node, size_t length) {
	size_t i, j, k, l, step = length >> 1;
	list_node_t left_node, right_node;

	for (i = step; i > 0; i >>= 1) {
		for (j = i; j < length; j++) {
			for (k = (j-i); k <= length; k -= i) {
				left_node = first_node, right_node = first_node;
				for (l = 0; l < k; l++) {
					left_node = left_node->next;
					right_node = right_node->next;
				}
				for (l = 0; l < i; l++) {
					right_node = right_node->next;
				}
				if (right_node->value >= left_node->value)
					break;
				swap_xor_list(left_node, right_node);
			}
		}
	}
}

std::chrono::duration<double> list_sort_ciura_rfctrd(list_node_t &first_node) {
	//start counting time
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

	//start sorting
	list_sort_cr_rfctrd(first_node, AMOUNT);

	//stop counting time
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	//print sorting duration time
	std::chrono::duration<double> diff = end-start;
	fprintf(stdout, "Time to sort list with refactored Ciura's version of Shell's algorithm: %.7f s\n",
		diff.count());

	//return duration time
	return diff;
}

inline void list_sort_cr_rfctrd(list_node_t const &first_node, size_t length) {
	size_t j, k, l;
	list_node_t left_node, right_node;
	u16 steps[8] = {701, 301, 132, 57, 23, 10, 4, 1};

	for (u16 step : steps) {
		for (j = step; j < length; j++) {
			for (k = (j-step); k <= length; k -= step) {
				left_node = first_node, right_node = first_node;
				for (l = 0; l < k; l++) {
					left_node = left_node->next;
					right_node = right_node->next;
				}
				for (l = 0; l < step; l++) {
					right_node = right_node->next;
				}
				if (right_node->value >= left_node->value)
					break;
				swap_xor_list(left_node, right_node);
			}
		}
	}
}

/*** LINEAR SEARCH ***/
std::chrono::duration<double> list_search_linear_rfctrd(list_node_t const &first_node, const i32 searched_number,
							bool &result) {
	//start counting time
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

	//start searching
	result = list_search_lnr_rfctrd(first_node, searched_number);

	//stop counting time
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	//print searching duration time
	std::chrono::duration<double> diff = end-start;

	// check if number is found
	if (result) {
		fprintf(stdout, "Time to find %ld in list with refactored linear search algorithm: "
				"%.7f s\n", searched_number, diff.count());
	} else {
		fprintf(stderr, "Refactored linear search didn't found %ld in list.\n", searched_number);
	}

	//return duration time
	return diff;
}

inline bool list_search_lnr_rfctrd(list_node_t const &first_node, const i32 searched_item) {
	list_node_t current_node = first_node;
	while (current_node != nullptr) {
		if (current_node->value == searched_item)
			return true;
		current_node = current_node->next;
	}
	return false;
}

/*** BINARY SEARCH ***/
std::chrono::duration<double> list_search_binary_rfctrd(list_node_t  const &first_node, const i32 searched_number,
							bool &result) {
	//start counting time
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

	//start searching
	result = list_search_bnr_rfctrd(first_node, searched_number);

	//stop counting time
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	//print searching duration time
	std::chrono::duration<double> diff = end-start;

	// check if number is found
	if (result) {
		fprintf(stdout, "Time to find %ld in list with refactored binary search algorithm: "
				"%.7f s\n", searched_number, diff.count());
	} else {
		fprintf(stderr, "Refactored binary search didn't found %ld in list.\n", searched_number);
	}

	//return duration time
	return diff;
}

inline bool list_search_bnr_rfctrd(list_node_t const &first_node, const i32 searched_item) {
	if (first_node == nullptr)
		return false;

	list_node_t left_head, right_head;
	list_node_t left_tail = first_node, right_tail = first_node->next;

	while (right_tail != nullptr) {
		right_tail = right_tail->next;
		if (right_tail != nullptr) {
			left_tail = left_tail->next;
			right_tail = right_tail->next;
		}
	}

	left_head = first_node;
	right_head = left_tail->next;
	left_tail->next = nullptr;

	if (left_tail->value == searched_item)
		return true;

	if (searched_item < left_tail->value) {
		list_search_bnr_rfctrd(left_head, searched_item);
	} else {
		list_search_bnr_rfctrd(right_head, searched_item);
	}
}

/*** MAXIMUM/ MINIMUM SEARCH ***/
std::chrono::duration<double> list_search_extrema_rfctrd(list_node_t const &first_node, const i32 searched_number,
							  bool &result) {
	i32 minimum = first_node->value;
	i32 maximum = first_node->value;

	//start counting time
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

	//start searching
	list_search_ext_rfctrd(first_node, minimum, maximum);

	if (minimum < INT32_MAX && maximum > INT32_MIN)
		result = true;

	//stop counting time
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	//print searching duration time
	std::chrono::duration<double> diff = end-start;

	// check if number is found
	if (result) {
		fprintf(stdout, "Time to find minimum: %ld and maximum: %ld in list"
				"with refactored extrema search algorithm: %.7f s\n", minimum, maximum, diff.count());
	} else {
		fprintf(stderr, "Refactored extrema search didn't found minimum: %ld or maximum: %ld in list.\n",
			minimum, maximum);
	}

	//return duration time
	return diff;
}

inline void list_search_ext_rfctrd(list_node_t const &first_node, i32 &minimum, i32 &maximum) {
	list_node_t current_node = first_node;
	while (current_node != nullptr) {
		if (current_node->value > maximum)
			maximum = current_node->value;
		if (current_node->value < minimum)
			minimum = current_node->value;
		current_node = current_node->next;
	}
}

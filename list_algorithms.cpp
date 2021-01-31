#include "list_algorithms.h"

std::chrono::duration<double> list_sort_bubble(list_node_t &first_node) {
	//start counting time
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

	//start sorting
	first_node = list_sort_bbl(first_node);

	//stop counting time
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	//print sorting duration time
	std::chrono::duration<double> diff = end-start;
	fprintf(stdout, "Time to sort list with bubble sort algorithm: %.7f s\n", diff.count());

	//return duration time
	return diff;
}

list_node_t list_sort_bbl(list_node_t first_node) {
	list_node_t first_sorted_node = first_node;
	int list_len = get_list_lenght(first_sorted_node);

	for (int i = 0; i < list_len; i++) {
		list_node_t left_node = first_sorted_node;
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
	return first_sorted_node;
}

/*** INSERTION SORT ***/
std::chrono::duration<double> list_sort_insertion(list_node_t &first_node) {
	//start counting time
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

	//start sorting
	first_node = list_sort_insrt(first_node);

	//stop counting time
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	//print sorting duration time
	std::chrono::duration<double> diff = end-start;
	fprintf(stdout, "Time to sort list with insertion sort algorithm: %.7f s\n", diff.count());

	//return duration time
	return diff;
}

list_node_t list_sort_insrt(list_node_t first_node) {
	list_node_t sorted_list = init_list_node();
	list_node_t current_node = first_node, next_node;
	while (current_node != nullptr) {
		next_node = current_node->next;
		list_sort_insert(sorted_list, current_node);
		current_node = next_node;
	}
	list_node_t new_first_node = sorted_list;
	while (sorted_list->value != 0)
		sorted_list = sorted_list->next;
	remove_list_node(new_first_node, sorted_list);
	return new_first_node;
}

void list_sort_insert(list_node_t &sorted_list, list_node_t &new_node) {
	if (sorted_list == nullptr || sorted_list->value >= new_node->value) {
		new_node->next = sorted_list;
		sorted_list = new_node;
	} else {
		list_node_t current = sorted_list;
		while (current->next != nullptr && current->next->value < new_node->value)
			current = current->next;
		new_node->next = current->next;
		current->next = new_node;
	}
}

/*** MERGE SORT ***/
std::chrono::duration<double> list_sort_merge(list_node_t &first_node) {
	//start counting time
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

	//start sorting
	list_sort_mrg(first_node, 0, AMOUNT-1);

	//stop counting time
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	//print sorting duration time
	std::chrono::duration<double> diff = end-start;
	fprintf(stdout, "Time to sort list with merge sort algorithm: %.7f s\n", diff.count());

	//return duration time
	return diff;
}

void list_sort_mrg(list_node_t &first_node, int left, int right) {
	if (left < right) {
		int middle = (left + right) / 2;
		list_sort_mrg(first_node, left, middle);
		list_sort_mrg(first_node, middle + 1, right);
		first_node = list_merge(first_node, left, middle, right);
	}
}

list_node_t list_merge(list_node_t first_node, int left, int middle, int right) {
	list_node_t current_node = first_node;
	list_node_t temp_list = init_list_node();
	list_node_t temp_first_node = temp_list;
	while (current_node != nullptr) {
		set_list_node(temp_first_node, temp_list, current_node->value);
		current_node = current_node->next;
		if (current_node == nullptr)
			break;
		temp_list->next = init_list_node();
		temp_list = temp_list->next;
	}
	temp_list = temp_first_node;

	int left1 = left, left2 = middle + 1, i = left;
	list_node_t left_node = first_node, right_node = left_node;

	for (int j = 0; j < i; j++)
		temp_list = temp_list->next;

	for (int j = 0; j < left1; j++)
		left_node = left_node->next;

	for (int j = 0; j < left2; j++)
		right_node = right_node->next;

	while ((left1 <= middle) && (left2 <= right)) {
		if (left_node->value < right_node->value) {
			set_list_node(temp_first_node, temp_list, left_node->value);
			temp_list = temp_list->next;
			left_node = left_node->next;
			i += 1;
			left1 += 1;
		}
		else {
			set_list_node(temp_first_node, temp_list, right_node->value);
			temp_list = temp_list->next;
			right_node = right_node->next;
			i += 1;
			left2 += 1;
		}
	}

	while (left1 <= middle) {
		set_list_node(temp_first_node, temp_list, left_node->value);
		temp_list = temp_list->next;
		left_node = left_node->next;
		i += 1;
		left1 += 1;
	}

	temp_list = temp_first_node;
	remove_all_nodes(first_node);
	return temp_list;
}

/*** QUICK SORT ***/
std::chrono::duration<double> list_sort_quick(list_node_t &first_node) {
	//start counting time
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

	//start sorting
	first_node = list_sort_qck(first_node);

	//stop counting time
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	//print sorting duration time
	std::chrono::duration<double> diff = end-start;
	fprintf(stdout, "Time to sort list with quick sort algorithm: %.7f s\n", diff.count());

	//return duration time
	return diff;
}

list_node_t list_sort_qck(list_node_t first_node) {
	list_node_t last_node = first_node;
	while (last_node->next != nullptr)
		last_node = last_node->next;
	first_node = list_recursion_rfctrd(first_node, last_node);
	return first_node;
}

list_node_t list_recursion(list_node_t first_node, list_node_t last_node) {
	if (first_node == nullptr || first_node == last_node)
		return first_node;
	list_node_t *valuable_nodes;
	valuable_nodes = list_split(first_node, last_node, valuable_nodes);

	if (valuable_nodes[0] != valuable_nodes[2]) {
		list_node_t temp_node = valuable_nodes[0];
		while (temp_node->next != valuable_nodes[2])
			temp_node = temp_node->next;
		temp_node->next = nullptr;

		valuable_nodes[0] = list_recursion(valuable_nodes[0], temp_node);

		temp_node = valuable_nodes[0];
		while (temp_node->next != nullptr)
			temp_node = temp_node->next;
		temp_node->next = valuable_nodes[2];
	}
	valuable_nodes[2]->next = list_recursion(valuable_nodes[2]->next, valuable_nodes[1]);

	return valuable_nodes[0];
}

list_node_t* list_split(list_node_t first_node, list_node_t last_node, list_node_t *nodes) {
	list_node_t sublist_head, sublist_tail;
	list_node_t pivot = last_node;
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
			list_node_t temp_node = current_node->next;
			current_node->next = nullptr;
			right_node->next = current_node;
			right_node = current_node;
			current_node = temp_node;
		}
	}
	if (sublist_head == nullptr)
		sublist_head = pivot;
	sublist_tail = right_node;

	nodes[0] = sublist_head;
	nodes[1] = sublist_tail;
	nodes[2] = pivot;

	return nodes;
}

/*** SELECTION SORT ***/
std::chrono::duration<double> list_sort_selection(list_node_t &first_node) {
	//start counting time
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

	//start sorting
	first_node = list_sort_slct(first_node);

	//stop counting time
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	//print sorting duration time
	std::chrono::duration<double> diff = end-start;
	fprintf(stdout, "Time to sort list with selection sort algorithm: %.7f s\n", diff.count());

	//return duration time
	return diff;
}

list_node_t list_sort_slct(list_node_t first_node) {
	list_node_t sorted_node = init_list_node();
	list_node_t first_sorted_list_node = sorted_node;

	for (int i = 0; i < AMOUNT; i++) {
		list_node_t current_node = first_node;
		list_node_t temp_node;
		long min_value = LONG_MAX;
		while (current_node != nullptr) {
			if (current_node->value < min_value) {
				min_value = current_node->value;
				temp_node = current_node;
			}
			current_node = current_node->next;
		}
		remove_list_node(first_node, temp_node);
		set_list_node(first_sorted_list_node, sorted_node, min_value);
		sorted_node->next = init_list_node();
		sorted_node = sorted_node->next;
	}

	remove_list_node(first_sorted_list_node, sorted_node);
	remove_all_nodes(first_node);
	return first_sorted_list_node;
}

/*** SHELL'S SORT ***/
std::chrono::duration<double> list_sort_shell(list_node_t &first_node) {
	//start counting time
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

	//start sorting
	first_node = list_sort_shl(first_node, AMOUNT);

	//stop counting time
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	//print sorting duration time
	std::chrono::duration<double> diff = end-start;
	fprintf(stdout, "Time to sort list with original Shell's algorithm: %.7f s\n", diff.count());

	//return duration time
	return diff;
}

list_node_t list_sort_shl(list_node_t first_node, int length) {
	for (int i = (length/2); i > 0; i /= 2) {
		for (int j = i; j < length; j++) {
			for (int k = (j-i); k >= 0; k -= i) {
				list_node_t left_node = first_node, right_node = first_node;
				for (int l = 0; l < k; l++) {
					left_node = left_node->next;
				}
				for (int l = 0; l < (k+i); l++) {
					right_node = right_node->next;
				}
				if (right_node->value >= left_node->value)
					break;
				swap_tmp_list(left_node, right_node);
			}
		}
	}
	return first_node;
}

std::chrono::duration<double> list_sort_ciura(list_node_t &first_node) {
	//start counting time
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

	//start sorting
	first_node = list_sort_cr(first_node, AMOUNT);

	//stop counting time
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	//print sorting duration time
	std::chrono::duration<double> diff = end-start;
	fprintf(stdout, "Time to sort list with Ciura's version of Shell's algorithm: %.7f s\n", diff.count());

	//return duration time
	return diff;
}

list_node_t list_sort_cr(list_node_t first_node, int length) {
	const int size = 8;
	int steps[size] = {701, 301, 132, 57, 23, 10, 4, 1};
	for (int i = 0; i < size; i++) {
		for (int j = steps[i]; j < length; j++) {
			for (int k = (j-steps[i]); k >= 0; k -= steps[i]) {
				list_node_t left_node = first_node, right_node = first_node;
				for (int l = 0; l < k; l++) {
					left_node = left_node->next;
				}
				for (int l = 0; l < (k+steps[i]); l++) {
					right_node = right_node->next;
				}
				if (right_node->value >= left_node->value)
					break;
				swap_tmp_list(left_node, right_node);
			}
		}
	}
	return first_node;
}

/*** LINEAR SEARCH ***/
std::chrono::duration<double> list_search_linear(list_node_t &first_node, long searched_number, bool &result) {
	//start counting time
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

	//start searching
	result = list_search_lnr(first_node, searched_number);

	//stop counting time
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	//print searching duration time
	std::chrono::duration<double> diff = end-start;

	// check if number is found
	if (result) {
		fprintf(stdout, "Time to find %ld in list with linear search algorithm: %.7f s\n",
			searched_number, diff.count());
	} else {
		fprintf(stderr, "Linear search didn't found %ld in list.\n", searched_number);
	}

	//return duration time
	return diff;
}

bool list_search_lnr(list_node_t first_node, long searched_item) {
	bool result = false;
	list_node_t current_node = first_node;
	while (current_node != nullptr) {
		if (current_node->value == searched_item)
			result = true;
		current_node = current_node->next;
	}
	return result;
}

/*** BINARY SEARCH ***/
std::chrono::duration<double> list_search_binary(list_node_t &first_node, long searched_number, bool &result) {
	//start counting time
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

	//start searching
	result = list_search_bnr(first_node, 0, AMOUNT - 1, searched_number);

	//stop counting time
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	//print searching duration time
	std::chrono::duration<double> diff = end-start;

	// check if number is found
	if (result) {
		fprintf(stdout, "Time to find %ld in list with binary search algorithm: %.7f s\n",
			searched_number, diff.count());
	} else {
		fprintf(stderr, "Binary search didn't found %ld in list.\n", searched_number);
	}

	//return duration time
	return diff;
}

bool list_search_bnr(list_node_t first_node, int left, int right, long searched_item) {
	if (left > right)
		return false;

	list_node_t current_item = first_node;
	int middle = (left + right) / 2;
	for (int i = 0; i < middle; i++)
		current_item = current_item->next;

	if (current_item->value == searched_item)
		return true;

	if (searched_item < current_item->value) {
		list_search_bnr(first_node, left, middle - 1, searched_item);
	} else {
		list_search_bnr(first_node, middle + 1, right, searched_item);
	}
}

/*** MAXIMUM/ MINIMUM SEARCH ***/
std::chrono::duration<double> list_search_extrema(list_node_t &first_node, long searched_number, bool &result) {
	//start counting time
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

	//start searching
	long maximum = list_search_max(first_node);
	long minimum = list_search_min(first_node);

	if (minimum <= maximum)
		result = true;

	//stop counting time
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	//print searching duration time
	std::chrono::duration<double> diff = end-start;

	// check if number is found
	if (result) {
		fprintf(stdout, "Time to find minimum: %ld and maximum: %ld in list "
				"with extrema search algorithm: %.7f s\n", minimum, maximum, diff.count());
	} else {
		fprintf(stderr, "Extrema search didn't found minimum: %ld or maximum: %ld in list.\n",
			minimum, maximum);
	}

	//return duration time
	return diff;
}

long list_search_max(list_node_t first_node) {
	long maximum = LONG_MIN;
	list_node_t current_item = first_node;

	while (current_item != nullptr) {
		if (current_item->value > maximum)
			maximum = current_item->value;
		current_item = current_item->next;
	}

	return maximum;
}

long list_search_min(list_node_t first_node) {
	long minimum = LONG_MAX;
	list_node_t current_item = first_node;

	while (current_item != nullptr) {
		if (current_item->value < minimum)
			minimum = current_item->value;
		current_item = current_item->next;
	}

	return minimum;
}
#include "table_algorithms_refactored.h"

/*** BUBBLE SORT ***/
std::chrono::duration<double> table_sort_bubble_rfctrd(i32* table) {
	//start counting time
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

	//start sorting
	table_sort_bbl_rfctrd(table, AMOUNT);

	//stop counting time
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	//print sorting duration time
	std::chrono::duration<double> diff = end-start;
	fprintf(stdout, "Time to sort table with refactored bubble sort algorithm: %.7f s\n", diff.count());

	//return duration time
	return diff;
}

inline void table_sort_bbl_rfctrd(i32* &table, size_t length) {
	bool change;
	size_t i, j;
	for (i = 0; i < length; i++) {
		change = false;
		for (j = 1; j < length-i; j++) {
			if (table[j] < table[j-1]) {
				swap_xor_table(table[j - 1], table[j]);
				change = true;
				j = j-1;
			}
		}
		if (!change)
			break;
	}
}

/*** HEAP SORT ***/
std::chrono::duration<double> table_sort_heap_rfctrd(i32* table) {
	//start counting time
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

	//start sorting
	table_sort_hp_rfctrd(table, AMOUNT);

	//stop counting time
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	//print sorting duration time
	std::chrono::duration<double> diff = end-start;
	fprintf(stdout, "Time to sort table with refactored heap sort algorithm: %.7f s\n", diff.count());

	//return duration time
	return diff;
}

inline void table_sort_hp_rfctrd(i32* &table, size_t length) {
	size_t j;
	for (j = (length >> 1); j > 0; --j) {
		table_restore_rfctrd(table, j, length);
	}
	do {
		swap_xor_table(table[length - 1], table[0]);
		--length;
		table_restore_rfctrd(table, 1, length);
	} while (length > 1);
}

inline void table_restore_rfctrd(i32* &table, size_t j, size_t length) {
	i32 tmp = table[j-1];
	size_t k;

	while (j <= (length >> 1)) {
		k = j << 1;
		if ((k < length) && (table[k-1] < table[k]))
			++k;
		if (tmp >= table[k-1])
			break;
		table[j-1] = table[k-1];
		j = k;
	}
	table[j-1] = tmp;
}

/*** INSERTION SORT ***/
std::chrono::duration<double> table_sort_insertion_rfctrd(i32* table) {
	//start counting time
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

	//start sorting
	table_sort_insrt_rfctrd(table, AMOUNT);

	//stop counting time
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	//print sorting duration time
	std::chrono::duration<double> diff = end-start;
	fprintf(stdout, "Time to sort table with refactored insertion sort algorithm: %.7f s\n", diff.count());

	//return duration time
	return diff;
}

inline void table_sort_insrt_rfctrd(i32* &table, size_t length) {
	i32 tmp;
	size_t i, j;
	for (i = 1; i < length; ++i) {
		tmp = table[i];
		j = i - 1;
		while(j < length && tmp < table[j]) {
			table[j+1] = table[j];
			--j;
		}
		table[j+1] = tmp;
	}
}

/*** MERGE SORT ***/
std::chrono::duration<double> table_sort_merge_rfctrd(i32* table) {
	//start counting time
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

	//start sorting
	table_sort_mrg_rfctrd(table, 0, AMOUNT - 1);

	//stop counting time
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	//print sorting duration time
	std::chrono::duration<double> diff = end-start;
	fprintf(stdout, "Time to sort table with refactored merge sort algorithm: %.7f s\n", diff.count());

	//return duration time
	return diff;
}

inline void table_sort_mrg_rfctrd(i32* &table, size_t left, size_t right) {
	if (left < right) {
		size_t middle = (left + right) >> 1;
		table_sort_mrg_rfctrd(table, left, middle);
		table_sort_mrg_rfctrd(table, middle + 1, right);
		table_merge_rfctrd(table, left, middle, right);
	}
}

inline void table_merge_rfctrd(i32* &table, size_t left, size_t middle, size_t right) {
	size_t left_size = middle - left + 1, right_size = right - middle, left_idx = 0, right_idx = 0, i;
	i32 left_table[left_size], right_table[right_size];

	for (i = 0; i < left_size; ++i)
		left_table[i] = table[left+i];
	for (i = 0; i < right_size; ++i)
		right_table[i] = table[middle+1+i];

	i = left;
	while (left_idx < left_size && right_idx < right_size) {
		if (left_table[left_idx] <= right_table[right_idx])
			table[i++] = left_table[left_idx++];
		else
			table[i++] = right_table[right_idx++];
	}

	while (left_idx < left_size)
		table[i++] = left_table[left_idx++];

	while (right_idx < right_size)
		table[i++] = right_table[right_idx++];
}

/*** QUICK SORT ***/
std::chrono::duration<double> table_sort_quick_rfctrd(i32* table) {
	//start counting time
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

	//start sorting
	table_sort_qck_rfctrd(table, 0, AMOUNT - 1);

	//stop counting time
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	//print sorting duration time
	std::chrono::duration<double> diff = end-start;
	fprintf(stdout, "Time to sort table with refactored quick sort algorithm: %.7f s\n", diff.count());

	//return duration time
	return diff;
}

inline void table_sort_qck_rfctrd(i32* &table, size_t left, size_t right) {
	if (left < right) {
		size_t i;
		size_t splitter = left;
		for (i = left + 1; i <= right; i++) {
			if (table[i] < table[left])
				swap_xor_table(table[++splitter], table[i]);
		}
		swap_xor_table(table[left], table[splitter]);
		table_sort_qck_rfctrd(table, left, splitter);
		table_sort_qck_rfctrd(table, splitter + 1, right);
	}
}

/*** SELECTION SORT ***/
std::chrono::duration<double> table_sort_selection_rfctrd(i32* table) {
	//start counting time
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

	//start sorting
	table_sort_slct_rfctrd(table, AMOUNT);

	//stop counting time
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	//print sorting duration time
	std::chrono::duration<double> diff = end-start;
	fprintf(stdout, "Time to sort table with refactored selection sort algorithm: %.7f s\n", diff.count());

	//return duration time
	return diff;
}

inline void table_sort_slct_rfctrd(i32* &table, size_t length) {
	size_t i, j, min_val_index;
	for (i = 0; i < (length - 1); ++i) {
		min_val_index = i;
		for (j = i + 1; j < length; ++j) {
		if (table[j] < table[min_val_index])
			min_val_index = j;
		}
		swap_xor_table(table[i], table[min_val_index]);
	}
}

/*** SHELL'S SORT ***/
std::chrono::duration<double> table_sort_shell_rfctrd(i32* table) {
	//start counting time
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

	//start sorting
	table_sort_shl_rfctrd(table, AMOUNT);

	//stop counting time
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	//print sorting duration time
	std::chrono::duration<double> diff = end-start;
	fprintf(stdout, "Time to sort table with refactored original Shell's algorithm: %.7f s\n", diff.count());

	//return duration time
	return diff;
}

inline void table_sort_shl_rfctrd(i32* &table, size_t length) {
	size_t i, j, step = length / 2;
	i32 tmp_val;
	while (step >= 1) {
		for (i = step; i < length; i++) {
			tmp_val = table[i];
			for (j = i; j >= step && table[j-step] > tmp_val; j -= step)
				table[j] = table[j-step];
			table[j] = tmp_val;
		}
		step >>= 1;
	}
}

std::chrono::duration<double> table_sort_ciura_rfctrd(i32* table) {
	//start counting time
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

	//start sorting
	table_sort_cr_rfctrd(table, AMOUNT);

	//stop counting time
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	//print sorting duration time
	std::chrono::duration<double> diff = end-start;
	fprintf(stdout, "Time to sort table with refactored Ciura's version of Shell's algorithm: %.7f s\n",
	 	diff.count());

	//return duration time
	return diff;
}

inline void table_sort_cr_rfctrd(i32* &table, size_t length) {
	i32 tmp_val;
	size_t i, tmp_idx;
	u16 steps[8] = {701, 301, 132, 57, 23, 10, 4, 1};
	for (u16 step : steps) {
		for (i = step; i < length; i++) {
			tmp_val = table[i];
			for (tmp_idx = i; tmp_idx >= step && table[tmp_idx-step] > tmp_val; tmp_idx -= step)
				table[tmp_idx] = table[tmp_idx-step];
			table[tmp_idx] = tmp_val;
		}
	}
}

/*** LINEAR SEARCH ***/
std::chrono::duration<double> table_search_linear_rfctrd(i32* table, const i32 searched_number, bool &result) {
	//start counting time
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

	//start searching
	result = table_search_lnr_rfctrd(table, AMOUNT, searched_number);

	//stop counting time
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	//print searching duration time
	std::chrono::duration<double> diff = end-start;

	// check if number is found
	if (result) {
		fprintf(stdout, "Time to find %ld in table with refactored linear search algorithm: "
		  	"%.7f s\n", searched_number, diff.count());
	} else {
		fprintf(stderr, "Refactored linear search didn't found %ld in table.\n", searched_number);
	}

	//return duration time
	return diff;
}

inline bool table_search_lnr_rfctrd(i32* &table, const size_t length, const i32 searched_item) {
	size_t index = 0;
	*(table+length) = searched_item;  //set guardian

	while (true) {
		if (*(table+index) == searched_item) {
			break;
		}
		++index;
	}

	return index < length;
}

/*** BINARY SEARCH ***/
std::chrono::duration<double> table_search_binary_rfctrd(i32* table, const i32 searched_number, bool &result) {
	//start counting time
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

	//start searching
	result = table_search_bnr_rfctrd(table, 0, AMOUNT - 1, searched_number);

	//stop counting time
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	//print searching duration time
	std::chrono::duration<double> diff = end-start;

	// check if number is found
	if (result) {
		fprintf(stdout, "Time to find %ld in table with refactored binary search algorithm: "
		  	"%.7f s\n", searched_number, diff.count());
	} else {
		fprintf(stderr, "Refactored binary search didn't found %ld in table.\n", searched_number);
	}

	//return duration time
	return diff;
}

inline bool table_search_bnr_rfctrd(i32* &table, size_t left, size_t right, const i32 searched_item) {
	if (left > right)
		return false;

	size_t middle = (left + right) >> 1;
	if (table[middle] == searched_item)
		return true;

	if (searched_item < table[middle]) {
		table_search_bnr_rfctrd(table, left, middle - 1, searched_item);
	} else {
		table_search_bnr_rfctrd(table, middle + 1, right, searched_item);
	}
}

/*** MAXIMUM/ MINIMUM SEARCH ***/
std::chrono::duration<double> table_search_extrema_rfctrd(i32* table, const i32 searched_number,
							  bool &result) {
	i32 minimum = table[0];
	i32 maximum = table[0];

	//start counting time
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

	//start searching
	table_search_ext_rfctrd(table, AMOUNT, minimum, maximum);

	if (minimum < INT32_MAX && maximum > INT32_MIN)
		result = true;

	//stop counting time
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	//print searching duration time
	std::chrono::duration<double> diff = end-start;

	// check if number is found
	if (result) {
		fprintf(stdout, "Time to find minimum: %ld and maximum: %ld in table"
		  	"with refactored extrema search algorithm: %.7f s\n", minimum, maximum, diff.count());
	} else {
		fprintf(stderr, "Refactored extrema search didn't found minimum: %ld or maximum: %ld in table.\n",
	  		minimum, maximum);
	}

	//return duration time
	return diff;
}

inline void table_search_ext_rfctrd(i32* &table, const size_t length, i32 &minimum, i32 &maximum) {
	size_t i;
	for (i = 1; i < length; i++) {
		if (table[i] > maximum)
			maximum = table[i];
		if (table[i] < minimum)
			minimum = table[i];
	}
}

#include "table_algorithms.h"

/*** BUBBLE SORT ***/
std::chrono::duration<double> table_sort_bubble(long table[]) {
	//start counting time
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

	//start sorting
	table_sort_bbl(table, AMOUNT);

	//stop counting time
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	//print sorting duration time
	std::chrono::duration<double> diff = end-start;
	fprintf(stdout, "Time to sort table with bubble sort algorithm: %f s\n", diff);

	//return duration time
	return diff;
}

void table_sort_bbl(long table[], int length) {
	for (int i = 0; i < length; i++) {
		for (int j = 0; j <= length-1; j++) {
			if (table[j] > table[j+1])
				swap_tmp(table[j], table[j+1]);
		}
	}
}

/*** HEAP SORT ***/
std::chrono::duration<double> table_sort_heap(long table[]) {
	//start counting time
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

	//start sorting
	table_sort_hp(table, AMOUNT);

	//stop counting time
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	//print sorting duration time
	std::chrono::duration<double> diff = end-start;
	fprintf(stdout, "Time to sort table with heap sort algorithm: %f s\n", diff);

	//return duration time
	return diff;
}

void table_sort_hp(long table[], int length) {
	for (int j = length / 2; j > 0; --j) {
		table_restore(table, j, length);
	}
	do {
		swap_tmp(table[length-1], table[0]);
		length -= 1;
		table_restore(table, 1, length);
	} while (length > 1);
}

void table_restore(long table[], int j, int length) {
	long tmp = table[j-1];
	while (j <= (length / 2)) {
		int k = j * 2;
		if ((k < length) && (table[k-1] < table[k]))
			k += 1;
		if (tmp >= table[k-1])
			break;
		table[j-1] = table[k-1];
		j = k;
	}
	table[j-1] = tmp;
}

/*** INSERTION SORT ***/
std::chrono::duration<double> table_sort_insertion(long table[]) {
	//start counting time
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

	//start sorting
	table_sort_insrt(table, AMOUNT);

	//stop counting time
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	//print sorting duration time
	std::chrono::duration<double> diff = end-start;
	fprintf(stdout, "Time to sort table with insertion sort algorithm: %f s\n", diff);

	//return duration time
	return diff;
}

void table_sort_insrt(long table[], int length) {
	for (int i = 1; i < length; i++) {
		long tmp_i = table[i];
		int j;
		for (j = (i - 1); j >= 0; j--) {
			long tmp_j = table[j];
			if (tmp_j <= tmp_i)
				break;
			table[j+1] = tmp_j;
		}
		table[j+1] = tmp_i;
	}
}

/*** MERGE SORT ***/
std::chrono::duration<double> table_sort_merge(long table[]) {
	//start counting time
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

	//start sorting
	table_sort_mrg(table, 0, AMOUNT - 1);

	//stop counting time
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	//print sorting duration time
	std::chrono::duration<double> diff = end-start;
	fprintf(stdout, "Time to sort table with merge sort algorithm: %f s\n", diff);

	//return duration time
	return diff;
}

void table_sort_mrg(long table[], int left, int right) {
	if (left < right) {
		int middle = (left + right) / 2;
		table_sort_mrg(table, left, middle);
		table_sort_mrg(table, middle + 1, right);
		table_merge(table, left, middle, right);
	}
}

void table_merge(long table[], int left, int middle, int right) {
	//copy table content to temporary table
	auto *tmp_table = (int*)zmalloc(sizeof(int) * AMOUNT);
	for (int i = 0; i < AMOUNT; i++)
		tmp_table[i] = table[i];

	//create auxiliary variables
	int left1 = left, left2 = middle + 1, i = left;
	while ((left1 <= middle) && (left2 <= right)) {
		if (table[left1] < table[left2]) {
			tmp_table[i] = table[left1];
			i += 1;
			left1 += 1;
		}
		else {
			tmp_table[i] = table[left2];
			i += 1;
			left2 += 1;
		}
	}

	while (left1 <= middle) {
		tmp_table[i] = table[left1];
		i += 1;
		left1 += 1;
	}

	//copy sorted temporary table content to table
	for (int j = 0; j < AMOUNT; j++)
		table[j] = tmp_table[j];
	free(tmp_table);
}

/*** QUICK SORT ***/
std::chrono::duration<double> table_sort_quick(long table[]) {
	//start counting time
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

	//start sorting
	table_sort_qck(table, 0, AMOUNT - 1);

	//stop counting time
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	//print sorting duration time
	std::chrono::duration<double> diff = end-start;
	fprintf(stdout, "Time to sort table with quick sort algorithm: %f s\n", diff);

	//return duration time
	return diff;
}

void table_sort_qck(long table[], int left, int right) {
	if (left < right) {
		int splitter = left;
		for (int i = left + 1; i <= right; i++) {
			if (table[i] < table[left]) {
				splitter += 1;
				swap_tmp(table[splitter], table[i]);
			}
		}
		long tmp = table[splitter];
		table[splitter] = table[left];
		table[left] = tmp;
		table_sort_qck(table, left, splitter);
		table_sort_qck(table, splitter + 1, right);
	}
}

/*** SELECTION SORT ***/
std::chrono::duration<double> table_sort_selection(long table[]) {
	//start counting time
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

	//start sorting
	table_sort_slct(table, AMOUNT);

	//stop counting time
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	//print sorting duration time
	std::chrono::duration<double> diff = end-start;
	fprintf(stdout, "Time to sort table with selection sort algorithm: %f s\n", diff);

	//return duration time
	return diff;
}

void table_sort_slct(long table[], int length) {
	for (int i = 0; i < (length - 1); ++i) {
		int min_val_index = i;
		for (int j = i + 1; j < length; ++j) {
			if (table[j] < table[min_val_index])
				min_val_index = j;
		}
		swap_tmp(table[i], table[min_val_index]);
	}
}

/*** SHELL'S SORT ***/
std::chrono::duration<double> table_sort_shell(long table[]) {
	//start counting time
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

	//start sorting
	table_sort_shl(table, AMOUNT);

	//stop counting time
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	//print sorting duration time
	std::chrono::duration<double> diff = end-start;
	fprintf(stdout, "Time to sort table with original Shell's algorithm: %f s\n", diff);

	//return duration time
	return diff;
}

void table_sort_shl(long table[], int length) {
	int step = length / 2;
	while (step >= 1) {
		for (int i = step; i < length; i++) {
			long tmp_val;
			int j;
			tmp_val = table[i];
			for (j = i; j >= step && table[j - step] > tmp_val; j -= step)
				table[j] = table[j - step];
			table[j] = tmp_val;
		}
		step /= 2;
	}
}

std::chrono::duration<double> table_sort_ciura(long table[]) {
	//start counting time
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

	//start sorting
	table_sort_cr(table, AMOUNT);

	//stop counting time
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	//print sorting duration time
	std::chrono::duration<double> diff = end-start;
	fprintf(stdout, "Time to sort table with Ciura's version of Shell's algorithm: %f s\n", diff);

	//return duration time
	return diff;
}

void table_sort_cr(long table[], int length) {
	const int size = 8;
	int steps[size] = {701, 301, 132, 57, 23, 10, 4, 1};
	for (int i = 0; i < size; i++) {
		int step = steps[i];
		for (int j = step; j < length; j++) {
			long tmp_val;
			int k;
			tmp_val = table[j];
			for (k = j; k >= step && table[k-step] > tmp_val; k -= step)
				table[k] = table[k-step];
			table[k] = tmp_val;
		}
	}
}

/*** LINEAR SEARCH ***/
std::chrono::duration<double> table_search_linear(long table[], long searched_number, bool &result) {
	//start counting time
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

	//start searching
	result = table_search_lnr(table, AMOUNT, searched_number);

	//stop counting time
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	//print searching duration time
	std::chrono::duration<double> diff = end-start;

	// check if number is found
	if (result) {
		fprintf(stdout, "Time to find %ld in table with linear search algorithm: %f s\n",
	  		searched_number, diff);
	} else {
		fprintf(stderr, "Linear search didn't found %ld in table.\n", searched_number);
	}

	//return duration time
	return diff;
}

bool table_search_lnr(long table[], int length, long searched_item) {
	for (int i = 0; i < length; i++) {
		long current_item = table[i];
		if (current_item == searched_item) {
			return true;
		}
	}
	return false;
}

std::chrono::duration<double> table_search_guardian(long table[], long searched_number, bool &result) {
	//start counting time
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

	//start searching
	result = table_search_grd(table, AMOUNT, searched_number);

	//stop counting time
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	//print searching duration time
	std::chrono::duration<double> diff = end-start;

	// check if number is found
	if (result) {
		fprintf(stdout, "Time to find %ld in table with linear search with guardian algorithm: %f s\n",
	  		searched_number, diff);
	} else {
		fprintf(stderr, "Linear search with guardian didn't found %ld in table.\n", searched_number);
	}

	//return duration time
	return diff;
}

bool table_search_grd(long table[], int length, long searched_item) {
	int index = 0;
	long tmp_table[length+1];
	for (int i = 0; i <= length; i++)
		tmp_table[i] = table[i];
	tmp_table[length] = searched_item;  //set guardian

	while (true) {
		long current_item = tmp_table[index];
		if (current_item == searched_item) {
			break;
		}
		index += 1;
	}
	if (index < length)
		return true;
	else
		return false;
}

/*** BINARY SEARCH ***/
std::chrono::duration<double> table_search_binary(long table[], long searched_number, bool &result) {
	//start counting time
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

	//start searching
	result = table_search_bnr(table, 0, AMOUNT - 1, searched_number);

	//stop counting time
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	//print searching duration time
	std::chrono::duration<double> diff = end-start;

	// check if number is found
	if (result) {
		fprintf(stdout, "Time to find %ld in table with binary search algorithm: %f s\n",
	  		searched_number, diff);
	} else {
		fprintf(stderr, "Binary search didn't found %ld in table.\n", searched_number);
	}

	//return duration time
	return diff;
}

bool table_search_bnr(long table[], int left, int right, long searched_item) {
	if (left > right)
		return false;

	int middle = (left + right) / 2;
	long current_item = table[middle];
	if (current_item == searched_item)
		return true;

	if (searched_item < current_item) {
		table_search_bnr(table, left, middle - 1, searched_item);
	} else {
		table_search_bnr(table, middle + 1, right, searched_item);
	}
}

/*** MAXIMUM/ MINIMUM SEARCH ***/
std::chrono::duration<double> table_search_extrema(long table[], long searched_number, bool &result) {
	//start counting time
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

	//start searching
	long maximum = table_search_max(table, AMOUNT);
	long minimum = table_search_min(table, AMOUNT);

	if (minimum <= maximum)
		result = true;

	//stop counting time
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	//print searching duration time
	std::chrono::duration<double> diff = end-start;

	// check if number is found
	if (result) {
		fprintf(stdout, "Time to find minimum: %ld and maximum: %ld in table "
		  	"with extrema search algorithm: %f s\n", minimum, maximum, diff);
	} else {
		fprintf(stderr, "Extrema search didn't found minimum: %ld or maximum: %ld in table.\n",
	  		minimum, maximum);
	}

	//return duration time
	return diff;
}

long table_search_max(long table[], int length) {
	long maximum = LONG_MIN;
	for (int i = 0; i < length; i++) {
		if (table[i] > maximum)
			maximum = table[i];
	}
	return maximum;
}

long table_search_min(long table[], int length) {
	long minimum = LONG_MAX;
	for (int i = 0; i < length; i++) {
		if (table[i] < minimum)
			minimum = table[i];
	}
	return minimum;
}
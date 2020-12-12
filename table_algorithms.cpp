#include "table_algorithms.h"

/*** BUBBLE SORT ***/
std::chrono::duration<double> bubblesort_prerefactored(long table[]) {
	//start counting time
	std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();

	//start sorting
	bblsort_prerefactored(table, AMOUNT);

	//stop counting time
	std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now();

	//print sorting duration time
	std::chrono::duration<double> diff = end-start;
	fprintf(stdout, "Time to sort by bubblesort algorithm: "
			"%f s\n", diff);

	//return duration time
	return diff;
}

void bblsort_prerefactored(long table[], int length) {
	for (int i = (length - 1); i > 0; i--) {
		for (int j = 1; j <= i; j++) {
			if (table[j] < table[j-1]) {
                swap_tmp(table[j], table[j-1]);
			}
		}
	}
}

/*** HEAP SORT ***/
std::chrono::duration<double> heapsort_prerefactored(long table[]) {
	//start counting time
	std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();

	//start sorting
	hsort_prerefactored(table, AMOUNT);

	//stop counting time
	std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now();

	//print sorting duration time
	std::chrono::duration<double> diff = end-start;
	fprintf(stdout, "Time to sort by heapsort algorithm: "
			"%f s\n", diff);

	//return duration time
	return diff;
}

void hsort_prerefactored(long table[], int length) {
	int j;
	for (j = length / 2; j > 0; --j) {
		restore_prerefactored(table, j, length);
	}
	do {
        swap_tmp(table[length-1], table[0]);
		length -= 1;
		restore_prerefactored(table, 1, length);
	} while (length > 1);
}

void restore_prerefactored(long table[], int j, int length) {
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
std::chrono::duration<double> insertionsort_prerefactored(long table[]) {
	//start counting time
	std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();

	//start sorting
	inssort_prerefactored(table, AMOUNT);

	//stop counting time
	std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now();

	//print sorting duration time
	std::chrono::duration<double> diff = end-start;
	fprintf(stdout, "Time to sort by insertionsort algorithm: "
			"%f s\n", diff);

	//return duration time
	return diff;
}

void inssort_prerefactored(long table[], int length) {
	for (int i = 1; i < length; ++i) {
		long tmp = table[i];
		int j = i - 1;
		while(j < length && tmp < table[j]) {
			table[j+1] = table[j];
			j -= 1;
		}
		table[j+1] = tmp;
	}
}

/*** MERGE SORT ***/
std::chrono::duration<double> mergesort_prerefactored(long table[]) {
	//start counting time
	std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();

	//start sorting
	msort_prerefactored(table, 0, AMOUNT - 1);

	//stop counting time
	std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now();

	//print sorting duration time
	std::chrono::duration<double> diff = end-start;
	fprintf(stdout, "Time to sort by mergesort algorithm: "
			"%f s\n", diff);

	//return duration time
	return diff;
}

void msort_prerefactored(long table[], int left, int right) {
	if (left < right) {
		int middle = (left + right) / 2;
		msort_prerefactored(table, left, middle);
		msort_prerefactored(table, middle + 1, right);
		merge_prerefactored(table, left, middle, right);
	}
}

void merge_prerefactored(long table[], int left, int middle, int right) {
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
std::chrono::duration<double> quicksort_prerefactored(long table[]) {
	//start counting time
	std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();

	//start sorting
	qsort_prerefactored(table, 0, AMOUNT - 1);

	//stop counting time
	std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now();

	//print sorting duration time
	std::chrono::duration<double> diff = end-start;
	fprintf(stdout, "Time to sort by quicksort algorithm: "
			"%f s\n", diff);

	//return duration time
	return diff;
}

void qsort_prerefactored(long table[], int left, int right) {
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
		qsort_prerefactored(table, left, splitter);
		qsort_prerefactored(table, splitter + 1, right);
	}
}

/*** SELECTION SORT ***/
std::chrono::duration<double> selectionsort_prerefactored(long table[]) {
	//start counting time
	std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();

	//start sorting
	slctsort_prerefactored(table, AMOUNT);

	//stop counting time
	std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now();

	//print sorting duration time
	std::chrono::duration<double> diff = end-start;
	fprintf(stdout, "Time to sort by selectionsort algorithm: "
			"%f s\n", diff);

	//return duration time
	return diff;
}

void slctsort_prerefactored(long table[], int length) {
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
std::chrono::duration<double> shellsort_prerefactored(long table[]) {
	//start counting time
	std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();

	//start sorting
	shlsort_prerefactored(table, AMOUNT);

	//stop counting time
	std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now();

	//print sorting duration time
	std::chrono::duration<double> diff = end-start;
	fprintf(stdout, "Time to sort by original Shell's algorithm: "
			"%f s\n", diff);

	//return duration time
	return diff;
}

void shlsort_prerefactored(long table[], int length) {
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

std::chrono::duration<double> ciurassort_prerefactored(long table[]) {
	//start counting time
	std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();

	//start sorting
	crsort_prerefactored(table, AMOUNT);

	//stop counting time
	std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now();

	//print sorting duration time
	std::chrono::duration<double> diff = end-start;
	fprintf(stdout, "Time to sort by Ciura's version of Shell's algorithm: "
			"%f s\n", diff);

	//return duration time
	return diff;
}

void crsort_prerefactored(long table[], int length) {
	int tmp_val, tmp_idx;
	int steps[8] = {701, 301, 132, 57, 23, 10, 4, 1};
	for (int step : steps) {
		for (int j = step; j < length; j++) {
			tmp_val = table[j];
			for (tmp_idx = j; tmp_idx >= step && table[tmp_idx-step] > tmp_val; tmp_idx -= step)
				table[tmp_idx] = table[tmp_idx - step];
			table[tmp_idx] = tmp_val;
		}
	}
}

/*** LINEAR SEARCH ***/
std::chrono::duration<double> linearsearch_prerefactored(long table[], long searched_number, bool &result) {
	//start counting time
	std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();

	//start searching
	result = lnrsearch_prerefactored(table, AMOUNT, searched_number);

	//stop counting time
	std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now();

	//print searching duration time
	std::chrono::duration<double> diff = end-start;

	// check if number is found
	if (result) {
		fprintf(stdout, "Time to find %d with linear search algorithm: "
				"%f s\n", searched_number, diff);
	} else {
		fprintf(stderr, "Linear search didn't found %d.\n", searched_number);
	}

	//return duration time
	return diff;
}

bool lnrsearch_prerefactored(long table[], int length, long searched_item) {
	for (int i = 0; i < length; i++) {
		long current_item = table[i];
		if (current_item == searched_item) {
			return true;
		}
	}
	return false;
}

std::chrono::duration<double> guardiansearch_prerefactored(long table[], long searched_number, bool &result) {
	//start counting time
	std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();

	//start searching
	result = grdsearch_prerefactored(table, AMOUNT, searched_number);

	//stop counting time
	std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now();

	//print searching duration time
	std::chrono::duration<double> diff = end-start;

	// check if number is found
	if (result) {
		fprintf(stdout, "Time to find %d with linear search with guardian algorithm: "
				"%f s\n", searched_number, diff);
	} else {
		fprintf(stderr, "Linear search with guardian didn't found %d.\n", searched_number);
	}

	//return duration time
	return diff;
}

bool grdsearch_prerefactored(long table[], int length, long searched_item) {
	int index = 0;
	*(table+length) = searched_item;  //set guardian

	while (true) {
		long current_item = table[index];
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
std::chrono::duration<double> binarysearch_prerefactored(long table[], long searched_number, bool &result) {
	//start counting time
	std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();

	//start searching
	result = bnrsearch_prerefactored(table, 0, AMOUNT - 1, searched_number);

	//stop counting time
	std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now();

	//print searching duration time
	std::chrono::duration<double> diff = end-start;

	// check if number is found
	if (result) {
		fprintf(stdout, "Time to find %d with binary search algorithm: "
				"%f s\n", searched_number, diff);
	} else {
		fprintf(stderr, "Binary search didn't found %d.\n", searched_number);
	}

	//return duration time
	return diff;
}

bool bnrsearch_prerefactored(long table[], int left, int right, long searched_item) {
	if (left > right)
		return false;

	int middle = (left + right) / 2;
	long current_item = table[middle];
	if (current_item == searched_item)
		return true;

	if (searched_item < current_item) {
		bnrsearch_prerefactored(table, left, middle - 1, searched_item);
	} else {
		bnrsearch_prerefactored(table, middle + 1, right, searched_item);
	}
}

/*** MAXIMUM/ MINIMUM SEARCH ***/
std::chrono::duration<double> maxminsearch_prerefactored(long table[], long searched_number, bool &result) {
	//start counting time
	std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();

	//start searching
	long maximum = maxsearch_prerefactored(table, AMOUNT);
    long minimum = minsearch_prerefactored(table, AMOUNT);

	if (minimum <= maximum)
		result = true;

	//stop counting time
	std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now();

	//print searching duration time
	std::chrono::duration<double> diff = end-start;

	// check if number is found
	if (result) {
		fprintf(stdout, "Time to find minimum: %ld and maximum: %ld with extrema search algorithm: "
				"%f s\n", minimum, maximum, diff);
	} else {
		fprintf(stderr, "Extrema search didn't found minimum: %ld or maximum: %ld.\n", minimum, maximum);
	}

	//return duration time
	return diff;
}

long maxsearch_prerefactored(long table[], int length) {
    long maximum = LONG_MIN;
	for (int i = 0; i < length; i++) {
		if (table[i] > maximum)
			maximum = table[i];
	}
}

long minsearch_prerefactored(long table[], int length) {
    long minimum = LONG_MAX;
    for (int i = 0; i < length; i++) {
        if (table[i] < minimum)
            minimum = table[i];
    }
}
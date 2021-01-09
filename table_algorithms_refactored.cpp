#include "table_algorithms_refactored.h"

/*** BUBBLE SORT ***/
std::chrono::duration<double> bubblesort(int32_t table[]) {
    //start counting time
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

    //start sorting
    bblsort(table, AMOUNT);

    //stop counting time
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    //print sorting duration time
    std::chrono::duration<double> diff = end-start;
    fprintf(stdout, "Time to sort by refactored bubblesort algorithm: "
                    "%f s\n", diff);

    //return duration time
    return diff;
}

inline void bblsort(int32_t table[], size_t length) {
	bool change = false;
	size_t i, j;
	for (i = 0; i < length; i++) {
		for (j = 1; j <= length-i; j++) {
			if (table[j] < table[j-1]) {
				swap_xor(table[j-1], table[j]);
				change = true;
			}
		}
		if (!change)
			break;
	}
}

/*** HEAP SORT ***/
std::chrono::duration<double> heapsort(int32_t table[]) {
    //start counting time
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

    //start sorting
    hsort(table, AMOUNT);

    //stop counting time
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    //print sorting duration time
    std::chrono::duration<double> diff = end-start;
    fprintf(stdout, "Time to sort by refactored heapsort algorithm: "
                    "%f s\n", diff);

    //return duration time
    return diff;
}

inline void hsort(int32_t table[], size_t length) {
    size_t j;
    for (j = (length >> 1); j > 0; --j) {
        restore(table, j, length);
    }
    do {
        swap_xor(table[length-1], table[0]);
        --length;
        restore(table, 1, length);
    } while (length > 1);
}

inline void restore(int32_t table[], size_t j, size_t length) {
    int32_t tmp = table[j-1];
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
std::chrono::duration<double> insertionsort(int32_t table[]) {
    //start counting time
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

    //start sorting
    inssort(table, AMOUNT);

    //stop counting time
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    //print sorting duration time
    std::chrono::duration<double> diff = end-start;
    fprintf(stdout, "Time to sort by refactored insertionsort algorithm: "
                    "%f s\n", diff);

    //return duration time
    return diff;
}

inline void inssort(int32_t table[], size_t length) {
	int32_t tmp;
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
std::chrono::duration<double> mergesort(int32_t table[]) {
    //start counting time
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

    //start sorting
    msort(table, 0, AMOUNT - 1);

    //stop counting time
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    //print sorting duration time
    std::chrono::duration<double> diff = end-start;
    fprintf(stdout, "Time to sort by refactored mergesort algorithm: "
                    "%f s\n", diff);

    //return duration time
    return diff;
}

inline void msort(int32_t table[], size_t left, size_t right) {
	if (left < right) {
		size_t middle = (left + right) >> 1;
		msort(table, left, middle);
		msort(table, middle + 1, right);
		merge(table, left, middle, right);
	}
}

inline void merge(int32_t table[], size_t left, size_t middle, size_t right) {
    size_t i, j;
	//copy table content to temporary table
	auto *tmp_table = (int32_t*)zmalloc(sizeof(int32_t) * AMOUNT);
	for (i = 0; i < AMOUNT; i++)
		tmp_table[i] = table[i];

	//create auxiliary variables
	size_t left1 = left, left2 = middle + 1;
    i = left;
	while (left1 <= middle && left2 <= right) {
		if (table[left1] < table[left2])
			tmp_table[i++] = table[left1++];
		else
			tmp_table[i++] = table[left2++];
	}

	while (left1 <= middle)
		tmp_table[i++] = table[left1++];

	//copy sorted temporary table content to table
	for (j = 0; j < AMOUNT; j++)
		table[j] = tmp_table[j];
	free(tmp_table);
}

/*** QUICK SORT ***/
std::chrono::duration<double> quicksort(int32_t table[]) {
    //start counting time
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

    //start sorting
    qsort(table, 0, AMOUNT - 1);

    //stop counting time
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    //print sorting duration time
    std::chrono::duration<double> diff = end-start;
    fprintf(stdout, "Time to sort by refactored quicksort algorithm: "
                    "%f s\n", diff);

    //return duration time
    return diff;
}

inline void qsort(int32_t table[], size_t left, size_t right) {
    size_t i;
    if (left < right) {
        size_t splitter = left;
        for (i = left + 1; i <= right; i++) {
            if (table[i] < table[left])
                swap_xor(table[++splitter], table[i]);
        }
        swap_xor(table[left], table[splitter]);
        qsort(table, left, splitter);
        qsort(table, splitter + 1, right);
    }
}

/*** SELECTION SORT ***/
std::chrono::duration<double> selectionsort(int32_t table[]) {
    //start counting time
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

    //start sorting
    slctsort(table, AMOUNT);

    //stop counting time
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    //print sorting duration time
    std::chrono::duration<double> diff = end-start;
    fprintf(stdout, "Time to sort by refactored selectionsort algorithm: "
                    "%f s\n", diff);

    //return duration time
    return diff;
}

inline void slctsort(int32_t table[], size_t length) {
	size_t i, j, min_val_index;
	for (i = 0; i < (length - 1); ++i) {
		min_val_index = i;
		for (j = i + 1; j < length; ++j) {
		if (table[j] < table[min_val_index])
			min_val_index = j;
		}
		swap_xor(table[i], table[min_val_index]);
	}
}

/*** SHELL'S SORT ***/
std::chrono::duration<double> shellsort(int32_t table[]) {
    //start counting time
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

    //start sorting
    shlsort(table, AMOUNT);

    //stop counting time
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    //print sorting duration time
    std::chrono::duration<double> diff = end-start;
    fprintf(stdout, "Time to sort by refactored original Shell's algorithm: "
                    "%f s\n", diff);

    //return duration time
    return diff;
}

inline void shlsort(int32_t table[], size_t length) {
    size_t i, j, step = length / 2;
	int32_t tmp_val;
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

std::chrono::duration<double> ciurassort(int32_t table[]) {
    //start counting time
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

    //start sorting
    crsort(table, AMOUNT);

    //stop counting time
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    //print sorting duration time
    std::chrono::duration<double> diff = end-start;
    fprintf(stdout, "Time to sort by refactored Ciura's version of Shell's algorithm: "
                    "%f s\n", diff);

    //return duration time
    return diff;
}

inline void crsort(int32_t table[], size_t length) {
	int32_t tmp_val;
	size_t i, tmp_idx;
	uint16_t steps[8] = {701, 301, 132, 57, 23, 10, 4, 1};
	for (uint16_t step : steps) {
		for (i = step; i < length; i++) {
			tmp_val = table[i];
			for (tmp_idx = i; tmp_idx >= step && table[tmp_idx-step] > tmp_val; tmp_idx -= step)
				table[tmp_idx] = table[tmp_idx-step];
			table[tmp_idx] = tmp_val;
		}
	}
}

/*** LINEAR SEARCH ***/
std::chrono::duration<double> linearsearch(int32_t table[], const int32_t searched_number, bool &result) {
	//start counting time
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

	//start searching
	result = lnrsearch(table, AMOUNT, searched_number);

	//stop counting time
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	//print searching duration time
	std::chrono::duration<double> diff = end-start;

	// check if number is found
	if (result) {
		fprintf(stdout, "Time to find %ld with refactored linear search algorithm: "
				"%f s\n", searched_number, diff);
	} else {
		fprintf(stderr, "Refactored linear search didn't found %ld.\n", searched_number);
	}

	//return duration time
	return diff;
}

inline bool lnrsearch(int32_t table[], const size_t length, const int32_t searched_item) {
    size_t i;
	for (i = 0; i < length; i++) {
		if (table[i] == searched_item)
			return true;
	}
	return false;
}

std::chrono::duration<double> guardiansearch(int32_t table[], const int32_t searched_number, bool &result) {
	//start counting time
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

	//start searching
	result = grdsearch(table, AMOUNT, searched_number);

	//stop counting time
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	//print searching duration time
	std::chrono::duration<double> diff = end-start;

	// check if number is found
	if (result) {
		fprintf(stdout, "Time to find %ld with refactored linear search with guardian algorithm: "
				"%f s\n", searched_number, diff);
	} else {
		fprintf(stderr, "Refactored linear search with guardian didn't found %ld.\n", searched_number);
	}

	//return duration time
	return diff;
}

inline bool grdsearch(int32_t table[], const size_t length, const int32_t searched_item) {
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
std::chrono::duration<double> binarysearch(int32_t table[], const int32_t searched_number, bool &result) {
	//start counting time
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

	//start searching
	result = bnrsearch(table, 0, AMOUNT - 1, searched_number);

	//stop counting time
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	//print searching duration time
	std::chrono::duration<double> diff = end-start;

	// check if number is found
	if (result) {
		fprintf(stdout, "Time to find %ld with refactored binary search algorithm: "
				"%f s\n", searched_number, diff);
	} else {
		fprintf(stderr, "Refactored binary search didn't found %ld.\n", searched_number);
	}

	//return duration time
	return diff;
}

inline bool bnrsearch(int32_t table[], size_t left, size_t right, const int32_t searched_item) {
	if (left > right)
		return false;

	size_t middle = (left + right) >> 1;
	if (table[middle] == searched_item)
		return true;

	if (searched_item < table[middle]) {
		bnrsearch(table, left, middle - 1, searched_item);
	} else {
		bnrsearch(table, middle + 1, right, searched_item);
	}
}

/*** MAXIMUM/ MINIMUM SEARCH ***/
std::chrono::duration<double> maxminsearch(int32_t table[], const int32_t searched_number, bool &result) {
	int32_t minimum = INT32_MAX;
	int32_t maximum = INT32_MIN;

	//start counting time
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

	//start searching
	mxmnearch(table, AMOUNT, minimum, maximum);

	if (minimum < INT32_MAX && maximum > INT32_MIN)
		result = true;

	//stop counting time
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	//print searching duration time
	std::chrono::duration<double> diff = end-start;

	// check if number is found
	if (result) {
		fprintf(stdout, "Time to find minimum: %ld and maximum: %ld "
		  "with refactored extrema search algorithm: %f s\n", minimum, maximum, diff);
	} else {
		fprintf(stderr, "Refactored extrema search didn't found minimum: %ld or maximum: "
		  "%ld.\n", minimum, maximum);
	}

	//return duration time
	return diff;
}

inline void mxmnearch(int32_t table[], const size_t length, int32_t &minimum, int32_t &maximum) {
    size_t i;
	for (i = 0; i < length; i++) {
		if (table[i] > maximum)
			maximum = table[i];
		if (table[i] < minimum)
			minimum = table[i];
	}
}

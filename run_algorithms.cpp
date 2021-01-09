#include "run_algorithms.h"

//initialize collective functions
uint8_t run_normal_algorithms(const int32_t&number) {
	uint8_t result;

	result = run_normal_sort_algorithms();
	if (result)
		return result;

	result = run_normal_search_algorithms(number);
	if (result)
		return result;

	return SUCCESS;
}

uint8_t run_refactored_algorithms(const int32_t&number) {
	uint8_t result;

	result = run_refactored_sort_algorithms();
	if (result)
		return result;

	result = run_refactored_search_algorithms(number);
	if (result)
		return result;

	return SUCCESS;
}

uint8_t run_normal_sort_algorithms() {
	uint8_t result;

	//sort data by bubblesort algorithm
	result = execute_sort_algorithm_on_table(GENERATED_DATA_FILE.c_str(), BUBBLESORT_FILE,
						 reinterpret_cast<std::chrono::duration<double> (*)(
							 int_fast32_t *)>(bubblesort_prerefactored));
	if(result) {
		fprintf(stderr, "Bubblesort failed with code %u.", result);
		return BBL_SORT_FAIL;
	}

	//sort data by quicksort algorithm
	result = execute_sort_algorithm_on_table(GENERATED_DATA_FILE.c_str(), QUICKSORT_FILE,
						 reinterpret_cast<std::chrono::duration<double> (*)(
							 int_fast32_t *)>(quicksort_prerefactored));
	if(result) {
		fprintf(stderr, "Quicksort failed with code %u.", result);
		return QCK_SORT_FAIL;
	}

	//sort data by mergesort algorithm
	result = execute_sort_algorithm_on_table(GENERATED_DATA_FILE.c_str(), MERGESORT_FILE,
						 reinterpret_cast<std::chrono::duration<double> (*)(
							 int_fast32_t *)>(mergesort_prerefactored));
	if(result) {
		fprintf(stderr, "Mergesort failed with code %u.", result);
		return MRG_SORT_FAIL;
	}

	//sort data by insertionsort algorithm
	result = execute_sort_algorithm_on_table(GENERATED_DATA_FILE.c_str(), INSERTIONSORT_FILE,
						 reinterpret_cast<std::chrono::duration<double> (*)(
							 int_fast32_t *)>(insertionsort_prerefactored));
	if(result) {
		fprintf(stderr, "Insertionsort failed with code %u.", result);
		return INS_SORT_FAIL;
	}

	//sort data by heapsort algorithm
	result = execute_sort_algorithm_on_table(GENERATED_DATA_FILE.c_str(), HEAPSORT_FILE,
						 reinterpret_cast<std::chrono::duration<double> (*)(
							 int_fast32_t *)>(heapsort_prerefactored));
	if(result) {
		fprintf(stderr, "Heapsort failed with code %u.", result);
		return HP_SORT_FAIL;
	}

	//sort data by selectionsort algorithm
	result = execute_sort_algorithm_on_table(GENERATED_DATA_FILE.c_str(), SELECTIONSORT_FILE,
						 reinterpret_cast<std::chrono::duration<double> (*)(
							 int_fast32_t *)>(selectionsort_prerefactored));
	if(result) {
		fprintf(stderr, "Selectionsort failed with code %u.", result);
		return SLC_SORT_FAIL;
	}

	//sort data by original Shell's algorithm
	result = execute_sort_algorithm_on_table(GENERATED_DATA_FILE.c_str(), SHELLSSORT_FILE,
						 reinterpret_cast<std::chrono::duration<double> (*)(
							 int_fast32_t *)>(shellsort_prerefactored));
	if(result) {
		fprintf(stderr, "Shell's sort failed with code %u.", result);
		return SHL_SORT_FAIL;
	}

	//sort data by Ciura's verion of Shell's algorithm
	result = execute_sort_algorithm_on_table(GENERATED_DATA_FILE.c_str(), CIURASSORT_FILE,
						 reinterpret_cast<std::chrono::duration<double> (*)(
							 int_fast32_t *)>(ciurassort_prerefactored));
	if(result) {
		fprintf(stderr, "Ciura's sort failed with code %u.", result);
		return CRA_SORT_FAIL;
	}

	return SUCCESS;
}

uint8_t run_refactored_sort_algorithms() {
	uint8_t result;

	//sort data by bubblesort algorithm
	result = execute_sort_algorithm_on_table(GENERATED_DATA_FILE.c_str(), REF_BUBBLESORT_FILE, bubblesort);
	if(result) {
		fprintf(stderr, "Refactored bubblesort failed with code %u.", result);
		return BBL_SORT_FAIL;
	}

	//sort data by quicksort algorithm
	result = execute_sort_algorithm_on_table(GENERATED_DATA_FILE.c_str(), REF_QUICKSORT_FILE, quicksort);
	if(result) {
		fprintf(stderr, "Refactored quicksort failed with code %u.", result);
		return QCK_SORT_FAIL;
	}

	//sort data by mergesort algorithm
	result = execute_sort_algorithm_on_table(GENERATED_DATA_FILE.c_str(), REF_MERGESORT_FILE, mergesort);
	if(result) {
		fprintf(stderr, "Refactored mergesort failed with code %u.", result);
		return MRG_SORT_FAIL;
	}

	//sort data by insertionsort algorithm
	result = execute_sort_algorithm_on_table(GENERATED_DATA_FILE.c_str(), REF_INSERTIONSORT_FILE, insertionsort);
	if(result) {
		fprintf(stderr, "Refactored insertionsort failed with code %u.", result);
		return INS_SORT_FAIL;
	}

	//sort data by heapsort algorithm
	result = execute_sort_algorithm_on_table(GENERATED_DATA_FILE.c_str(), REF_HEAPSORT_FILE, heapsort);
	if(result) {
		fprintf(stderr, "Refactored heapsort failed with code %u.", result);
		return HP_SORT_FAIL;
	}

	//sort data by selectionsort algorithm
	result = execute_sort_algorithm_on_table(GENERATED_DATA_FILE.c_str(), REF_SELECTIONSORT_FILE, selectionsort);
	if(result) {
		fprintf(stderr, "Refactored selectionsort failed with code %u.", result);
		return SLC_SORT_FAIL;
	}

	//sort data by original Shell's algorithm
	result = execute_sort_algorithm_on_table(GENERATED_DATA_FILE.c_str(), REF_SHELLSSORT_FILE, shellsort);
	if(result) {
		fprintf(stderr, "Refactored Shell's sort failed with code %u.", result);
		return SHL_SORT_FAIL;
	}

	//sort data by Ciura's verion of Shell's algorithm
	result = execute_sort_algorithm_on_table(GENERATED_DATA_FILE.c_str(), REF_CIURASSORT_FILE, ciurassort);
	if(result) {
		fprintf(stderr, "Refactored Ciura's sort failed with code %u.", result);
		return CRA_SORT_FAIL;
	}

	return SUCCESS;
}

uint8_t run_normal_search_algorithms(const int32_t &number) {
	uint8_t result;

	//search data with linear search algorithm
	result = execute_search_algorithm_on_table(GENERATED_DATA_FILE.c_str(), LINEARSEARCH_FILE, number,
						   reinterpret_cast<std::chrono::duration<double> (*)(int_fast32_t *,
												      const int_fast32_t,
												      bool &)>(linearsearch_prerefactored));
	if(result) {
		fprintf(stderr, "Linear search failed with code %u.", result);
		return LNR_SEARCH_FAIL;
	}

	//search data with linear search with guardian algorithm
	result = execute_search_algorithm_on_table(GENERATED_DATA_FILE.c_str(), GUARDIANSEARCH_FILE, number,
						   reinterpret_cast<std::chrono::duration<double> (*)(int_fast32_t *,
												      const int_fast32_t,
												      bool &)>(guardiansearch_prerefactored));
	if(result) {
		fprintf(stderr, "Linear search with guardian failed with code %u.", result);
		return GRD_SEARCH_FAIL;
	}

	//search data with binary search algorithm
	result = execute_search_algorithm_on_table(QUICKSORT_FILE.c_str(), BINARYSEARCH_FILE, number,
						   reinterpret_cast<std::chrono::duration<double> (*)(int_fast32_t *,
												      const int_fast32_t,
												      bool &)>(binarysearch_prerefactored));
	if(result) {
		fprintf(stderr, "Binary search failed with code %u.", result);
		return BNR_SEARCH_FAIL;
	}

	//search data with extrema search algorithm
	result = execute_search_algorithm_on_table(GENERATED_DATA_FILE.c_str(), MAXMINSEARCH_FILE, number,
						   reinterpret_cast<std::chrono::duration<double> (*)(int_fast32_t *,
												      const int_fast32_t,
												      bool &)>(maxminsearch_prerefactored));
	if(result) {
		fprintf(stderr, "Extrema search failed with code %u.", result);
		return EXTR_SEARCH_FAIL;
	}

	return result;
}

uint8_t run_refactored_search_algorithms(const int32_t &number) {
	uint8_t result;

	//search data with linear search algorithm
	result = execute_search_algorithm_on_table(GENERATED_DATA_FILE.c_str(), REF_LINEARSEARCH_FILE, number,
						   linearsearch);
	if(result) {
		fprintf(stderr, "Refactored linear search failed with code %u.", result);
		return LNR_SEARCH_FAIL;
	}

	//search data with linear search with guardian algorithm
	result = execute_search_algorithm_on_table(GENERATED_DATA_FILE.c_str(), REF_GUARDIANSEARCH_FILE, number,
						   guardiansearch);
	if(result) {
		fprintf(stderr, "Refactored linear search with guardian failed with code %u.", result);
		return GRD_SEARCH_FAIL;
	}

	//search data with binary search algorithm
	result = execute_search_algorithm_on_table(REF_QUICKSORT_FILE.c_str(), REF_BINARYSEARCH_FILE, number,
						   binarysearch);
	if(result) {
		fprintf(stderr, "Refactored binary search failed with code %u.", result);
		return BNR_SEARCH_FAIL;
	}

	//search data with extrema search algorithm
	result = execute_search_algorithm_on_table(GENERATED_DATA_FILE.c_str(), REF_MAXMINSEARCH_FILE, number,
						   maxminsearch);
	if(result) {
		fprintf(stderr, "Refactored extrema search failed with code %u.", result);
		return EXTR_SEARCH_FAIL;
	}

	return result;
}

#include "run_algorithms.h"

uint8_t run_normal_table_algorithms(const int32_t&number) {
	uint8_t result;

	result = run_normal_table_sort_algorithms();
	if (result)
		return result;

	result = run_normal_table_search_algorithms(number);
	if (result)
		return result;

	return SUCCESS;
}

uint8_t run_refactored_table_algorithms(const int32_t&number) {
	uint8_t result;

	result = run_refactored_table_sort_algorithms();
	if (result)
		return result;

	result = run_refactored_table_search_algorithms(number);
	if (result)
		return result;

	return SUCCESS;
}

uint8_t run_normal_table_sort_algorithms() {
	uint8_t result;

	result = execute_sort_algorithm_on_table(GENERATED_DATA_FILE.c_str(), TABLE_SORT_BUBBLE,
						 reinterpret_cast<std::chrono::duration<double> (*)(
							 int_fast32_t *)>(table_sort_bubble));
	if(result) {
		fprintf(stderr, "Table bubble sort failed with code %u.", result);
		return BBL_SORT_FAIL;
	}

	result = execute_sort_algorithm_on_table(GENERATED_DATA_FILE.c_str(), TABLE_SORT_QUICK,
						 reinterpret_cast<std::chrono::duration<double> (*)(
							 int_fast32_t *)>(table_sort_quick));
	if(result) {
		fprintf(stderr, "Table quick sort failed with code %u.", result);
		return QCK_SORT_FAIL;
	}

	result = execute_sort_algorithm_on_table(GENERATED_DATA_FILE.c_str(), TABLE_SORT_MERGE,
						 reinterpret_cast<std::chrono::duration<double> (*)(
							 int_fast32_t *)>(table_sort_merge));
	if(result) {
		fprintf(stderr, "Table merge sort failed with code %u.", result);
		return MRG_SORT_FAIL;
	}

	result = execute_sort_algorithm_on_table(GENERATED_DATA_FILE.c_str(), TABLE_SORT_INSERTION,
						 reinterpret_cast<std::chrono::duration<double> (*)(
							 int_fast32_t *)>(table_sort_insertion));
	if(result) {
		fprintf(stderr, "Table insertion sort failed with code %u.", result);
		return INS_SORT_FAIL;
	}

	result = execute_sort_algorithm_on_table(GENERATED_DATA_FILE.c_str(), TABLE_SORT_HEAP,
						 reinterpret_cast<std::chrono::duration<double> (*)(
							 int_fast32_t *)>(table_sort_heap));
	if(result) {
		fprintf(stderr, "Table heap sort failed with code %u.", result);
		return HP_SORT_FAIL;
	}

	result = execute_sort_algorithm_on_table(GENERATED_DATA_FILE.c_str(), TABLE_SORT_SELECTION,
						 reinterpret_cast<std::chrono::duration<double> (*)(
							 int_fast32_t *)>(table_sort_selection));
	if(result) {
		fprintf(stderr, "Table selection sort failed with code %u.", result);
		return SLC_SORT_FAIL;
	}

	result = execute_sort_algorithm_on_table(GENERATED_DATA_FILE.c_str(), TABLE_SORT_SHELL,
						 reinterpret_cast<std::chrono::duration<double> (*)(
							 int_fast32_t *)>(table_sort_shell));
	if(result) {
		fprintf(stderr, "Table Shell's sort failed with code %u.", result);
		return SHL_SORT_FAIL;
	}

	result = execute_sort_algorithm_on_table(GENERATED_DATA_FILE.c_str(), TABLE_SORT_CIURA,
						 reinterpret_cast<std::chrono::duration<double> (*)(
							 int_fast32_t *)>(table_sort_ciura));
	if(result) {
		fprintf(stderr, "Table Ciura's sort failed with code %u.", result);
		return CRA_SORT_FAIL;
	}

	return SUCCESS;
}

uint8_t run_refactored_table_sort_algorithms() {
	uint8_t result;

	result = execute_sort_algorithm_on_table(GENERATED_DATA_FILE.c_str(), TABLE_SORT_BUBBLE_REF,
						 table_sort_bubble_rfctrd);
	if(result) {
		fprintf(stderr, "Refactored table bubble sort failed with code %u.", result);
		return BBL_SORT_FAIL;
	}

	result = execute_sort_algorithm_on_table(GENERATED_DATA_FILE.c_str(), TABLE_SORT_QUICK_REF,
						 table_sort_quick_rfctrd);
	if(result) {
		fprintf(stderr, "Refactored table quick sort failed with code %u.", result);
		return QCK_SORT_FAIL;
	}

	result = execute_sort_algorithm_on_table(GENERATED_DATA_FILE.c_str(), TABLE_SORT_MERGE_REF,
						 table_sort_merge_rfctrd);
	if(result) {
		fprintf(stderr, "Refactored table merge sort failed with code %u.", result);
		return MRG_SORT_FAIL;
	}

	result = execute_sort_algorithm_on_table(GENERATED_DATA_FILE.c_str(), TABLE_SORT_INSERTION_REF,
						 table_sort_insertion_rfctrd);
	if(result) {
		fprintf(stderr, "Refactored table insertion sort failed with code %u.", result);
		return INS_SORT_FAIL;
	}

	result = execute_sort_algorithm_on_table(GENERATED_DATA_FILE.c_str(), TABLE_SORT_HEAP_REF,
						 table_sort_heap_rfctrd);
	if(result) {
		fprintf(stderr, "Refactored table heap sort failed with code %u.", result);
		return HP_SORT_FAIL;
	}

	result = execute_sort_algorithm_on_table(GENERATED_DATA_FILE.c_str(), TABLE_SORT_SELECTION_REF,
						 table_sort_selection_rfctrd);
	if(result) {
		fprintf(stderr, "Refactored table selection sort failed with code %u.", result);
		return SLC_SORT_FAIL;
	}

	result = execute_sort_algorithm_on_table(GENERATED_DATA_FILE.c_str(), TABLE_SORT_SHELL_REF,
						 table_sort_shell_rfctrd);
	if(result) {
		fprintf(stderr, "Refactored table Shell's sort failed with code %u.", result);
		return SHL_SORT_FAIL;
	}

	result = execute_sort_algorithm_on_table(GENERATED_DATA_FILE.c_str(), TABLE_SORT_CIURA_REF,
						 table_sort_ciura_rfctrd);
	if(result) {
		fprintf(stderr, "Refactored table Ciura's sort failed with code %u.", result);
		return CRA_SORT_FAIL;
	}

	return SUCCESS;
}

uint8_t run_normal_table_search_algorithms(const int32_t &number) {
	uint8_t result;

	result = execute_search_algorithm_on_table(GENERATED_DATA_FILE.c_str(), TABLE_SEARCH_LINEAR, number,
						   reinterpret_cast<std::chrono::duration<double> (*)(int_fast32_t *,
						   	const int_fast32_t, bool &)>(table_search_linear));
	if(result) {
		fprintf(stderr, "Table linear search failed with code %u.", result);
		return LNR_SEARCH_FAIL;
	}

	result = execute_search_algorithm_on_table(GENERATED_DATA_FILE.c_str(), TABLE_SEARCH_GUARDIAN, number,
						   reinterpret_cast<std::chrono::duration<double> (*)(int_fast32_t *,
						   	const int_fast32_t,bool &)>(table_search_guardian));
	if(result) {
		fprintf(stderr, "Table linear search with guardian failed with code %u.", result);
		return GRD_SEARCH_FAIL;
	}

	result = execute_search_algorithm_on_table(TABLE_SORT_QUICK.c_str(), TABLE_SEARCH_BINARY, number,
						   reinterpret_cast<std::chrono::duration<double> (*)(int_fast32_t *,
						   	const int_fast32_t, bool &)>(table_search_binary));
	if(result) {
		fprintf(stderr, "Table binary search failed with code %u.", result);
		return BNR_SEARCH_FAIL;
	}

	result = execute_search_algorithm_on_table(GENERATED_DATA_FILE.c_str(), TABLE_SEARCH_EXTREMA, number,
						   reinterpret_cast<std::chrono::duration<double> (*)(int_fast32_t *,
						   	const int_fast32_t, bool &)>(table_search_extrema));
	if(result) {
		fprintf(stderr, "Table extrema search failed with code %u.", result);
		return EXTR_SEARCH_FAIL;
	}

	return SUCCESS;
}

uint8_t run_refactored_table_search_algorithms(const int32_t &number) {
	uint8_t result;

	result = execute_search_algorithm_on_table(GENERATED_DATA_FILE.c_str(), TABLE_SEARCH_LINEAR_REF, number,
						   table_search_linear_rfctrd);
	if(result) {
		fprintf(stderr, "Refactored table linear search failed with code %u.", result);
		return LNR_SEARCH_FAIL;
	}

	result = execute_search_algorithm_on_table(GENERATED_DATA_FILE.c_str(), TABLE_SEARCH_GUARDIAN_REF, number,
						   table_search_guardian_rfctrd);
	if(result) {
		fprintf(stderr, "Refactored table linear search with guardian failed with code %u.", result);
		return GRD_SEARCH_FAIL;
	}

	result = execute_search_algorithm_on_table(TABLE_SORT_QUICK_REF.c_str(), TABLE_SEARCH_BINARY_REF, number,
						   table_search_binary_rfctrd);
	if(result) {
		fprintf(stderr, "Refactored table binary search failed with code %u.", result);
		return BNR_SEARCH_FAIL;
	}

	result = execute_search_algorithm_on_table(GENERATED_DATA_FILE.c_str(), TABLE_SEARCH_EXTREMA_REF, number,
						   table_search_extrema_rfctrd);
	if(result) {
		fprintf(stderr, "Refactored table extrema search failed with code %u.", result);
		return EXTR_SEARCH_FAIL;
	}

	return SUCCESS;
}

uint8_t run_normal_list_algorithms(const int32_t&number) {
	uint8_t result;

	result = run_normal_list_sort_algorithms();
	if (result)
		return result;

	result = run_normal_list_search_algorithms(number);
	if (result)
		return result;

	return SUCCESS;
}

uint8_t run_refactored_list_algorithms(const int32_t&number) {
	uint8_t result;

	result = run_refactored_list_sort_algorithms();
	if (result)
		return result;

	result = run_refactored_list_search_algorithms(number);
	if (result)
		return result;

	return SUCCESS;
}

uint8_t run_normal_list_sort_algorithms() {
	uint8_t result;

	result = execute_sort_algorithm_on_list(GENERATED_DATA_FILE.c_str(), LIST_SORT_BUBBLE,
						reinterpret_cast<std::chrono::duration<double> (*)(
							list_node_t&)>(list_sort_bubble));
	if(result) {
		fprintf(stderr, "List bubble sort failed with code %u.", result);
		return BBL_SORT_FAIL;
	}

	result = execute_sort_algorithm_on_list(GENERATED_DATA_FILE.c_str(), LIST_SORT_QUICK,
						 reinterpret_cast<std::chrono::duration<double> (*)(
							 list_node_t&)>(list_sort_quick));
	if(result) {
		fprintf(stderr, "List quick sort failed with code %u.", result);
		return QCK_SORT_FAIL;
	}

	result = execute_sort_algorithm_on_list(GENERATED_DATA_FILE.c_str(), LIST_SORT_MERGE,
						 reinterpret_cast<std::chrono::duration<double> (*)(
							 list_node_t&)>(list_sort_merge));
	if(result) {
		fprintf(stderr, "List merge sort failed with code %u.", result);
		return MRG_SORT_FAIL;
	}

	result = execute_sort_algorithm_on_list(GENERATED_DATA_FILE.c_str(), LIST_SORT_INSERTION,
						 reinterpret_cast<std::chrono::duration<double> (*)(
							 list_node_t&)>(list_sort_insertion));
	if(result) {
		fprintf(stderr, "List insertion sort failed with code %u.", result);
		return INS_SORT_FAIL;
	}

	result = execute_sort_algorithm_on_list(GENERATED_DATA_FILE.c_str(), LIST_SORT_HEAP,
						 reinterpret_cast<std::chrono::duration<double> (*)(
							 list_node_t&)>(list_sort_heap));
	if(result) {
		fprintf(stderr, "List heap sort failed with code %u.", result);
		return HP_SORT_FAIL;
	}

	result = execute_sort_algorithm_on_list(GENERATED_DATA_FILE.c_str(), LIST_SORT_SELECTION,
						 reinterpret_cast<std::chrono::duration<double> (*)(
							 list_node_t&)>(list_sort_selection));
	if(result) {
		fprintf(stderr, "List selection sort failed with code %u.", result);
		return SLC_SORT_FAIL;
	}

	result = execute_sort_algorithm_on_list(GENERATED_DATA_FILE.c_str(), LIST_SORT_SHELL,
						 reinterpret_cast<std::chrono::duration<double> (*)(
							 list_node_t&)>(list_sort_shell));
	if(result) {
		fprintf(stderr, "List Shell's sort failed with code %u.", result);
		return SHL_SORT_FAIL;
	}

	result = execute_sort_algorithm_on_list(GENERATED_DATA_FILE.c_str(), LIST_SORT_CIURA,
						 reinterpret_cast<std::chrono::duration<double> (*)(
							 list_node_t&)>(list_sort_ciura));
	if(result) {
		fprintf(stderr, "List Ciura's sort failed with code %u.", result);
		return CRA_SORT_FAIL;
	}

	return SUCCESS;
}

uint8_t run_refactored_list_sort_algorithms() {
	uint8_t result;

	result = execute_sort_algorithm_on_list(GENERATED_DATA_FILE.c_str(), LIST_SORT_BUBBLE_REF,
						 list_sort_bubble_rfctrd);
	if(result) {
		fprintf(stderr, "Refactored list bubble sort failed with code %u.", result);
		return BBL_SORT_FAIL;
	}

	result = execute_sort_algorithm_on_list(GENERATED_DATA_FILE.c_str(), LIST_SORT_QUICK_REF,
						 list_sort_quick_rfctrd);
	if(result) {
		fprintf(stderr, "Refactored list quick sort failed with code %u.", result);
		return QCK_SORT_FAIL;
	}

	result = execute_sort_algorithm_on_list(GENERATED_DATA_FILE.c_str(), LIST_SORT_MERGE_REF,
						 list_sort_merge_rfctrd);
	if(result) {
		fprintf(stderr, "Refactored list merge sort failed with code %u.", result);
		return MRG_SORT_FAIL;
	}

	result = execute_sort_algorithm_on_list(GENERATED_DATA_FILE.c_str(), LIST_SORT_INSERTION_REF,
						 list_sort_insertion_rfctrd);
	if(result) {
		fprintf(stderr, "Refactored list insertion sort failed with code %u.", result);
		return INS_SORT_FAIL;
	}

	result = execute_sort_algorithm_on_list(GENERATED_DATA_FILE.c_str(), LIST_SORT_HEAP_REF,
						 list_sort_heap_rfctrd);
	if(result) {
		fprintf(stderr, "Refactored list heap sort failed with code %u.", result);
		return HP_SORT_FAIL;
	}

	result = execute_sort_algorithm_on_list(GENERATED_DATA_FILE.c_str(), LIST_SORT_SELECTION_REF,
						 list_sort_selection_rfctrd);
	if(result) {
		fprintf(stderr, "Refactored list selection sort failed with code %u.", result);
		return SLC_SORT_FAIL;
	}

	result = execute_sort_algorithm_on_list(GENERATED_DATA_FILE.c_str(), LIST_SORT_SHELL_REF,
						 list_sort_shell_rfctrd);
	if(result) {
		fprintf(stderr, "Refactored list Shell's sort failed with code %u.", result);
		return SHL_SORT_FAIL;
	}

	result = execute_sort_algorithm_on_list(GENERATED_DATA_FILE.c_str(), LIST_SORT_CIURA_REF,
						 list_sort_ciura_rfctrd);
	if(result) {
		fprintf(stderr, "Refactored list Ciura's sort failed with code %u.", result);
		return CRA_SORT_FAIL;
	}

	return SUCCESS;
}

uint8_t run_normal_list_search_algorithms(const int32_t &number) {
	uint8_t result;

	result = execute_search_algorithm_on_list(GENERATED_DATA_FILE.c_str(), LIST_SEARCH_LINEAR, number,
						   reinterpret_cast<std::chrono::duration<double> (*)(list_node_t&,
						   	const int_fast32_t, bool &)>(list_search_linear));
	if(result) {
		fprintf(stderr, "List linear search failed with code %u.", result);
		return LNR_SEARCH_FAIL;
	}

	result = execute_search_algorithm_on_list(GENERATED_DATA_FILE.c_str(), LIST_SEARCH_GUARDIAN, number,
						   reinterpret_cast<std::chrono::duration<double> (*)(list_node_t&,
						   	const int_fast32_t,bool &)>(list_search_guardian));
	if(result) {
		fprintf(stderr, "List linear search with guardian failed with code %u.", result);
		return GRD_SEARCH_FAIL;
	}

	result = execute_search_algorithm_on_list(LIST_SORT_QUICK.c_str(), LIST_SEARCH_BINARY, number,
						   reinterpret_cast<std::chrono::duration<double> (*)(list_node_t&,
						   	const int_fast32_t, bool &)>(list_search_binary));
	if(result) {
		fprintf(stderr, "List binary search failed with code %u.", result);
		return BNR_SEARCH_FAIL;
	}

	result = execute_search_algorithm_on_list(GENERATED_DATA_FILE.c_str(), LIST_SEARCH_EXTREMA, number,
						   reinterpret_cast<std::chrono::duration<double> (*)(list_node_t&,
						   	const int_fast32_t, bool &)>(list_search_extrema));
	if(result) {
		fprintf(stderr, "List extrema search failed with code %u.", result);
		return EXTR_SEARCH_FAIL;
	}

	return SUCCESS;
}

uint8_t run_refactored_list_search_algorithms(const int32_t &number) {
	uint8_t result;

	result = execute_search_algorithm_on_list(GENERATED_DATA_FILE.c_str(), LIST_SEARCH_LINEAR_REF, number,
						   list_search_linear_rfctrd);
	if(result) {
		fprintf(stderr, "Refactored list linear search failed with code %u.", result);
		return LNR_SEARCH_FAIL;
	}

	result = execute_search_algorithm_on_list(GENERATED_DATA_FILE.c_str(), LIST_SEARCH_GUARDIAN_REF, number,
						   list_search_guardian_rfctrd);
	if(result) {
		fprintf(stderr, "Refactored list linear search with guardian failed with code %u.", result);
		return GRD_SEARCH_FAIL;
	}

	result = execute_search_algorithm_on_list(LIST_SORT_QUICK_REF.c_str(), LIST_SEARCH_BINARY_REF, number,
						   list_search_binary_rfctrd);
	if(result) {
		fprintf(stderr, "Refactored list binary search failed with code %u.", result);
		return BNR_SEARCH_FAIL;
	}

	result = execute_search_algorithm_on_list(GENERATED_DATA_FILE.c_str(), LIST_SEARCH_EXTREMA_REF, number,
						   list_search_extrema_rfctrd);
	if(result) {
		fprintf(stderr, "Refactored list extrema search failed with code %u.", result);
		return EXTR_SEARCH_FAIL;
	}

	return SUCCESS;
}

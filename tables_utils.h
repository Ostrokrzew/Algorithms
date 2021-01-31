#ifndef ENGINEERPROJECT_TABLES_UTILS_H
#define ENGINEERPROJECT_TABLES_UTILS_H

#include "headers.h"

static i32* table_data_read(const char *input_file) {
	auto *return_ptr = (i32 *)zmalloc(sizeof(i32) * AMOUNT);

	//open the file with generated data to sort for read
	FILE *input = fopen(input_file, "r");
	if (!input) {
		*return_ptr = ERR_OPEN_FILE;
		return return_ptr;
	}

	//read input file to table
	char *line = (char *)zmalloc(12 * sizeof(char));
	size_t len = 12;

	for (size_t i = 0; i < AMOUNT; i++) {
		if (getline(&line, &len, input) == -1) {
			free(line);
			*return_ptr = ERR_READ_DATA;
			return return_ptr;
		}
		*(return_ptr + i) = atol(line);
	}
	free(line);

	//close input file
	if (fclose(input)) {
		*return_ptr = ERR_CLOSE_FILE;
		return return_ptr;
	}

	return return_ptr;
}

static u8 table_sort_result_write(const std::string &output_file, const i32 *table, const double diff) {
	//open the output file for write and clear its content
	FILE *output = fopen(output_file.c_str(), "w");
	if (!output)
		return ERR_OPEN_FILE;

	fprintf(output, "duration: %.7f s\n", diff);

	//save output to file
	for (size_t i = 0; i < AMOUNT; i++) {
		fprintf(output, "%ld\n", table[i]);
	}

	//close output file
	if (fclose(output))
		return ERR_CLOSE_FILE;

	return SUCCESS;
}

static u8 table_search_result_write(const std::string &output_file, const double diff) {
	//open the output file for write and clear its content
	FILE *output = fopen(output_file.c_str(), "w");
	if (!output)
		return ERR_OPEN_FILE;

	fprintf(output, "duration: %.7f s\n", diff);

	//close output file
	if (fclose(output))
		return ERR_CLOSE_FILE;

	return SUCCESS;
}

static inline u8 validate_order(const i32 table[]) {
	for (size_t i = 1; i < AMOUNT; i++) {
		if (table[i-1] > table[i]) {
			fprintf(stderr, "%ld should be greater or equal %ld.\n", table[i], table[i-1]);
			return ERR_WRG_ORDR;
		}
	}

	return SUCCESS;
}

static u8 execute_sort_algorithm_on_table(const char *input_file, const std::string &output_file,
					       std::chrono::duration<double> (*algorithm)(i32*)) {
	u8 result;
	//open the file with generated data to sort for read
	i32 *table = table_data_read(input_file);
	if (*table == ERR_OPEN_FILE || *table == ERR_READ_DATA || *table == ERR_CLOSE_FILE)
		return *table;

	// run algorithm and receive its duration time
	std::chrono::duration<double> diff = algorithm(table);

	// write results to file
	result = table_sort_result_write(output_file, table, diff.count());
	if (result)
		goto error;

	result = validate_order(table);

error:
	free(table);

	return result;
}

static u8 execute_search_algorithm_on_table(const char *input_file, const std::string &output_file,
						 const i32 searched_number, std::chrono::duration<double>
						         (*algorithm)(i32*, const i32, bool&)) {
	u8 result;
	bool is_found = false;
	//open the file with generated data to sort for read
	i32 *table = table_data_read(input_file);
	if (*table == ERR_OPEN_FILE || *table == ERR_READ_DATA || *table == ERR_CLOSE_FILE)
		return *table;

	// run algorithm and receive its duration time
	std::chrono::duration<double> diff = algorithm(table, searched_number, is_found);

	// write results without table to file
	result = table_search_result_write(output_file, diff.count());
	if (result)
		return result;

	free(table);

	return is_found ? SUCCESS :  SEARCH_FAIL;
}

static inline void swap_xor_table(i32 &a, i32 &b) {
	if (a == b)
		return;
	a ^= b;
	b ^= a;
	a ^= b;
}

static void swap_tmp_table(long &a, long &b) {
	long tmp = a;
	a = b;
	b = tmp;
}

#endif //ENGINEERPROJECT_TABLES_UTILS_H

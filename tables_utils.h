#ifndef ENGINEERPROJECT_TABLES_UTILS_H
#define ENGINEERPROJECT_TABLES_UTILS_H

#include "headers.h"

static int32_t* read_to_table(const char *input_file) {
	auto *return_ptr = (int32_t *)zmalloc(sizeof(int32_t) * AMOUNT);

	//open the file with generated data to sort for read
	FILE *input = fopen(input_file, "r");
	if (!input) {
		*return_ptr = ERR_OPEN_FILE;
		return return_ptr;
	}

	//read input file to table
	char *line = (char *)zmalloc(10 * sizeof(char));
	size_t len = 10;

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

static uint8_t table_to_write(const std::string &output_file, int32_t table[], double diff) {
	//open the output file for write and clear its content
	std::ofstream output;
	output.open(output_file, std::ofstream::trunc);
	if (!output.is_open())
		return ERR_OPEN_FILE;

	output << "duration: " << diff << " s\n" << std::endl;

	//save output to file
	for (size_t i = 0; i < AMOUNT; i++) {
		output << table[i] << std::endl;
	}

	//close output file
	output.close();
	if (output.is_open())
		return ERR_CLOSE_FILE;

	return SUCCESS;
}

static uint8_t search_result_to_write(const std::string &output_file, double diff) {
	//open the output file for write and clear its content
	std::ofstream output;
	output.open(output_file, std::ofstream::trunc);
	if (!output.is_open())
		return ERR_OPEN_FILE;

	output << "duration: " << diff << " s" << std::endl;

	//close output file
	output.close();
	if (output.is_open())
		return ERR_CLOSE_FILE;

	return SUCCESS;
}

static inline uint8_t validate_order(const int32_t table[]) {
	for (size_t i = 1; i < AMOUNT; i++) {
		if (table[i-1] > table[i]) {
			fprintf(stderr, "%ld should be greater or equal %ld.\n", table[i], table[i-1]);
			return ERR_WRG_ORDR;
		}
	}

	return SUCCESS;
}

static uint8_t execute_sort_algorithm_on_table(const char *input_file, const std::string &output_file,
						   std::chrono::duration<double> (*algorithm)(int32_t[])) {
	uint8_t result;
	//open the file with generated data to sort for read
	int32_t *table = read_to_table(input_file);
	if (*table == ERR_OPEN_FILE || *table == ERR_READ_DATA || *table == ERR_CLOSE_FILE)
		return *table;

	// run algorithm and receive its duration time
	std::chrono::duration<double> diff = algorithm(table);

	result = validate_order(table);
	if (result)
		goto error;

	// write results to file
	result = table_to_write(output_file, table, diff.count());

error:
	free(table);

	return result;
}

static uint8_t execute_search_algorithm_on_table(const char *input_file, const std::string &output_file,
						 const int32_t searched_number, std::chrono::duration<double>
						         (*algorithm)(int32_t[], const int32_t, bool&)
) {
	uint8_t result;
	bool is_found = false;
	//open the file with generated data to sort for read
	int32_t *table = read_to_table(input_file);
	if (*table == ERR_OPEN_FILE || *table == ERR_READ_DATA || *table == ERR_CLOSE_FILE)
		return *table;

	// run algorithm and receive its duration time
	std::chrono::duration<double> diff = algorithm(table, searched_number, is_found);

	// write results without table to file
	result = search_result_to_write(output_file, diff.count());
	if (result)
		return result;

	free(table);

	return is_found ? SUCCESS :  SEARCH_FAIL;
}

static inline void swap_xor_table(int32_t &a, int32_t &b) {
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

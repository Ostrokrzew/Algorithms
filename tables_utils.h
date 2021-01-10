#ifndef ENGINEERPROJECT_TABLES_UTILS_H
#define ENGINEERPROJECT_TABLES_UTILS_H

#include "headers.h"

static int32_t* read_to_table(const char *input_file) {
    int32_t *return_ptr = (int32_t *)zmalloc(sizeof(int32_t) * AMOUNT);

    //open the file with generated data to sort for read
    FILE *input = fopen(input_file, "r");
    if (!input) {
        *return_ptr = ERR_OPEN_FILE;
        return return_ptr;
    }

    //read input file to table
    char *line = (char *)zmalloc(sizeof(char));
    size_t len = 0;

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

static uint8_t table_to_write(const std::string &output_file, int32_t table[],
			      std::chrono::duration<double> diff) {
	//open the output file for write and clear its content
	std::ofstream output;
	output.open(output_file, std::ofstream::trunc);
	if (!output.is_open())
		return ERR_OPEN_FILE;

	output << "duration: " << diff.count() << " s\n" << std::endl;

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

static uint8_t search_result_to_write(const std::string &output_file, std::chrono::duration<double> diff) {
	//open the output file for write and clear its content
	std::ofstream output;
	output.open(output_file, std::ofstream::trunc);
	if (!output.is_open())
		return ERR_OPEN_FILE;

	output << "duration: " << diff.count() << " s" << std::endl;

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

	// run algorithm and receive its duration time
	std::chrono::duration<double> diff = algorithm(table);

	result = validate_order(table);
	if (result)
		goto error;

	// write results to file
	result = table_to_write(output_file, table, diff);

error:
	free(table);

	return result;
}

static uint8_t execute_search_algorithm_on_table(const char *input_file, const std::string &output_file,
						 const int32_t searched_number, std::chrono::duration<double> (*algorithm)(int32_t[], const int32_t, bool&)
) {
	uint8_t result;
	bool is_found = false;
	//open the file with generated data to sort for read
	int32_t *table = read_to_table(input_file);

	// run algorithm and receive its duration time
	std::chrono::duration<double> diff = algorithm(table, searched_number, is_found);

	// write results without table to file
	result = search_result_to_write(output_file, diff);
	if (result)
		return result;

	free(table);

	return is_found ? SUCCESS :  SEARCH_FAIL;
}

#endif //ENGINEERPROJECT_TABLES_UTILS_H

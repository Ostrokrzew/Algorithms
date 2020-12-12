#ifndef ENGINEERPROJECT_UTILS_H
#define ENGINEERPROJECT_UTILS_H

#include "structures.h"

//amount of numbers randomly generated
#define AMOUNT (262144/4)

//change numeric types to faster versions
#define uint8_t uint_fast8_t
#define uint16_t uint_fast16_t
#define uint32_t uint_fast32_t
#define uint64_t uint_fast64_t
#define int8_t int_fast8_t
#define int16_t int_fast16_t
#define int32_t int_fast32_t
#define int64_t int_fast64_t


static void* zmalloc(size_t size) {
    void *ptr = malloc(size);
    memset(ptr, 0, size);
    return ptr;
}

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
        *(return_ptr + i) = atoll(line);
    }
    free(line);

    //close input file
    if (fclose(input)) {
        *return_ptr = ERR_CLOSE_FILE;
        return return_ptr;
    }

    return return_ptr;
}

static void fill_one_way_node(node_single_t head, uint32_t line) {
    node_single_t current_node = head;
    while (current_node->next != NULL)
        current_node = current_node->next;

    current_node->next = (node_single_t)zmalloc(sizeof(node_single));
    current_node->value = line;
    current_node->next->value = NULL;
    current_node->next->next = NULL;
}

static uint8_t read_to_one_way_list(const char *input_file) {
    node_single_t node = (node_single_t)zmalloc(sizeof(node_single));
    node->value = NULL;
    node->next = NULL;

    //open the file with generated data to sort for read
    FILE *input = fopen(input_file, "r");
    if (!input) {
        return ERR_OPEN_FILE;
    }

    //read input file to table
    char *line = (char *)zmalloc(sizeof(char));
    size_t len = 0;

    for (size_t i = 0; i < AMOUNT; i++) {
        if (getline(&line, &len, input) == -1) {
            free(line);
            return ERR_READ_DATA;
        }
        fill_one_way_node(node, atoll(line));
    }
    free(line);

    //close input file
    if (fclose(input)) {
        return ERR_CLOSE_FILE;
    }

    return SUCCESS;
}

static void fill_two_way_node(node_double_t head, uint32_t line) {
    node_double_t current_node = head;
    while (current_node->next != NULL)
        current_node = current_node->next;

    current_node->next = (node_double_t)zmalloc(sizeof(node_double));
    current_node->value = line;
    current_node->next->prev = current_node;
    current_node->next->next = NULL;
}

static uint8_t read_to_two_way_list(const char *input_file) {
    node_double_t node = (node_double_t)zmalloc(sizeof(node_double));
    node->prev = NULL;
    node->next = NULL;

    //open the file with generated data to sort for read
    FILE *input = fopen(input_file, "r");
    if (!input) {
        return ERR_OPEN_FILE;
    }

    //read input file to table
    char *line = (char *)zmalloc(sizeof(char));
    size_t len = 0;

    for (size_t i = 0; i < AMOUNT; i++) {
        if (getline(&line, &len, input) == -1) {
            free(line);
            return ERR_READ_DATA;
        }
        fill_two_way_node(node, atoll(line));
    }
    free(line);

    //close input file
    if (fclose(input)) {
        return ERR_CLOSE_FILE;
    }

    return SUCCESS;
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

	output << "duration: " << diff.count() << " s\n" << std::endl;

	//close output file
	output.close();
	if (output.is_open())
		return ERR_CLOSE_FILE;

	return SUCCESS;
}

static inline void swap_xor(int32_t &a, int32_t &b) {
    if (a == b)
        return;
    a ^= b;
    b ^= a;
    a ^= b;
}

static void swap_tmp(long &a, long &b) {
    long tmp = a;
    a = b;
    b = tmp;
}

static uint8_t validate_order(const char *input_file) {
    uint8_t result = SUCCESS;
    int32_t *table = read_to_table(input_file);
    for (size_t i = 0; i < AMOUNT-1; i++) {
        if (*table > *(table + 1)) {
            fprintf(stderr, "%ld should be greater or equal %ld.\n", *(table + 1), *table);
            result = ERR_WRG_ORDR;
        }
    }
    free(table);

    return result;
}

static uint8_t execute_sort_algorithm_on_table(const char *input_file, const std::string &output_file,
					       std::chrono::duration<double> (*algorithm)(int32_t[])) {
	uint8_t result;
	//open the file with generated data to sort for read
	int32_t *table = read_to_table(input_file);

	// run algorithm and receive its duration time
	std::chrono::duration<double> diff = algorithm(table);

	// write results to file
	result = table_to_write(output_file, table, diff);
	if (result)
		return result;

	free(table);

	return SUCCESS;
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

#endif //ENGINEERPROJECT_UTILS_H

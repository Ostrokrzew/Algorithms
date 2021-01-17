#ifndef ENGINEERPROJECT_STRUCTURES_H
#define ENGINEERPROJECT_STRUCTURES_H

#include "headers.h"

typedef struct list {
	i32 value;
	struct list *next;
} list_node;

typedef list_node *list_node_t;

static inline list_node_t init_list_node() {
	auto node = (list_node_t)zmalloc(sizeof(list_node));
	node->value = NULL;
	node->next = nullptr;
	return node;
}

static inline void remove_lonely_node(list_node_t &node_to_remove) {
	free(node_to_remove);
	node_to_remove = nullptr;
}

static inline void remove_first_node(list_node_t &first_node) {
	list_node_t node_to_remove = first_node;
	first_node = node_to_remove->next;
	free(node_to_remove);
}

static inline void remove_last_node(list_node_t const &first_node) {
	list_node_t node = first_node;
	while (node->next->next != nullptr)
		node = node->next;
	free(node->next);
	node->next = nullptr;
}

static inline void remove_internal_node(list_node_t const &first_node, list_node_t node_to_remove) {
	list_node_t current_node = first_node;
	while (current_node->next != node_to_remove)
		current_node = current_node->next;
	current_node->next = node_to_remove->next;
	free(node_to_remove);
}

static inline void remove_list_node(list_node_t &first_node, list_node_t &node_to_remove) {
	if (node_to_remove == nullptr)
		return;
	if (first_node == node_to_remove) {
		if (first_node->next == nullptr)
			remove_lonely_node(first_node);
		else
			remove_first_node(first_node);
	} else {
		if (node_to_remove->next == nullptr)
			remove_last_node(first_node);
		else
			remove_internal_node(first_node, node_to_remove);
	}
}

static inline void remove_all_nodes(list_node_t &first_node) {
	while (first_node != nullptr)
		remove_list_node(first_node, first_node);
}

static inline void set_first_list_node(list_node_t const &first_node, u32 value) {
	first_node->value = value;
}

static inline void set_internal_list_node(list_node_t const &first_node, list_node_t node_to_set, u32 value) {
	list_node_t current_node = first_node;
	while (current_node != node_to_set)
		current_node = current_node->next;

	current_node->value = value;
}

static inline void set_last_list_node(list_node_t const &first_node, u32 value) {
	list_node_t current_node = first_node;
	while (current_node->next != nullptr)
		current_node = current_node->next;

	current_node->value = value;
}

static inline void set_list_node(list_node_t const &first_node, list_node_t &node_to_set, u32 value) {
	if (first_node == node_to_set) {
		set_first_list_node(first_node, value);
	} else {
		if (node_to_set->next == nullptr)
			set_last_list_node(first_node, value);
		else
			set_internal_list_node(first_node, node_to_set, value);
	}
}

typedef struct metalist {
	list_node_t head;
	list_node_t tail;
	u32 counter;
} list_controler;

typedef list_controler *list_controler_t;

static inline list_controler_t init_metalist() {
	auto metalist = (list_controler_t)zmalloc(sizeof(list_controler));
	metalist->head = nullptr;
	metalist->tail = nullptr;
	metalist->counter = 0;
	return metalist;
}

static inline void remove_head(list_controler_t &list_controler) {
	remove_first_node(list_controler->head);
	--list_controler->counter;
}

static inline void remove_tail(list_controler_t &list_controler) {
	free(list_controler->tail);
	list_controler->tail = nullptr;
	--list_controler->counter;
}

static inline void update_metalist(list_controler_t &list_controler, list_node_t const &first_node) {
	list_controler->head = first_node;
	list_controler->counter = 1;
	list_node_t current_node = first_node;
	while (current_node->next != nullptr) {
		current_node = current_node->next;
		++list_controler->counter;
	}
	list_controler->tail = current_node;
}

static u8 list_data_read(const char *input_file, list_node_t &first_node) {
	list_node_t current_node = first_node;

	//open the file with generated data to sort for read
	FILE *input = fopen(input_file, "r");
	if (!input) {
		return ERR_OPEN_FILE;
	}

	//read input file to table
	char *line = (char *)zmalloc(12 * sizeof(char));
	size_t len = 12;

	for (size_t i = 0; i < AMOUNT; i++) {
		if (getline(&line, &len, input) == -1) {
			free(line);
			return ERR_READ_DATA;
		}
		current_node->value = atol(line);
		current_node->next = init_list_node();
		current_node = current_node->next;
	}
	free(line);
	remove_list_node(first_node, current_node);

	//close input file
	if (fclose(input))
		return ERR_CLOSE_FILE;

	return SUCCESS;
}

static u8 list_sort_result_write(const std::string &output_file, list_node_t const &first_node, const double diff) {
	//open the output file for write and clear its content
	std::ofstream output;
	output.open(output_file, std::ofstream::trunc);
	if (!output.is_open())
		return ERR_OPEN_FILE;

	output << "duration: " << diff << " s\n" << std::endl;

	//save output to file
	list_node_t current_node = first_node;
	do {
		output << current_node->value << std::endl;
		current_node = current_node->next;
	} while (current_node != nullptr);

	//close output file
	output.close();
	if (output.is_open())
		return ERR_CLOSE_FILE;

	return SUCCESS;
}

static u8 list_search_result_write(const std::string &output_file, const double diff) {
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

static inline u8 validate_list_order(list_node_t const &first_node) {
	list_node_t prev_node = first_node, current_node;
	while (prev_node->next != nullptr) {
		current_node = prev_node->next;
		if (prev_node->value > current_node->value) {
			fprintf(stderr, "%ld should be greater or equal %ld.\n", current_node->value, prev_node->value);
			return ERR_WRG_ORDR;
		}
		prev_node = current_node;
	}

	return SUCCESS;
}

static u8 execute_sort_algorithm_on_list(const char *input_file, const std::string &output_file,
					      std::chrono::duration<double> (*algorithm)(list_node_t&)) {
	u8 result;
	list_node_t list = init_list_node();
	//open the file with generated data to sort for read
	result = list_data_read(input_file, list);
	if (result)
		return result;

	// run algorithm and receive its duration time
	std::chrono::duration<double> diff = algorithm(list);

	// write results to file
	result = list_sort_result_write(output_file, list, diff.count());
	if (result)
		goto error;

	result = validate_list_order(list);

error:
	remove_all_nodes(list);

	return result;
}

static u8 execute_search_algorithm_on_list(const char *input_file, const std::string &output_file,
						 const i32 searched_number, std::chrono::duration<double>
						         (*algorithm)(list_node_t&, const i32, bool&)
) {
	u8 result;
	list_node_t list = init_list_node();;
	bool is_found = false;
	//open the file with generated data to sort for read
	result = list_data_read(input_file, list);
	if (result)
		return result;

	// run algorithm and receive its duration time
	std::chrono::duration<double> diff = algorithm(list, searched_number, is_found);

	// write results without table to file
	result = list_search_result_write(output_file, diff.count());
	if (result)
		return result;

	remove_all_nodes(list);

	return is_found ? SUCCESS :  SEARCH_FAIL;
}


static inline void swap_xor_list(list_node_t &a, list_node_t &b) {
	if (a->value == b->value)
		return;
	a->value ^= b->value;
	b->value ^= a->value;
	a->value ^= b->value;
}

static void swap_tmp_list(list_node_t &a, list_node_t &b) {
	long tmp = a->value;
	a->value = b->value;
	b->value = tmp;
}

static int get_list_lenght(list_node_t first_node) {
	list_node_t current_node = first_node;
	int counter = 1;
	while (current_node->next != nullptr) {
		counter += 1;
		current_node = current_node->next;
	}
	return counter;
}

#endif //ENGINEERPROJECT_STRUCTURES_H

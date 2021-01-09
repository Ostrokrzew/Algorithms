#ifndef ENGINEERPROJECT_STRUCTURES_H
#define ENGINEERPROJECT_STRUCTURES_H

#include "headers.h"

typedef struct list {
	uint32_t value;
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
			remove_middle_node(first_node, node_to_remove);
	}
}

static inline void remove_all_nodes(list_node_t &first_node) {
	while (first_node != nullptr)
		remove_list_node(first_node, first_node);
}

static inline void set_first_list_node(list_node_t const &first_node, uint32_t value) {
	first_node->value = value;
}

static inline void set_internal_list_node(list_node_t const &first_node, list_node_t node_to_set, uint32_t value) {
	list_node_t current_node = first_node;
	while (current_node != node_to_set)
		current_node = current_node->next;

	current_node->value = value;
}

static inline void set_last_list_node(list_node_t const &first_node, uint32_t value) {
	list_node_t current_node = first_node;
	while (current_node->next != nullptr)
		current_node = current_node->next;

	current_node->value = value;
}

typedef struct metalist {
	list_node_t head;
	list_node_t tail;
	uint32_t counter;
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
	list_controler->head = current_node;
	list_controler->counter = 1;
	list_node_t current_node = first_node;
	while (current_node->next != nullptr) {
		current_node = current_node->next;
		++list_controler->counter;
	}
	list_controler->tail = current_node;
}

static uint8_t read_to_list(const char *input_file) {
	list_node_t node = init_list_node();

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
		node->value = atoll(line);
		node->next = init_list_node();
		node = node->next;
	}
	free(line);
	remove_list

	//close input file
	if (fclose(input))
		return ERR_CLOSE_FILE;

	return SUCCESS;
}


static inline void swap_xor_list(list_node &a, list_node &b) {
	if (a.value == b.value)
		return;
	a.value ^= b.value;
	b.value ^= a.value;
	a.value ^= b.value;
}

static void swap_tmp_list(list_node &a, list_node &b) {
	long tmp = a.value;
	a.value = b.value;
	b.value = tmp;
}

#endif //ENGINEERPROJECT_STRUCTURES_H

//#ifndef ENGINEERPROJECT_STRUCTURES_H
//#define ENGINEERPROJECT_STRUCTURES_H
//
//#include "headers.h"
//
//
///*** singly linked list ***/
//typedef struct list {
//	uint32_t value;
//	struct list *next;
//} list_node;
//
//typedef list_node *list_node_t;
//
//static void fill_one_way_node(list_node_t head, uint32_t line) {
//	list_node_t current_node = head;
//	while (current_node->next != NULL)
//		current_node = current_node->next;
//
//	current_node->next = (list_node_t)zmalloc(sizeof(list_node));
//	current_node->value = line;
//	current_node->next->value = NULL;
//	current_node->next->next = NULL;
//}
//
//static uint8_t read_to_list(const char *input_file) {
//	list_node_t node = (list_node_t)zmalloc(sizeof(list_node));
//	node->value = NULL;
//	node->next = NULL;
//
//	//open the file with generated data to sort for read
//	FILE *input = fopen(input_file, "r");
//	if (!input) {
//		return ERR_OPEN_FILE;
//	}
//
//	//read input file to table
//	char *line = (char *)zmalloc(sizeof(char));
//	size_t len = 0;
//
//	for (size_t i = 0; i < AMOUNT; i++) {
//		if (getline(&line, &len, input) == -1) {
//			free(line);
//			return ERR_READ_DATA;
//		}
//		fill_one_way_node(node, atoll(line));
//	}
//	free(line);
//
//	//close input file
//	if (fclose(input))
//		return ERR_CLOSE_FILE;
//
//	return SUCCESS;
//}
//
//#endif //ENGINEERPROJECT_STRUCTURES_H

//#ifndef ENGINEERPROJECT_STRUCTURES_H
//#define ENGINEERPROJECT_STRUCTURES_H
//
//#include "headers.h"
//
//
///*** singly linked list ***/
//typedef struct one_way_list {
//	uint32_t value;
//	struct one_way_list *next;
//} node_single;
//
//typedef node_single *node_single_t;
//
//static void fill_one_way_node(node_single_t head, uint32_t line) {
//	node_single_t current_node = head;
//	while (current_node->next != NULL)
//		current_node = current_node->next;
//
//	current_node->next = (node_single_t)zmalloc(sizeof(node_single));
//	current_node->value = line;
//	current_node->next->value = NULL;
//	current_node->next->next = NULL;
//}
//
//static uint8_t read_to_one_way_list(const char *input_file) {
//	node_single_t node = (node_single_t)zmalloc(sizeof(node_single));
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
///*** doubly linked list ***/
//typedef struct two_way_list {
//	struct two_way_list *prev;
//	uint32_t value;
//	struct two_way_list *next;
//} node_double;
//
//typedef node_double *node_double_t;
//
//static void fill_two_way_node(node_double_t head, uint32_t line) {
//	node_double_t current_node = head;
//	while (current_node->next != NULL)
//		current_node = current_node->next;
//
//	current_node->next = (node_double_t)zmalloc(sizeof(node_double));
//	current_node->value = line;
//	current_node->next->prev = current_node;
//	current_node->next->next = NULL;
//}
//
//static uint8_t read_to_two_way_list(const char *input_file) {
//	node_double_t node = (node_double_t)zmalloc(sizeof(node_double));
//	node->prev = NULL;
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
//		fill_two_way_node(node, atoll(line));
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
///*** binary tree ***/
//typedef struct binary_tree {
//	struct two_way_list *parent;
//	uint32_t value;
//	struct two_way_list *left;
//	struct two_way_list *right;
//} binary_node;
//
//typedef binary_node *binary_node_t;
//
//static binary_node_t init_node() {
//	binary_node_t first_node = (binary_node_t)zmalloc(sizeof(binary_node));
//	first_node->parent = NULL;
//	first_node->value = 0;
//	first_node->left = NULL;
//	first_node->right = NULL;
//	return first_node;
//}
//
//static void add_left_leaf(binary_node_t root, uint32_t value) {
//	binary_node_t left_node = init_node();
//	root->left = left_node;
//	left_node->parent = root;
//	left_node->value = value;
//}
//
//static void add_right_leaf(binary_node_t root, uint32_t value) {
//	binary_node_t right_node = init_node();
//	root->right = right_node;
//	right_node->parent = root;
//	right_node->value = value;
//}
//
//static void delete_lonely_node(binary_node_t node) {
//	free(node);
//}
//
//static void delete_none_parent_two_childs_node(binary_node_t node) {
//	binary_node_t curr_node = node->left;
//	while (curr_node->right != NULL)
//		curr_node = curr_node->right;
//	curr_node->right = node->right;
//	node->right->parent = curr_node;
//	free(node);
//}
//
//static void delete_none_parent_left_child_node(binary_node_t node) {
//	node->left->parent = NULL;
//	free(node);
//}
//
//static void delete_none_parent_right_child_node(binary_node_t node) {
//	node->right->parent = NULL;
//	free(node);
//}
//
//static void delete_left_parent_none_childs_node(binary_node_t node) {
//	node->parent->right = NULL;
//	free(node);
//}
//
//static void delete_right_parent_none_childs_node(binary_node_t node) {
//	node->parent->left = NULL;
//	free(node);
//}
//
//static void delete_left_parent_two_childs_node(binary_node_t node) {
//	node->parent->right = node->left;
//	node->left->parent = node->parent;
//	delete_none_parent_two_childs_node(node);
//}
//
//static void delete_right_parent_two_childs_node(binary_node_t node) {
//	node->parent->left = node->left;
//	node->left->parent = node->parent;
//	delete_none_parent_two_childs_node(node);
//}
//
//static void delete_left_parent_left_child_node(binary_node_t node) {
//	node->parent->right = node->left;
//	node->left->parent = node->parent;
//	free(node);
//}
//
//static void delete_right_parent_left_child_node(binary_node_t node) {
//	node->parent->left = node->left;
//	node->left->parent = node->parent;
//	free(node);
//}
//
//static void delete_left_parent_right_child_node(binary_node_t node) {
//	node->parent->right = node->right;
//	node->right->parent = node->parent;
//	free(node);
//}
//
//static void delete_right_parent_right_child_node(binary_node_t node) {
//	node->parent->left = node->right;
//	node->right->parent = node->parent;
//	free(node);
//}
//
//static void delete_tree_node(binary_node_t node) {
//	if (node->parent == NULL) {
//		if (node->left == NULL && node->right == NULL) {
//			delete_lonely_node(node);
//		} else if (node->parent == NULL && node->left != NULL && node->right == NULL) {
//			delete_none_parent_left_child_node(node);
//		} else if (node->parent == NULL && node->left == NULL && node->right != NULL) {
//			delete_none_parent_right_child_node(node);
//		} else if (node->parent == NULL && node->left != NULL && node->right != NULL) {
//			delete_none_parent_two_childs_node(node);
//		}
//	} else {
//		if (node->left == NULL && node->right == NULL) {
//			if (node->parent->right == node)
//				delete_left_parent_none_childs_node(node);
//			if (node->parent->left == node)
//				delete_right_parent_none_childs_node(node);
//		}
//		else if (node->left != NULL && node->right == NULL) {
//			if (node->parent->right == node)
//				delete_left_parent_left_child_node(node);
//			if (node->parent->left == node)
//				delete_right_parent_left_child_node(node);
//		}
//		else if (node->left == NULL && node->right != NULL) {
//			if (node->parent->right == node)
//				delete_left_parent_right_child_node(node);
//			if (node->parent->left == node)
//				delete_right_parent_right_child_node(node);
//		}
//		else if (node->left != NULL && node->right != NULL){
//			if (node->parent->right == node)
//				delete_left_parent_two_childs_node(node);
//			if (node->parent->left == node)
//				delete_right_parent_two_childs_node(node)
//		}
//	}
//}
//
//static void delete_all_tree_nodes(binary_node_t *tree) {
//	while (tree != NULL)
//		delete_tree_node(*tree)
//}
//
//static void add_tree_node(binary_node_t root, uint32_t value) {
//	binary_node_t current_node = root;
//	while(true) {
//		if (current_node->left != NULL && current_node->right != NULL) {
//			if (current_node->right->left == NULL || current_node->right->right == NULL)
//				current_node = current_node->right;
//			else if (current_node->left->left == NULL || current_node->left->right == NULL)
//				current_node = current_node->left;
//		} else if (current_node->left == NULL && current_node->right == NULL) {
//			add_left_leaf(current_node, value);
//			break;
//		} else if (current_node->left == NULL && current_node->right != NULL) {
//			add_left_leaf(current_node, value);
//			break;
//		} else if (current_node->left != NULL && current_node->right == NULL) {
//			add_right_leaf(current_node, value);
//			break;
//		}
//	}
//}
//
//static uint8_t read_to_tree(const char *input_file) {
//	binary_node_t node = (binary_node_t)zmalloc(sizeof(binary_node));
//	node->parent = NULL;
//	node->left = NULL;
//	node->right = NULL;
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
//		fill_tree_node(node, atoll(line));
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

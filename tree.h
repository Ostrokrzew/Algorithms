#ifndef ENGINEERPROJECT_TREE_H
#define ENGINEERPROJECT_TREE_H

#include "headers.h"

typedef struct binary_tree {
	struct binary_tree *parent;
	uint32_t value;
	struct binary_tree *left;
	struct binary_tree *right;
} binary_node;

typedef binary_node *binary_node_t;

static binary_node_t init_node() {
	auto first_node = (binary_node_t)zmalloc(sizeof(binary_node));
	first_node->parent = nullptr;
	first_node->value = 0;
	first_node->left = nullptr;
	first_node->right = nullptr;
	return first_node;
}

static void add_left_leaf(binary_node_t root, uint32_t value) {
	binary_node_t left_node = init_node();
	root->left = left_node;
	left_node->parent = root;
	left_node->value = value;
}

static void add_right_leaf(binary_node_t root, uint32_t value) {
	binary_node_t right_node = init_node();
	root->right = right_node;
	right_node->parent = root;
	right_node->value = value;
}

static void delete_lonely_node(binary_node_t node) {
	free(node);
}

static void delete_none_parent_two_childs_node(binary_node_t node) {
	binary_node_t curr_node = node->left;
	while (curr_node->right != nullptr)
		curr_node = curr_node->right;
	curr_node->right = node->right;
	node->right->parent = curr_node;
	free(node);
}

static void delete_none_parent_left_child_node(binary_node_t node) {
	node->left->parent = nullptr;
	free(node);
}

static void delete_none_parent_right_child_node(binary_node_t node) {
	node->right->parent = nullptr;
	free(node);
}

static void delete_left_parent_none_childs_node(binary_node_t node) {
	node->parent->right = nullptr;
	free(node);
}

static void delete_right_parent_none_childs_node(binary_node_t node) {
	node->parent->left = nullptr;
	free(node);
}

static void delete_left_parent_two_childs_node(binary_node_t node) {
	node->parent->right = node->left;
	node->left->parent = node->parent;
	delete_none_parent_two_childs_node(node);
}

static void delete_right_parent_two_childs_node(binary_node_t node) {
	node->parent->left = node->left;
	node->left->parent = node->parent;
	delete_none_parent_two_childs_node(node);
}

static void delete_left_parent_left_child_node(binary_node_t node) {
	node->parent->right = node->left;
	node->left->parent = node->parent;
	free(node);
}

static void delete_right_parent_left_child_node(binary_node_t node) {
	node->parent->left = node->left;
	node->left->parent = node->parent;
	free(node);
}

static void delete_left_parent_right_child_node(binary_node_t node) {
	node->parent->right = node->right;
	node->right->parent = node->parent;
	free(node);
}

static void delete_right_parent_right_child_node(binary_node_t node) {
	node->parent->left = node->right;
	node->right->parent = node->parent;
	free(node);
}

static void delete_tree_node(binary_node_t node) {
	if (node->parent == nullptr) {
		if (node->left == nullptr && node->right == nullptr) {
			delete_lonely_node(node);
		} else if (node->parent == nullptr && node->left != nullptr && node->right == nullptr) {
			delete_none_parent_left_child_node(node);
		} else if (node->parent == nullptr && node->left == nullptr && node->right != nullptr) {
			delete_none_parent_right_child_node(node);
		} else if (node->parent == nullptr && node->left != nullptr && node->right != nullptr) {
			delete_none_parent_two_childs_node(node);
		}
	} else {
		if (node->left == nullptr && node->right == nullptr) {
			if (node->parent->right == node)
				delete_left_parent_none_childs_node(node);
			if (node->parent->left == node)
				delete_right_parent_none_childs_node(node);
		}
		else if (node->left != nullptr && node->right == nullptr) {
			if (node->parent->right == node)
				delete_left_parent_left_child_node(node);
			if (node->parent->left == node)
				delete_right_parent_left_child_node(node);
		}
		else if (node->left == nullptr && node->right != nullptr) {
			if (node->parent->right == node)
				delete_left_parent_right_child_node(node);
			if (node->parent->left == node)
				delete_right_parent_right_child_node(node);
		}
		else if (node->left != nullptr && node->right != nullptr){
			if (node->parent->right == node)
				delete_left_parent_two_childs_node(node);
			if (node->parent->left == node)
				delete_right_parent_two_childs_node(node)
		}
	}
}

static void delete_all_tree_nodes(binary_node_t *tree) {
	while (tree != nullptr)
		delete_tree_node(*tree)
}

static void add_tree_node(binary_node_t root, uint32_t value) {
	binary_node_t current_node = root;
	while(true) {
		if (current_node->left != nullptr && current_node->right != nullptr) {
			if (current_node->right->left == nullptr || current_node->right->right == nullptr)
				current_node = current_node->right;
			else if (current_node->left->left == nullptr || current_node->left->right == nullptr)
				current_node = current_node->left;
		} else if (current_node->left == nullptr && current_node->right == nullptr) {
			add_left_leaf(current_node, value);
			break;
		} else if (current_node->left == nullptr && current_node->right != nullptr) {
			add_left_leaf(current_node, value);
			break;
		} else if (current_node->left != nullptr && current_node->right == nullptr) {
			add_right_leaf(current_node, value);
			break;
		}
	}
}

static uint8_t read_to_tree(const char *input_file) {
	binary_node_t node = init_node();

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
		fill_tree_node(node, atoll(line));
	}
	free(line);

	//close input file
	if (fclose(input))
		return ERR_CLOSE_FILE;

	return SUCCESS;
}

#endif //ENGINEERPROJECT_TREE_H

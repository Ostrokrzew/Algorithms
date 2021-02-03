#ifndef ENGINEERPROJECT_TREE_H
#define ENGINEERPROJECT_TREE_H

#include "headers.h"

typedef struct binary_tree {
	struct binary_tree *parent;
	i32 value;
	struct binary_tree *left;
	struct binary_tree *right;
} binary_node;

typedef binary_node *binary_node_t;

static binary_node_t init_tree_node() {
	auto first_node = (binary_node_t)zmalloc(sizeof(binary_node));
	first_node->parent = nullptr;
	first_node->value = NULL;
	first_node->left = nullptr;
	first_node->right = nullptr;
	return first_node;
}

static void add_left_leaf(binary_node_t &root, u32 value) {
	binary_node_t left_node = init_tree_node();
	root->left = left_node;
	left_node->parent = root;
	left_node->value = value;
}

static void add_right_leaf(binary_node_t &root, u32 value) {
	binary_node_t right_node = init_tree_node();
	root->right = right_node;
	right_node->parent = root;
	right_node->value = value;
}

static void add_parent(binary_node_t &root, u32 value) {
	binary_node_t parent_node = init_tree_node();
	root->parent = parent_node;
	parent_node->left = root;
	parent_node->value = value;
	root = parent_node->right;
}

static void delete_lonely_node(binary_node_t &node) {
	free(node);
}

static void delete_none_parent_two_children_node(binary_node_t &node) {
	binary_node_t curr_node = node->left;
	while (curr_node->right != nullptr)
		curr_node = curr_node->right;
	curr_node->right = node->right;
	node->right->parent = curr_node;
	free(node);
}

static void delete_none_parent_left_child_node(binary_node_t &node) {
	node->left->parent = nullptr;
	free(node);
}

static void delete_none_parent_right_child_node(binary_node_t &node) {
	node->right->parent = nullptr;
	free(node);
}

static void delete_left_parent_none_children_node(binary_node_t &node) {
	node->parent->right = nullptr;
	free(node);
}

static void delete_right_parent_none_children_node(binary_node_t &node) {
	node->parent->left = nullptr;
	free(node);
}

static void delete_left_parent_two_children_node(binary_node_t &node) {
	node->parent->right = node->left;
	node->left->parent = node->parent;
	delete_none_parent_two_children_node(node);
}

static void delete_right_parent_two_children_node(binary_node_t &node) {
	node->parent->left = node->left;
	node->left->parent = node->parent;
	delete_none_parent_two_children_node(node);
}

static void delete_left_parent_left_child_node(binary_node_t &node) {
	node->parent->right = node->left;
	node->left->parent = node->parent;
	free(node);
}

static void delete_right_parent_left_child_node(binary_node_t &node) {
	node->parent->left = node->left;
	node->left->parent = node->parent;
	free(node);
}

static void delete_left_parent_right_child_node(binary_node_t &node) {
	node->parent->right = node->right;
	node->right->parent = node->parent;
	free(node);
}

static void delete_right_parent_right_child_node(binary_node_t &node) {
	node->parent->left = node->right;
	node->right->parent = node->parent;
	free(node);
}

static void delete_tree_node(binary_node_t &node) {
	if (node->parent == nullptr) {
		if (node->left == nullptr && node->right == nullptr) {
			delete_lonely_node(node);
		} else if (node->left != nullptr && node->right == nullptr) {
			delete_none_parent_left_child_node(node);
		} else if (node->left == nullptr && node->right != nullptr) {
			delete_none_parent_right_child_node(node);
		} else if (node->left != nullptr && node->right != nullptr) {
			delete_none_parent_two_children_node(node);
		}
	} else {
		if (node->left == nullptr && node->right == nullptr) {
			if (node->parent->right == node)
				delete_left_parent_none_children_node(node);
			if (node->parent->left == node)
				delete_right_parent_none_children_node(node);
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
				delete_left_parent_two_children_node(node);
			if (node->parent->left == node)
				delete_right_parent_two_children_node(node);
		}
	}
}

static void delete_all_tree_nodes(binary_node_t &root) {
	if (root == nullptr)
		return;
	delete_all_tree_nodes(root->left);
	delete_all_tree_nodes(root->right);
}

static void add_tree_node(binary_node_t &root, const u32 value) {
	if (root == nullptr) {
		root = init_tree_node();
		root->value = value;
	} else if (root->value < value)
		add_tree_node(root->left, value);
	else
		add_tree_node(root->right, value);
}

static u8 tree_data_read(const char *input_file, binary_node_t &root) {
	//open the file with generated data to sort for read
	FILE *input = fopen(input_file, "r");
	if (!input) {
		return ERR_OPEN_FILE;
	}

	//read input file to table
	auto line = (char *)zmalloc(12 * sizeof(char));
	size_t len = 12;

	for (size_t i = 0; i < AMOUNT; i++) {
		if (getline(&line, &len, input) == -1) {
			free(line);
			return ERR_READ_DATA;
		}
		add_tree_node(root, atol(line));
	}
	free(line);

	//close input file
	if (fclose(input))
		return ERR_CLOSE_FILE;

	return SUCCESS;
}

static u8 tree_search_result_write(const std::string &output_file, const double diff) {
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

static u8 execute_search_algorithm_on_tree(const char *input_file, const std::string &output_file,
					   const i32 searched_number, std::chrono::duration<double>
					   (*algorithm)(binary_node_t const&, const i32, bool&)) {
	u8 result;
	binary_node_t root = nullptr;
	bool is_found = false;
	//open the file with generated data to sort for read
	result = tree_data_read(input_file, root);
	if (result)
		return result;

	// run algorithm and receive its duration time
	std::chrono::duration<double> diff = algorithm(root, searched_number, is_found);

	// write results without table to file
	result = tree_search_result_write(output_file, diff.count());
	if (result)
		return result;

	delete_all_tree_nodes(root);

	return is_found ? SUCCESS : SEARCH_FAIL;
}

static inline u32 get_height(binary_node_t const &node) {
	if (node == nullptr)
		return 0;
	else {
		u32 left_height = get_height(node->left);
		u32 right_height = get_height(node->right);

		return left_height > right_height ? (left_height + 1) : (right_height + 1);
	}
}

#endif //ENGINEERPROJECT_TREE_H

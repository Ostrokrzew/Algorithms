#ifndef ENGINEERPROJECT_TREE_ALGORITHMS_H
#define ENGINEERPROJECT_TREE_ALGORITHMS_H

#include "tree.h"

std::chrono::duration<double> tree_search_depth(struct binary_tree*&, long, bool&);
void tree_search_dpth(struct binary_tree*, long, bool&);

std::chrono::duration<double> tree_search_breadth(struct binary_tree*&, long, bool&);
void tree_search_brdth(struct binary_tree*, long, bool&);
void tree_search_traverse(struct binary_tree*, int, long, bool&);

#endif //ENGINEERPROJECT_TREE_ALGORITHMS_H

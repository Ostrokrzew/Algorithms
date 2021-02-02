#ifndef ENGINEERPROJECT_TREE_ALGORITHMS_REFACTORED_H
#define ENGINEERPROJECT_TREE_ALGORITHMS_REFACTORED_H

#include "tree.h"

std::chrono::duration<double> tree_search_depth_rfctrd(struct binary_tree* const&, const i32, bool&);
inline void tree_search_dpth_rfctrd(struct binary_tree* const&, const i32, bool&);

std::chrono::duration<double> tree_search_breadth_rfctrd(struct binary_tree* const&, const i32, bool&);
inline void tree_search_brdth_rfctrd(struct binary_tree* const&, const i32, bool&);
inline void tree_search_traverse_rfctrd(struct binary_tree* const&, size_t, const i32, bool&);

#endif //ENGINEERPROJECT_TREE_ALGORITHMS_REFACTORED_H

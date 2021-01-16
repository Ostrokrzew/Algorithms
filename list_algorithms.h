#ifndef ENGINEERPROJECT_LIST_ALGORITHMS_H
#define ENGINEERPROJECT_LIST_ALGORITHMS_H

#include "list.h"

std::chrono::duration<double> list_sort_bubble(list_node_t&);
void list_sort_bbl(list_node);

std::chrono::duration<double> list_sort_heap(list_node_t&);
void list_sort_hp(list_node);
void list_restore(list_node);

std::chrono::duration<double> list_sort_insertion(list_node_t&);
void list_sort_insrt(list_node, int);

std::chrono::duration<double> list_sort_merge(list_node_t&);
void list_sort_mrg(list_node, int, int);
void list_merge(list_node, int, int, int);

std::chrono::duration<double> list_sort_quick(list_node_t&);
void list_sort_qck(list_node, int, int);

std::chrono::duration<double> list_sort_selection(list_node_t&);
void list_sort_slct(list_node, int);

std::chrono::duration<double> list_sort_shell(list_node_t&);
void list_sort_shl(list_node, int);

std::chrono::duration<double> list_sort_ciura(list_node_t&);
void list_sort_cr(list_node, int);

std::chrono::duration<double> list_search_linear(list_node_t&, long, bool&);
bool list_search_lnr(list_node, int, long);

std::chrono::duration<double> list_search_guardian(list_node_t&, long, bool&);
bool list_search_grd(list_node, int, long);

std::chrono::duration<double> list_search_binary(list_node_t&, long, bool&);
bool list_search_bnr(list_node, int, int, long);

std::chrono::duration<double> list_search_extrema(list_node_t&, long, bool&);
long list_search_max(list_node, int);
long list_search_min(list_node, int);

#endif //ENGINEERPROJECT_LIST_ALGORITHMS_H

#ifndef ENGINEERPROJECT_LIST_ALGORITHMS_H
#define ENGINEERPROJECT_LIST_ALGORITHMS_H

#include "list.h"

std::chrono::duration<double> list_sort_bubble(list_node_t);
void list_sort_bbl(list_node_t);

std::chrono::duration<double> list_sort_heap(list_node_t);
void list_sort_hp(list_node_t);
void list_restore(list_node_t)

std::chrono::duration<double> guardiansearch_prerefactored(long[], long, bool&);
bool grdsearch_prerefactored(long[], int, long);

std::chrono::duration<double> maxminsearch_prerefactored(long[], long, bool&);
long maxsearch_prerefactored(long[], int);
long minsearch_prerefactored(long[], int);


#endif //ENGINEERPROJECT_LIST_ALGORITHMS_H

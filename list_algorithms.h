#ifndef ENGINEERPROJECT_LIST_ALGORITHMS_H
#define ENGINEERPROJECT_LIST_ALGORITHMS_H

#include "list.h"

std::chrono::duration<double> list_sort_bubble(struct list*&);
struct list* list_sort_bbl(struct list*);

std::chrono::duration<double> list_sort_insertion(struct list*&);
struct list* list_sort_insrt(struct list*);
void list_sort_insert(struct list*&, struct list*&);

std::chrono::duration<double> list_sort_merge(struct list*&);
void list_sort_mrg(struct list*&, int, int);
struct list* list_merge(struct list*, int, int, int);

std::chrono::duration<double> list_sort_quick(struct list*&);
struct list* list_sort_qck(struct list*);
struct list* list_recursion(struct list*, struct list*);
struct list** list_split(struct list*, struct list*, struct list**);

std::chrono::duration<double> list_sort_selection(struct list*&);
struct list* list_sort_slct(struct list*);

std::chrono::duration<double> list_sort_shell(struct list*&);
struct list* list_sort_shl(struct list*, int);

std::chrono::duration<double> list_sort_ciura(struct list*&);
struct list* list_sort_cr(struct list*, int);

std::chrono::duration<double> list_search_linear(struct list*&, long, bool&);
bool list_search_lnr(struct list*, long);

std::chrono::duration<double> list_search_binary(struct list*&, long, bool&);
bool list_search_bnr(struct list*, int, int, long);

std::chrono::duration<double> list_search_extrema(struct list*&, long, bool&);
long list_search_max(struct list*);
long list_search_min(struct list*);

#endif //ENGINEERPROJECT_LIST_ALGORITHMS_H

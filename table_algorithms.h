#ifndef ENGINEERPROJECT_TABLE_ALGORITHMS_H
#define ENGINEERPROJECT_TABLE_ALGORITHMS_H

#include "tables_utils.h"

std::chrono::duration<double> table_sort_bubble(long[]);
void table_sort_bbl(long[], int);

std::chrono::duration<double> table_sort_heap(long[]);
void table_sort_hp(long[], int);
void table_restore(long[], int, int);

std::chrono::duration<double> table_sort_insertion(long[]);
void table_sort_insrt(long[], int);

std::chrono::duration<double> table_sort_merge(long[]);
void table_sort_mrg(long[], int, int);
void table_merge(long[], int, int, int);

std::chrono::duration<double> table_sort_quick(long[]);
void table_sort_qck(long[], int, int);

std::chrono::duration<double> table_sort_selection(long[]);
void table_sort_slct(long[], int);

std::chrono::duration<double> table_sort_shell(long[]);
void table_sort_shl(long[], int);

std::chrono::duration<double> table_sort_ciura(long[]);
void table_sort_cr(long[], int);

std::chrono::duration<double> table_search_linear(long[], long, bool&);
bool table_search_lnr(long[], int, long);

std::chrono::duration<double> table_search_binary(long[], long, bool&);
bool table_search_bnr(long[], int, int, long);

std::chrono::duration<double> table_search_extrema(long[], long, bool&);
long table_search_max(long[], int);
long table_search_min(long[], int);

#endif //ENGINEERPROJECT_TABLE_ALGORITHMS_H

#ifndef ENGINEERPROJECT_TABLE_ALGORITHMS_REFACTORED_H
#define ENGINEERPROJECT_TABLE_ALGORITHMS_REFACTORED_H

#include "tables_utils.h"

std::chrono::duration<double> table_sort_bubble_rfctrd(i32*);
inline void table_sort_bbl_rfctrd(i32*&, size_t);

std::chrono::duration<double> table_sort_heap_rfctrd(i32*);
inline void table_sort_hp_rfctrd(i32*&, size_t);
inline void table_restore_rfctrd(i32*&, size_t, size_t);

std::chrono::duration<double> table_sort_insertion_rfctrd(i32*);
inline void table_sort_insrt_rfctrd(i32*&, size_t);

std::chrono::duration<double> table_sort_merge_rfctrd(i32*);
inline void table_sort_mrg_rfctrd(i32*&, size_t, size_t);
inline void table_merge_rfctrd(i32*&, size_t, size_t, size_t);

std::chrono::duration<double> table_sort_quick_rfctrd(i32*);
inline void table_sort_qck_rfctrd(i32*&, size_t, size_t);

std::chrono::duration<double> table_sort_selection_rfctrd(i32*);
inline void table_sort_slct_rfctrd(i32*&, size_t);

std::chrono::duration<double> table_sort_shell_rfctrd(i32*);
inline void table_sort_shl_rfctrd(i32*&, size_t);

std::chrono::duration<double> table_sort_ciura_rfctrd(i32*);
inline void table_sort_cr_rfctrd(i32*&, size_t);

std::chrono::duration<double> table_search_linear_rfctrd(i32*, const i32, bool&);
inline bool table_search_lnr_rfctrd(i32*&, const size_t, const i32);

std::chrono::duration<double> table_search_binary_rfctrd(i32*, const i32, bool&);
inline bool table_search_bnr_rfctrd(i32*&, size_t, size_t, const i32);

std::chrono::duration<double> table_search_extrema_rfctrd(i32*, const i32, bool&);
inline void table_search_ext_rfctrd(i32*&, const size_t, i32&, i32&);

#endif //ENGINEERPROJECT_TABLE_ALGORITHMS_REFACTORED_H

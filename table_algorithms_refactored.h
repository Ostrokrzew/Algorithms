#ifndef ENGINEERPROJECT_TABLE_ALGORITHMS_REFACTORED_H
#define ENGINEERPROJECT_TABLE_ALGORITHMS_REFACTORED_H

#include "tables_utils.h"

std::chrono::duration<double> table_sort_bubble_rfctrd(int32_t[]);
inline void table_sort_bbl_rfctrd(int32_t[], size_t);

std::chrono::duration<double> table_sort_heap_rfctrd(int32_t[]);
inline void table_sort_hp_rfctrd(int32_t[], size_t);
inline void table_restore_rfctrd(int32_t[], size_t, size_t);

std::chrono::duration<double> table_sort_insertion_rfctrd(int32_t[]);
inline void table_sort_insrt_rfctrd(int32_t[], size_t);

std::chrono::duration<double> table_sort_merge_rfctrd(int32_t[]);
inline void table_sort_mrg_rfctrd(int32_t[], size_t, size_t);
inline void table_merge_rfctrd(int32_t[], size_t, size_t, size_t);

std::chrono::duration<double> table_sort_quick_rfctrd(int32_t[]);
inline void table_sort_qck_rfctrd(int32_t[], size_t, size_t);

std::chrono::duration<double> table_sort_selection_rfctrd(int32_t[]);
inline void table_sort_slct_rfctrd(int32_t[], size_t);

std::chrono::duration<double> table_sort_shell_rfctrd(int32_t[]);
inline void table_sort_shl_rfctrd(int32_t[], size_t);

std::chrono::duration<double> table_sort_ciura_rfctrd(int32_t[]);
inline void table_sort_cr_rfctrd(int32_t[], size_t);

std::chrono::duration<double> table_search_linear_rfctrd(int32_t[], const int32_t, bool&);
inline bool table_search_lnr_rfctrd(int32_t[], const size_t, const int32_t);

std::chrono::duration<double> table_search_guardian_rfctrd(int32_t[], const int32_t, bool&);
inline bool table_search_grd_rfctrd(int32_t[], const size_t, const int32_t);

std::chrono::duration<double> table_search_binary_rfctrd(int32_t[], const int32_t, bool&);
inline bool table_search_bnr_rfctrd(int32_t[], size_t, size_t, const int32_t);

std::chrono::duration<double> table_search_extrema_rfctrd(int32_t[], const int32_t, bool&);
inline void table_search_ext_rfctrd(int32_t[], const size_t, int32_t&, int32_t&);

#endif //ENGINEERPROJECT_TABLE_ALGORITHMS_REFACTORED_H

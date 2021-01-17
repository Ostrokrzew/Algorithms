#ifndef ENGINEERPROJECT_LIST_ALGORITHMS_REFACTORED_H
#define ENGINEERPROJECT_LIST_ALGORITHMS_REFACTORED_H

#include "list.h"

std::chrono::duration<double> list_sort_bubble_rfctrd(struct list*&);
inline void list_sort_bbl_rfctrd(struct list*&, size_t);

std::chrono::duration<double> list_sort_heap_rfctrd(struct list*&);
inline void list_sort_hp_rfctrd(struct list*&, size_t);
inline void list_restore_rfctrd(struct list*&, size_t, size_t);

std::chrono::duration<double> list_sort_insertion_rfctrd(struct list*&);
inline void list_sort_insrt_rfctrd(struct list*&, size_t);

std::chrono::duration<double> list_sort_merge_rfctrd(struct list*&);
inline void list_sort_mrg_rfctrd(struct list*&, size_t, size_t);
inline void list_merge_rfctrd(struct list*&, size_t, size_t, size_t);

std::chrono::duration<double> list_sort_quick_rfctrd(struct list*&);
inline void list_sort_qck_rfctrd(struct list*&, size_t, size_t);

std::chrono::duration<double> list_sort_selection_rfctrd(struct list*&);
inline void list_sort_slct_rfctrd(struct list*&, size_t);

std::chrono::duration<double> list_sort_shell_rfctrd(struct list*&);
inline void list_sort_shl_rfctrd(struct list*&, size_t);

std::chrono::duration<double> list_sort_ciura_rfctrd(struct list*&);
inline void list_sort_cr_rfctrd(struct list*&, size_t);

std::chrono::duration<double> list_search_linear_rfctrd(struct list*&, const int32_t, bool&);
inline bool list_search_lnr_rfctrd(struct list*&, const size_t, const int32_t);

std::chrono::duration<double> list_search_guardian_rfctrd(struct list*&, const int32_t, bool&);
inline bool list_search_grd_rfctrd(struct list*&, const size_t, const int32_t);

std::chrono::duration<double> list_search_binary_rfctrd(struct list*&, const int32_t, bool&);
inline bool list_search_bnr_rfctrd(struct list*&, size_t, size_t, const int32_t);

std::chrono::duration<double> list_search_extrema_rfctrd(struct list*&, const int32_t, bool&);
inline void list_search_ext_rfctrd(struct list*&, const size_t, int32_t&, int32_t&);

#endif //ENGINEERPROJECT_LIST_ALGORITHMS_REFACTORED_H

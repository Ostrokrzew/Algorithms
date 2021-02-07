#ifndef ENGINEERPROJECT_LIST_ALGORITHMS_REFACTORED_H
#define ENGINEERPROJECT_LIST_ALGORITHMS_REFACTORED_H

#include "list.h"

std::chrono::duration<double> list_sort_bubble_rfctrd(struct list*&);
inline void list_sort_bbl_rfctrd(struct list* const&, const size_t);

std::chrono::duration<double> list_sort_insertion_rfctrd(struct list*&);
inline void list_sort_insrt_rfctrd(struct list*&);
inline void list_sort_insert_rfctrd(struct metalist*&, struct list*&);

std::chrono::duration<double> list_sort_merge_rfctrd(struct list*&);
inline void list_sort_mrg_rfctrd(struct list*&);
inline void list_split_to_merge_rfctrd(struct list*, struct list*&, struct list*&);
inline struct list* list_merge_rfctrd(struct list*&, struct list*&);

std::chrono::duration<double> list_sort_quick_rfctrd(struct list*&);
inline void list_sort_qck_rfctrd(struct list*&);
inline struct list* list_recursion_rfctrd(struct list*, struct list*);
inline struct list* list_split_rfctrd(struct list*, struct list*, struct list*&, struct list*&);

std::chrono::duration<double> list_sort_selection_rfctrd(struct list*&);
inline void list_sort_slct_rfctrd(struct list* const&);

std::chrono::duration<double> list_sort_shell_rfctrd(struct list*&);
inline void list_sort_shl_rfctrd(struct list* const&, size_t);

std::chrono::duration<double> list_sort_ciura_rfctrd(struct list*&);
inline void list_sort_cr_rfctrd(struct list* const&, size_t);

std::chrono::duration<double> list_search_linear_rfctrd(struct list* const&, const i32, bool&);
inline bool list_search_lnr_rfctrd(struct list* const&, const i32);

std::chrono::duration<double> list_search_binary_rfctrd(struct list* const&, const i32, bool&);
inline bool list_search_bnr_rfctrd(struct list* const&, const i32);

std::chrono::duration<double> list_search_extrema_rfctrd(struct list* const&, const i32, bool&);
inline void list_search_ext_rfctrd(struct list* const&, i32&, i32&);

#endif //ENGINEERPROJECT_LIST_ALGORITHMS_REFACTORED_H

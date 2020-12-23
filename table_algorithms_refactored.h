#ifndef ENGINEERPROJECT_TABLE_ALGORITHMS_REFACTORED_H
#define ENGINEERPROJECT_TABLE_ALGORITHMS_REFACTORED_H

#include "tables_utils.h"

std::chrono::duration<double> bubblesort(int32_t[]);
inline void bblsort(int32_t[], size_t);

std::chrono::duration<double> heapsort(int32_t[]);
inline void hsort(int32_t[], size_t);
inline void restore(int32_t[], size_t, size_t);

std::chrono::duration<double> insertionsort(int32_t[]);
inline void inssort(int32_t[], size_t);

std::chrono::duration<double> mergesort(int32_t[]);
inline void msort(int32_t[], size_t, size_t);
inline void merge(int32_t[], size_t, size_t, size_t);

std::chrono::duration<double> quicksort(int32_t[]);
inline void qsort(int32_t[], size_t, size_t);

std::chrono::duration<double> selectionsort(int32_t[]);
inline void slctsort(int32_t[], size_t);

std::chrono::duration<double> shellsort(int32_t[]);
inline void shlsort(int32_t[], size_t);

std::chrono::duration<double> ciurassort(int32_t[]);
inline void crsort(int32_t[], size_t);

std::chrono::duration<double> linearsearch(int32_t[], const int32_t, bool&);
inline bool lnrsearch(int32_t[], const size_t, const int32_t);

std::chrono::duration<double> guardiansearch(int32_t[], const int32_t, bool&);
inline bool grdsearch(int32_t[], const size_t, const int32_t);

std::chrono::duration<double> binarysearch(int32_t[], const int32_t, bool&);
inline bool bnrsearch(int32_t[], size_t, size_t, const int32_t);

std::chrono::duration<double> maxminsearch(int32_t[], const int32_t, bool&);
inline void mxmnearch(int32_t[], const size_t, int32_t&, int32_t&);

#endif //ENGINEERPROJECT_TABLE_ALGORITHMS_REFACTORED_H

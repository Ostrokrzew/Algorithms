#ifndef ENGINEERPROJECT_TABLE_ALGORITHMS_H
#define ENGINEERPROJECT_TABLE_ALGORITHMS_H

#include "tables_utils.h"

std::chrono::duration<double> bubblesort_prerefactored(long[]);
void bblsort_prerefactored(long[], int);

std::chrono::duration<double> heapsort_prerefactored(long[]);
void hsort_prerefactored(long[], int);
void restore_prerefactored(long[], int, int);

std::chrono::duration<double> insertionsort_prerefactored(long[]);
void inssort_prerefactored(long[], int);

std::chrono::duration<double> mergesort_prerefactored(long[]);
void msort_prerefactored(long[], int, int);
void merge_prerefactored(long[], int, int, int);

std::chrono::duration<double> quicksort_prerefactored(long[]);
void qsort_prerefactored(long[], int, int);

std::chrono::duration<double> selectionsort_prerefactored(long[]);
void slctsort_prerefactored(long[], int);

std::chrono::duration<double> shellsort_prerefactored(long[]);
void shlsort_prerefactored(long[], int);

std::chrono::duration<double> ciurassort_prerefactored(long[]);
void crsort_prerefactored(long[], int);

std::chrono::duration<double> linearsearch_prerefactored(long[], long, bool&);
bool lnrsearch_prerefactored(long[], int, long);

std::chrono::duration<double> guardiansearch_prerefactored(long[], long, bool&);
bool grdsearch_prerefactored(long[], int, long);

std::chrono::duration<double> binarysearch_prerefactored(long[], long, bool&);
bool bnrsearch_prerefactored(long[], int, int, long);

std::chrono::duration<double> maxminsearch_prerefactored(long[], long, bool&);
long maxsearch_prerefactored(long[], int);
long minsearch_prerefactored(long[], int);

#endif //ENGINEERPROJECT_TABLE_ALGORITHMS_H

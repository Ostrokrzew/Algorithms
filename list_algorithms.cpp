#include "list_algorithms.h"

std::chrono::duration<double> linearsort_prerefactored(list_node_t first_node) {
    //start counting time
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

    //start sorting
    lnrsort_prerefactored(first_node);

    //stop counting time
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    //print sorting duration time
    std::chrono::duration<double> diff = end-start;
    fprintf(stdout, "Time to sort by bubblesort algorithm: "
                    "%f s\n", diff);

    //return duration time
    return diff;
}

void lnrsort_prerefactored(list_node_t first_node) {

}

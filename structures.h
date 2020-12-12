#ifndef ENGINEERPROJECT_LISTS_H
#define ENGINEERPROJECT_LISTS_H

#include "headers.h"

typedef struct one_way_list {
    uint32_t value;
    struct one_way_list *next;
} node_single, *node_single_t ;

typedef struct two_way_list {
    struct two_way_list *prev;
    uint32_t value;
    struct two_way_list *next;
} node_double, *node_double_t;

#endif //ENGINEERPROJECT_LISTS_H

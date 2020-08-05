#ifndef ZALG_DATA_TYPE_H
#define ZALG_DATA_TYPE_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct DataType {
    size_t size;
    void (*destroy)(void *object);
    void (*copy)(void *from, void *to);
    bool (*compare)(void *a, void *b);
} DataType;

#endif

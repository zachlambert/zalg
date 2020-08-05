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

void data_destroy(DataType *data_type, void *object);
void data_copy(DataType *data_type, void *from, void *to);
bool data_compare(DataType *data_type, void *a, void *b);

#endif

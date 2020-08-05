#ifndef ZALG_STRUCTURES_DYNAMIC_ARRAY_H
#define ZALG_STRUCTURES_DYNAMIC_ARRAY_H

#include <stdlib.h>
#include "data_type.h"


typedef struct {
    DataType data_type;
    size_t capacity;
    void *start;
    void *end;
} DynamicArray;

DynamicArray dynamic_array_create(size_t data_size);
void dynamic_array_add(DynamicArray *array, void *data);
void dynamic_array_remove(DynamicArray *array, size_t index);
void dynamic_array_destroy(DynamicArray *array);

#endif

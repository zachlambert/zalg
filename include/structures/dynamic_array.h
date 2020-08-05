#ifndef ZALG_STRUCTURES_DYNAMIC_ARRAY_H
#define ZALG_STRUCTURES_DYNAMIC_ARRAY_H

#include <stdlib.h>
#include "type.h"


typedef struct {
    Type *type;
    size_t capacity;
    void *start;
    void *end;
} DynamicArray;

DynamicArray dynamic_array_construct(Type *type);
void dynamic_array_add(DynamicArray *array, void *data);
void dynamic_array_remove(DynamicArray *array, size_t index);
void dynamic_array_destruct(DynamicArray *array);

#endif

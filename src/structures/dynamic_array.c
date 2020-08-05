#include "structures/dynamic_array.h"

#include <string.h>

// === Dynamic array ===

DynamicArray dynamic_array_construct(Type *type)
{
    return (DynamicArray){type, 0, 0, 0};
}

// Adds data to the end
// If there isn't enough memory, doubles the allocated memory
void dynamic_array_add(DynamicArray *array, void *data)
{
    if (!data) return;
    if (array->end - array->start == array->capacity * array->type->size) {
        if (array->capacity == 0) {
            array->capacity = 1;
        } else {
            array->capacity *= 2;
        }
        void *new_start = realloc(array->start, array->capacity);
        array->end = new_start + (array->end - array->start);
        array->start = new_start;
    }
    type_copy(array->type, data, array->end);
    array->end += array->type->size;
}

void dynamic_array_remove(DynamicArray *array, size_t index)
{
    if (index >= (array->end - array->start)/array->type->size) return;
    array->end -= array->type->size;
    type_assign(
        array->type,
        array->end,
        array->start + index * array->type->size
    );
    type_destruct(array->type, array->end);
}

void dynamic_array_destruct(DynamicArray *array)
{
    void *it;
    while (it != array->end) {
        type_destruct(array->type, it);
    }
    free(array->start);
}


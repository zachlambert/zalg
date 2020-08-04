#include "structures/dynamic_array.h"

#include <string.h>

// === Dynamic array ===

DynamicArray dynamic_array_create(size_t data_size)
{
    DynamicArray array = {data_size, 0, 0, 0};
    return array;
}

// Adds data to the end
// If there isn't enough memory, doubles the allocated memory
void dynamic_array_add(DynamicArray *array, void *data)
{
    if (!data) return;
    if (array->end - array->start == array->capacity * array->data_size) {
        if (array->capacity == 0) {
            array->capacity = 1;
        } else {
            array->capacity *= 2;
        }
        void *new_start = realloc(array->start, array->capacity);
        array->end = new_start + (array->end - array->start);
        array->start = new_start;
    }
    memcpy(array->end, data, array->data_size);
    array->end += array->data_size;
}

void dynamic_array_remove(DynamicArray *array, void *data)
{
    if (!data) return;
    array->end -= array->data_size;
    memcpy(data, array->end, array->data_size);
}

void dynamic_array_destroy(DynamicArray *array)
{
    free(array->start);
}


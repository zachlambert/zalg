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
    if (array->end - array->start == array->capacity * array->data_type.size) {
        if (array->capacity == 0) {
            array->capacity = 1;
        } else {
            array->capacity *= 2;
        }
        void *new_start = realloc(array->start, array->capacity);
        array->end = new_start + (array->end - array->start);
        array->start = new_start;
    }
    memcpy(array->end, data, array->data_type.size);
    array->end += array->data_type.size;
}

void dynamic_array_remove(DynamicArray *array, size_t index)
{
    if (index >= (array->end - array->start)/array->data_type.size) return;
    array->end -= array->data_type.size;
    array->data_type.copy(
        array->end,
        array->start + index * array->data_type.size
    );
    array->data_type.destroy(array->end);
}

void dynamic_array_destroy(DynamicArray *array)
{
    void *it;
    while (it != array->end) {
        array->data_type.destroy(it);
    }
    free(array->start);
}


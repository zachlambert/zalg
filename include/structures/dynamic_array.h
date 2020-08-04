#ifndef ZALG_STRUCTURES_DYNAMIC_ARRAY_H
#define ZALG_STRUCTURES_DYNAMIC_ARRAY_H


// ** Dynamically sized array (unordered) **
// Doubles in size when more memory is required
// Start pointer points to first item
// End pointer points to one-past the last item
// Add items to the end of the array
// When deleting an item, replaces it with the last item, so doesn't
// need a function to free the daya
// * If the data contains pointers to memory that has to be freed
//   the user has to free this memory before removing the data

#include <stdlib.h>

typedef struct {
    size_t data_size;
    size_t capacity;
    void *start;
    void *end;
} DynamicArray;

DynamicArray dynamic_array_create(size_t data_size);
void dynamic_array_add(DynamicArray *array, void *data);
void dynamic_array_remove(DynamicArray *array, void *data);
void dynamic_array_destroy(DynamicArray *array);

#endif

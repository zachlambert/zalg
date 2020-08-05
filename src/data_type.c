#include "data_type.h"

#include <string.h>


void data_destroy(DataType *data_type, void *object)
{
    if (data_type->destroy) {
        data_type->destroy(object);
    } else {
        free(object); // Free works with void pointers in C
    }
}

void data_copy(DataType *data_type, void *from, void *to)
{
    if (data_type->copy) {
        data_type->copy(from, to);
    } else {
        memcpy(from, to, data_type->size);
    }
}

bool data_compare(DataType *data_type, void *a, void *b) {
    if (data_type->compare) {
        return data_type->compare(a, b);
    } else {
        return false; // No sensible default
    }
}

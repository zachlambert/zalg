#ifndef ZALG_DATA_TYPE_H
#define ZALG_DATA_TYPE_H

#include <stdbool.h>
#include <stdlib.h>

// The Type struct only provides functions for managing and interpreting
// the data handled by a structure.
// It doesn't handle the pointers to the data (ie: malloc and free), but
// leaves that to the struture.

// size: Number of bytes the data type requires
// copy: Copy from an existing object, to a new piece of memory, assumed to
//       construct: just calls malloc to allocate memory to the type.
// destruct: If applicable, deallocates memory managed by the type.
// assign: Assign data to an existing object from another object.
// compare: Compare two objects.

// If using shallow types, copy and assign are just memcpy, and destruct
// does nothing. Otherwise, custom functions need to be provided for
// all three of these.
//
// Assignment could be achieved by destruction, then copy, but this
// is inefficient, so its better to allow for a custom assign function.

typedef struct {
    size_t size;
    void (*copy)(void *from, void *to);
    void (*destruct)(void *object);
    void (*assign)(void *from, void *to);
    bool (*compare)(void *a, void *b);
} Type;

void type_copy(Type *type, void *from, void *to);
void type_destruct(Type *type, void *object);
void type_assign(Type *type, void *from, void *to);
bool type_compare(Type *type, void *a, void *b);


#endif

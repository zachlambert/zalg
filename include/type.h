#ifndef ZALG_DATA_TYPE_H
#define ZALG_DATA_TYPE_H

#include <stdbool.h>
#include <stdlib.h>

// The Type struct provides a similar interface to C++ classes,
// allowing for data which contains dynamically allocated memory.
// Where no function is provided, the default shallow version is used.

// Only pointers to types should be used. The library user only creates
// a single instance of a Type struct per data type, then passes the address
// of this object to data structures that use it.

typedef struct {
    size_t size;
    void (*construct)(void *object);
    void (*construct_copy)(void *object, void *from);
    void (*destruct)(void *object);
    void (*assign)(void *object, void *from);
    bool (*compare)(void *a, void *b);
} Type;

void *type_construct(Type *type);
void *type_construct_copy(Type *type, void *from);
void type_destruct(Type *type, void *object);
void type_assign(Type *type, void *object, void *from);
bool type_compare(Type *type, void *a, void *b);


#endif

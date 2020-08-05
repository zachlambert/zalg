#include "type.h"

#include <string.h>


void *type_construct(Type *type) {
    void *object = malloc(type->size);
    if (type->construct) {
        type->construct(object);
    }
    return object;
}

void *type_construct_copy(Type *type, void *from) {
    void *object = malloc(type->size); 
    if (type->construct_copy) {
        type->construct_copy(object, from);
    } else {
        memcpy(object, from, type->size);
    }
    return object;
}

void type_destruct(Type *type, void *object)
{
    if (type->destruct) {
        type->destruct(object);
    }
    free(object);
}

void type_assign(Type *type, void *object, void *from)
{
    if (type->assign) {
        type->assign(object, from);
    } else {
        memcpy(object, from, type->size);
    }
}

bool data_compare(Type *type, void *a, void *b) {
    if (type->compare) {
        return type->compare(a, b);
    } else {
        return false; // No sensible default
    }
}

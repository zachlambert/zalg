#include "type.h"

#include <string.h>


void type_copy(Type *type, void *from, void *to) {
    if (type->copy) {
        type->copy(from, to);
    } else {
        memcpy(to, from, type->size);
    }
}

void type_destruct(Type *type, void *object)
{
    if (type->destruct) {
        type->destruct(object);
    }
}

void type_assign(Type *type, void *from, void *to)
{
    if (type->assign) {
        type->assign(from, to);
    } else {
        memcpy(to, from, type->size);
    }
}

bool data_compare(Type *type, void *a, void *b) {
    if (type->compare) {
        return type->compare(a, b);
    } else {
        return false; // No sensible default
    }
}

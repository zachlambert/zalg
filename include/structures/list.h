#ifndef ZALG_STRUCTURES_LIST_H
#define ZALG_STRUCTURES_LIST_H

#include <stdlib.h>
#include <stdbool.h>

#include "type.h"

// ListSingle

typedef struct ListSingleNode {
    struct ListSingleNode *next;
    void *data;
} ListSingleNode;

typedef struct {
    Type type;
    ListSingleNode *head;
} ListSingle;

ListSingle list_single_construct(Type *type);
void list_single_add(ListSingle *list, void *data);
void list_single_remove(ListSingle *list, ListSingleNode *node);
ListSingle list_single_destruct(ListSingle *list);


// ListDouble

typedef struct ListDoubleNode {
    struct ListDoubleNode *prev;
    struct ListDoubleNode *next;
    void *data;
} ListDoubleNode;

typedef struct {
    Type type;
    ListDoubleNode *head;
    ListDoubleNode *tail;
} ListDouble;

ListDouble list_double_construct(Type *type);
void list_double_add(ListDouble *list, void *data);
void list_double_remove(ListDouble *list, ListDoubleNode *node);
ListDouble list_double_destruct(ListDouble *list);


// ListCircle

typedef ListSingleNode ListCircleNode;
typedef ListSingle ListCircle;

ListCircle list_circle_construct(Type *type);
void list_circle_add(ListCircle *list, void *data);
void list_circle_remove(ListCircle *list, ListCircleNode *node);
ListCircle list_circle_destruct(ListCircle *list);


// ListSingleOrdered

typedef ListSingleNode ListSingleOrderedNode;

typedef struct {
    Type type;
    ListSingleOrderedNode *head;
} ListSingleOrdered;

ListSingleOrdered list_single_ordered_construct(Type *type);
void list_single_ordered_add(ListSingleOrdered *list, void *data);
void list_single_ordered_remove(
    ListSingleOrdered *list, ListSingleOrderedNode *node
);
void list_single_ordered_destruct(ListSingleOrdered *list);


// ListDoubleOrdered

typedef ListDoubleNode ListDoubleOrderedNode;

typedef struct {
    Type type;
    ListDoubleOrderedNode *head;
    ListDoubleOrderedNode *tail;
} ListDoubleOrdered;

ListDoubleOrdered list_double_ordered_construct(Type *type);
void list_double_ordered_add(ListDoubleOrdered *list, void *data);
void list_double_ordered_remove(
    ListDoubleOrdered *list, ListDoubleOrderedNode *node
);
void list_double_ordered_destruct(ListDoubleOrdered *list);


#endif

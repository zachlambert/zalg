#ifndef ZALG_STRUCTURES_LIST_H
#define ZALG_STRUCTURES_LIST_H

#include <stdlib.h>
#include <stdbool.h>

#include "data_type.h"

// ListSingle

typedef struct ListSingleNode {
    struct ListSingleNode *next;
    void *data;
} ListSingleNode;

typedef struct {
    DataType data_type;
    ListSingleNode *head;
} ListSingle;

ListSingle list_single_create(DataType data_type);
void list_single_add(ListSingle *list, void *data);
void list_single_remove(ListSingle *list, ListSingleNode *node);


// ListDouble

typedef struct ListDoubleNode {
    struct ListDoubleNode *prev;
    struct ListDoubleNode *next;
    void *data;
} ListDoubleNode;

typedef struct {
    DataType data_type;
    ListDoubleNode *head;
    ListDoubleNode *tail;
} ListDouble;

ListDouble list_double_create(DataType data_type);
void list_double_add(ListDouble *list, void *data);
void list_double_remove(ListDouble *list, ListDoubleNode *node);


// ListCircle

typedef ListSingleNode ListCircleNode;
typedef ListSingle ListCircle;

ListCircle list_circle_create(DataType data_type);
void list_circle_add(ListCircle *list, void *data);
void list_circle_remove(ListCircle *list, ListCircleNode *node);


// ListSingleOrdered

typedef ListSingleNode ListSingleOrderedNode;

typedef struct {
    DataType data_type;
    ListSingleOrderedNode *head;
} ListSingleOrdered;

ListSingleOrdered list_single_ordered_create(DataType data_type);
void list_single_ordered_add(ListSingleOrdered *list, void *data);
void list_single_ordered_remove(
    ListSingleOrdered *list, ListSingleOrderedNode *node
);
void list_single_ordered_destroy(ListSingleOrdered *list);


// ListDoubleOrdered

typedef ListDoubleNode ListDoubleOrderedNode;

typedef struct {
    DataType data_type;
    ListDoubleOrderedNode *head;
    ListDoubleOrderedNode *tail;
} ListDoubleOrdered;

ListDoubleOrdered list_double_ordered_create(DataType data_type);
void list_double_ordered_add(ListDoubleOrdered *list, void *data);
void list_double_ordered_remove(
    ListDoubleOrdered *list, ListDoubleOrderedNode *node
);
void list_double_ordered_destroy(ListDoubleOrdered *list);


#endif

#ifndef ZALG_STRUCTURES_H
#define ZALG_STRUCTURES_H

#include <stdlib.h>
#include <stdbool.h>


// === Single-linked list ===
// Represents a list of nodes, where each node contains a pointer
// to the next.
// Nodes can contain any data, represented by a void pointer.
// The wrapper struct provides access to the first item and
// includes information necessary for allocating and freeing memory

typedef struct ListSingleNode {
    struct ListSingleNode *next;
    void *data;
} ListSingleNode;

typedef struct {
    size_t data_size;
    void (*data_destroy)(void *);
    ListSingleNode *head;
} ListSingle;

ListSingle list_single_create(size_t data_size, void (*data_destroy)(void *));
void list_single_add(ListSingle *list, void *data);
void list_single_remove(ListSingle *list, ListSingleNode *node);


// === Doubly-linked list ===
// Equivalent to the singly-linked list, except that
// nodes contain pointers to the next and previous node.
// Wrapper struct also contains a tail pointer

typedef struct ListDoubleNode {
    struct ListDoubleNode *prev;
    struct ListDoubleNode *next;
    void *data;
} ListDoubleNode;

typedef struct {
    size_t data_size;
    void (*data_destroy)(void *);
    ListDoubleNode *head;
    ListDoubleNode *tail;
} ListDouble;

ListDouble list_double_create(size_t data_size, void (*data_destroy)(void *));
void list_double_add(ListDouble *list, void *data);
void list_double_remove(ListDouble *list, ListDoubleNode *node);


// === Circular-linked list ===
// Equivalent to the singly-linked list, except that the final
// node points back to the first node
// Structs are the same

typedef ListSingleNode ListCircleNode;
typedef ListSingle ListCircle;

ListCircle list_circle_create(size_t data_size, void (*data_destroy)(void *));
void list_circle_add(ListCircle *list, void *data);
void list_circle_remove(ListCircle *list, ListCircleNode *node);


// === Ordered single-linked list ===
// Equivalent node structure
// List requires a comparison function
// data_compare(void *a, void *b) which returns true if a<b

typedef ListSingleNode ListSingleOrderedNode;

typedef struct {
    size_t data_size;
    void (*data_destroy)(void *);
    bool (*data_compare)(void *, void *);
    ListSingleOrderedNode *head;
} ListSingleOrdered;

ListSingleOrdered list_single_ordered_create(
    size_t data_size,
    void (*data_destroy)(void *),
    bool (*data_compare)(void *, void *)
);
void list_single_ordered_add(ListSingleOrdered *list, void *data);
void list_single_ordered_remove(
    ListSingleOrdered *list, ListSingleOrderedNode *node
);
void list_single_ordered_destroy(ListSingleOrdered *list);


// === Ordered doubly-linked list ===
// Equivalent node structure
// List requires a compare function:
// data_compare(void *a, void *b) which returns true if a<b

typedef ListDoubleNode ListDoubleOrderedNode;

typedef struct {
    size_t data_size;
    void (*data_destroy)(void *);
    bool (*data_compare)(void *, void *);
    ListDoubleOrderedNode *head;
    ListDoubleOrderedNode *tail;
} ListDoubleOrdered;

ListDoubleOrdered list_double_ordered_create(
    size_t data_size,
    void (*data_destroy)(void *),
    bool (*data_compare)(void *, void *)
);
void list_double_ordered_add(ListDoubleOrdered *list, void *data);
void list_double_ordered_remove(
    ListDoubleOrdered *list, ListDoubleOrderedNode *node
);
void list_double_ordered_destroy(ListDoubleOrdered *list);


#endif

#include "structures/list.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// ListSingle

ListSingle list_single_create(DataType data_type)
{
    ListSingle list = {data_type, 0};
    return list;
}

// Inserts a new node at the start of the linked list
// copying the data provided
void list_single_add(ListSingle *list, void *data)
{
    if (!data) return;  // Passed no data
    ListSingleNode *node = malloc(sizeof(ListSingleNode));
    node->data = malloc(list->data_type.size);
    list->data_type.copy(data, node->data);
    node->next = list->head;
    list->head = node;
}

// Destroys the node specified, and destroys the data using
// the provided destroy_data function.
// If node is NULL, or cannot be found, nothing is done
void list_single_remove(ListSingle *list, ListSingleNode *node)
{
    if (!node || !list->head) return;
    ListSingleNode *iter = list->head, *prev = NULL;
    while (iter) {
        if (iter == node) {
            if (prev) {
                prev->next = iter->next;
            } else {
                list->head = iter->next;
            }
            list->data_type.destroy(node->data);
            free(node);
            break;
        }
        prev = iter;
        iter = iter->next;
    }
}

void list_single_destroy(ListSingle *list)
{
    ListSingleNode *iter, *next;
    iter = list->head;
    while (iter) {
        next = iter->next;
        list->data_type.destroy(iter->data);
        free(iter);
        iter = next;
    }
}

// === ListDouble ===

ListDouble list_double_create(DataType data_type)
{
    ListDouble list = {data_type, 0, 0};
    return list;
}

// Adds nodes to the start of the list such that it matches the
// behaviour of the single-linked list (despite being able to
// append at the end with the the tail pointer if desired)
void list_double_add(ListDouble *list, void *data)
{
    if (!data) return;  // Passed no data
    ListDoubleNode *node = malloc(sizeof(ListDoubleNode));
    node->data = malloc(list->data_type.size);
    list->data_type.copy(data, node->data);
    node->next = list->head;
    node->prev = NULL;
    list->head = node;
}

void list_double_remove(ListDouble *list, ListDoubleNode *node)
{
    if (!node || !list->head) return;
    if (node->prev) {
        node->prev->next = node->next;
    } else {
        list->head = node->next;
    }
    if (node->next) {
        node->next->prev = node->prev;
    } else {
        list->tail = node->prev;
    }
    list->data_type.destroy(node->data);
    free(node);
}

void list_double_destroy(ListDouble *list)
{
    ListDoubleNode *iter, *next;
    iter = list->head;
    while (iter) {
        next = iter->next;
        list->data_type.destroy(iter->data);
        free(iter);
        iter = next;
    }
}


// === ListCircle ===

ListCircle list_circle_create(DataType data_type)
{
    ListCircle list = {data_type, 0};
    return list;
}

void list_circle_add(ListCircle *list, void *data)
{
    ListCircleNode *node = malloc(sizeof(ListCircleNode));
    node->data = malloc(list->data_type.size);
    list->data_type.copy(data, node->data);
    if (!list->head) {
        node->next = node;
    } else {
        node->next = list->head;
    }
    list->head = node;
}

void list_circle_remove(ListCircle *list, ListCircleNode *node)
{
    if (!node || !list->head) return;
    ListCircleNode *prev = list->head;
    ListCircleNode *iter = list->head->next;
    while (iter != list->head) {
        if (iter == node) {
            prev->next = iter->next;
            list->head = node->next;
            list->data_type.destroy(node->data);
            free(node);
            break;
        }
        prev = iter;
        iter = iter->next;
    }
    // Either the item isn't present, or there is just one item
    if (node == iter) {
        list->head = NULL;
        list->data_type.destroy(node->data);
        free(node);
    }
}

void list_circle_destroy(ListCircle *list)
{
    ListCircleNode *iter, *next;
    iter = list->head;
    while (iter) {
        next = iter->next;
        list->data_type.destroy(iter->data);
        free(iter);
        iter = next;
    }
}


// === ListSingleOrdered ===

ListSingleOrdered list_single_ordered_create(DataType data_type)
{
    ListSingleOrdered list = {data_type, 0};
    return list;
}

// Iterates through the list until the new data is smaller than the
// current node (iter), at which point the new node is inserted between
// the previous value and iter
void list_single_ordered_add(ListSingleOrdered *list, void *data)
{
    ListSingleOrderedNode *node;
    node = malloc((sizeof *node));
    list->data_type.copy(data, node->data);
    if (!list->head) {
        list->head = node;
    } else {
        ListSingleOrderedNode *prev, *iter;
        prev = list->head;
        iter = prev->next;
        while (iter && !list->data_type.compare(iter->data, data)) {
            prev = iter;
            iter = iter->next;
        }
        prev->next = node;
    }
}

void list_single_ordered_remove(
    ListSingleOrdered *list,
    ListSingleOrderedNode *node)
{

}


// === ListDoubleOrdered ===

ListDoubleOrdered list_double_ordered_create(DataType data_type)
{
    ListDoubleOrdered list = {data_type, 0, 0};
    return list;
}

void list_double_ordered_add(ListDoubleOrdered *list, void *data);
void list_double_ordered_remove(
    ListDoubleOrdered *list, ListDoubleOrderedNode *node
);



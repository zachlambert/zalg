#include "structures/list.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// ListSingle

ListSingle list_single_construct(Type *type)
{
    ListSingle list = {type, 0};
    return list;
}

void list_single_add(ListSingle *list, void *data)
{
    if (!data) return;  // Passed no data
    ListSingleNode *node = malloc(sizeof(ListSingleNode));
    node->data = malloc(list->type->size);
    type_copy(list->type, data, node->data);
    node->next = list->head;
    list->head = node;
}

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
            type_destruct(list->type, node->data);
            free(node);
            break;
        }
        prev = iter;
        iter = iter->next;
    }
}

void list_single_destruct(ListSingle *list)
{
    ListSingleNode *iter, *next;
    iter = list->head;
    while (iter) {
        next = iter->next;
        type_destruct(list->type, iter->data);
        free(iter);
        iter = next;
    }
}


// ListDouble

ListDouble list_double_construct(Type *type)
{
    return (ListDouble){type, 0, 0};
}

// Adds nodes to the start of the list such that it matches the
// behaviour of the single-linked list (despite being able to
// append at the end with the the tail pointer if desired)
void list_double_add(ListDouble *list, void *data)
{
    if (!data) return;  // Passed no data
    ListDoubleNode *node = malloc(sizeof(ListDoubleNode));
    node->data = malloc(list->type->size);
    type_copy(list->type, data, node->data);
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
    type_destruct(list->type, node->data);
    free(node);
}

void list_double_destroy(ListDouble *list)
{
    ListDoubleNode *iter, *next;
    iter = list->head;
    while (iter) {
        next = iter->next;
        type_destruct(list->type, iter->data);
        free(iter);
        iter = next;
    }
}


// ListCircle

ListCircle list_circle_construct(Type *type)
{
    return (ListCircle){type, 0};
}

void list_circle_add(ListCircle *list, void *data)
{
    ListCircleNode *node = malloc(sizeof(ListCircleNode));
    node->data = malloc(list->type->size);
    type_copy(list->type, data, node->data);
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
            type_destruct(list->type, node->data);
            free(node);
            break;
        }
        prev = iter;
        iter = iter->next;
    }
    // Either the item isn't present, or there is just one item
    if (node == iter) {
        list->head = NULL;
        type_destruct(list->type, node->data);
        free(node);
    }
}

void list_circle_destruct(ListCircle *list)
{
    ListCircleNode *iter, *next;
    iter = list->head;
    while (iter) {
        next = iter->next;
        type_destruct(list->type, iter->data);
        free(iter);
        iter = next;
    }
}


// ListSingleOrdered

ListSingleOrdered list_single_ordered_construct(Type *type)
{
    return (ListSingleOrdered){type, 0};
}

void list_single_ordered_add(ListSingleOrdered *list, void *data)
{
    ListSingleOrderedNode *node;
    node = malloc((sizeof *node));
    type_copy(list->type, data, node->data);
    if (!list->head) {
        list->head = node;
    } else {
        ListSingleOrderedNode *prev, *iter;
        prev = list->head;
        iter = prev->next;
        while (iter && !type_compare(list->type, iter->data, data)) {
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


// ListDoubleOrdered

ListDoubleOrdered list_double_ordered_construct(Type *type)
{
    return (ListDoubleOrdered){type, 0, 0};
}

void list_double_ordered_add(ListDoubleOrdered *list, void *data);
void list_double_ordered_remove(
    ListDoubleOrdered *list, ListDoubleOrderedNode *node
);



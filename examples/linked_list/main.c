#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "structures/list.h"

bool compare_int(void *a, void *b){ return *(int *)a < *(int *)b; }
Type type_int_s = {.size = sizeof(int), .compare = compare_int };
Type *type_int = &type_int_s;

typedef struct {
    char *data;
} cstring;

void copy_cstring(void *from, void *to)
{
    cstring *from_cstring = from;
    cstring *to_cstring = to_cstring;
    to_cstring->data = malloc(strlen(from_cstring->data)+1);
}
void destruct_cstring(void *object)
{
    free(((cstring *)object)->data);
}
void assign_cstring(void *from, void *to)
{
    cstring *to_cstring = to;
    cstring *from_cstring = from;
    if (strlen(to_cstring->data) < strlen(from_cstring->data)) {
        to_cstring->data = realloc(
            to_cstring->data,
            strlen(from_cstring->data) + 1
        ); // Need to allocate memory for the null terminator too
    }
    strcpy(to_cstring->data, from_cstring->data);
}
bool compare_cstring(void *a, void *b)
{
    return strcmp(((cstring *)a)->data, ((cstring *)b)->data);
}

Type type_cstring_s = {
    .size = sizeof(cstring),
    .copy = copy_cstring,
    .destruct = destruct_cstring,
    .assign = assign_cstring,
    .compare = compare_cstring
};
Type *type_cstring = &type_cstring_s;

int main(void)
{
    ListSingle list = list_single_create(
        sizeof(int), destroy_int
    );

    int data;
    data = 10;
    list_single_add(&list, &data);
    data = 12;
    list_single_add(&list, &data);
    data = 14;
    list_single_add(&list, &data);

    ListSingleNode *to_remove = NULL;
    for (ListSingleNode *iter = list.head; iter; iter = iter->next) {
        printf("%i\n", *(int*)iter->data);
        if (*(int*)iter->data == 12) to_remove = iter;
    }
    list_single_remove(&list, to_remove);
    for (ListSingleNode *iter = list.head; iter; iter = iter->next) {
        printf("%i\n", *(int*)iter->data);
    }

    ListSingle list2 = list_single_create(sizeof(Point), destroy_point);
    Point point;
    point.x = 0;
    point.y = 100;
    list_single_add(&list2, &point);
    point.x = 100;
    point.y = 100;
    list_single_add(&list2, &point);
    point.x = 0;
    point.y = 0;
    list_single_add(&list2, &point);

    ListSingleNode *prev = list2.head;
    if (prev && prev->next) {
        ListSingleNode* iter = prev->next;
        Point *a, *b;
        double dist;
        while (iter) {
            a = prev->data;
            b = iter->data;
            dist = hypot(b->x - a->x, b->y - a->y);
            printf(
                "(%.2f, %.2f) -> (%.2f, %.2f) = dist %.2f\n",
                a->x, a->y, b->x, b->y, dist
            );
            prev = iter;
            iter = iter->next;
        }
    }
    return 0;
}

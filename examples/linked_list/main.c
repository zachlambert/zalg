#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "structures/linked_list.h"


void destroy_int(void *data)
{
    free((int*)data);
}

typedef struct {
    double x;
    double y;
} Point;

void destroy_point(void *data)
{
    free((Point*)data);
}

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

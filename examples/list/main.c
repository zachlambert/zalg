#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "structures/list.h"

bool is_less_int(void *a, void *b){ return *(int *)a < *(int *)b; }
bool is_equal_int(void *a, void *b){ return *(int *)a == *(int *)b; }
Type type_int_s = {
    .size = sizeof(int), .is_less = is_less_int,
    .is_equal = is_equal_int
};
Type *type_int = &type_int_s;

typedef struct {
    char *data;
} cstring;

void copy_cstring(void *from, void *to)
{
    cstring *from_cstring = from;
    cstring *to_cstring = to;
    to_cstring->data = malloc(strlen(from_cstring->data)+1);
    strcpy(to_cstring->data, from_cstring->data);
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
bool is_less_cstring(void *a, void *b)
{
    return (strcmp(((cstring *)a)->data, ((cstring *)b)->data) < 0);
}
bool is_equal_cstring(void *a, void *b)
{
    return (strcmp(((cstring *)a)->data, ((cstring *)b)->data) == 0);
}

Type type_cstring_s = {
    .size = sizeof(cstring),
    .copy = copy_cstring,
    .destruct = destruct_cstring,
    .assign = assign_cstring,
    .is_less = is_less_cstring,
    .is_equal = is_equal_cstring
};
Type *type_cstring = &type_cstring_s;

int main(void)
{
    ListSingle list = list_single_construct(type_int);

    int data;
    data = 10;
    list_single_add(&list, &data);
    data = 12;
    list_single_add(&list, &data);
    data = 14;
    list_single_add(&list, &data);

    ListSingleNode *to_remove = NULL;
    int search_value = 12;
    for (ListSingleNode *iter = list.head; iter; iter = iter->next) {
        printf("%i\n", *(int*)iter->data);
        if (type_is_equal(list.type, iter->data, &search_value))
            to_remove = iter;
    }
    list_single_remove(&list, to_remove);

    for (ListSingleNode *iter = list.head; iter; iter = iter->next) {
        printf("%i\n", *(int*)iter->data);
    }

    ListSingle list2 = list_single_construct(type_cstring);
    cstring string;
    string.data = "Hello";
    list_single_add(&list2, &string);
    string.data = "Zach";
    list_single_add(&list2, &string);
    string.data = "Goodbye";
    list_single_add(&list2, &string);

    for (ListSingleNode *iter = list2.head; iter; iter = iter->next) {
        printf("%s\n", ((cstring *)iter->data)->data);
    }
    return 0;
}

#include "structures/dynamic_array.h"

#include <stdio.h>

int main(void)
{
    DynamicArray array = dynamic_array_create(sizeof(double));
    double data;
    data = 1.5;
    dynamic_array_add(&array, &data);
    data = 2.5;
    dynamic_array_add(&array, &data);
    data = 3.5;
    dynamic_array_add(&array, &data);
    data = 2.5;
    dynamic_array_add(&array, &data);

    for(double *iter = array.start; iter != array.end; iter++) {
        printf("%f\n", *iter);
    }
}

#include <stdio.h>

#include "structures/dynamic_array.h"
#include "type.h"


Type type_double_s = {.size = sizeof(double) }; // Not using comparisons
Type *type_double = &type_double_s;

int main(void)
{
    Type dt_double;
    DynamicArray array = dynamic_array_construct(type_double);
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

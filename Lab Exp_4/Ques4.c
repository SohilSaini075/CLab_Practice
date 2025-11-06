//Declare a static local variable inside a function observe how its value persists across fuction calls

#include <stdio.h>

void counterFunction() {
    static int count = 0;
    int normal = 0;

    count++;
    normal++;

    printf("count (static) = %d, normal (local) = %d\n", count, normal);
}

int main() {
    printf("First call:\n");
    counterFunction();

    printf("\nSecond call:\n");
    counterFunction();

    printf("\nThird call:\n");
    counterFunction();

    return 0;
}
//Declare variable within different code blocks (enclosed by curly braces) and test their accesibility within and outside those blocks

#include <stdio.h>

int main() {
    int x = 10;

    printf("In main, before inner block: x = %d\n", x);

    {
        int y = 20;
        printf("Inside first block: x = %d, y = %d\n", x, y);

        {
            int z = 30;
            printf("Inside nested block: x = %d, y = %d, z = %d\n", x, y, z);
        }
    }
    printf("Back in main, x is still accessible: x = %d\n", x);

    return 0;
}
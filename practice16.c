//Declare a local variable inside a function and try to access it outside the function compare it with accessing the global variable from within the function

#include <stdio.h>

int globalVar = 100;

void myFunction() {
    int localVar = 50;

    printf("Inside myFunction:\n");
    printf("  localVar = %d\n", localVar);
    printf("  globalVar = %d\n", globalVar);
}
int main() {
    printf("Inside main:\n");
    
    printf("  globalVar = %d\n", globalVar);

    myFunction();
    printf("Back in main: globalVar = %d\n", globalVar);

    return 0;
}
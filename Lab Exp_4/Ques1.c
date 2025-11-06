//Declare a global variable outside all functions and use it inside various functims do understand its avaibility.

#include <stdio.h>

int globalVar = 10;

void functionOne() {
    printf("Inside functionOne: globalVar = %d\n", globalVar);
    globalVar += 5;
}
void functionTwo() {
    printf("Inside functionTwo: globalVar = %d\n", globalVar);
    globalVar *= 2;
}
int main() {
    printf("Initially in main: globalVar = %d\n", globalVar);
    
    functionOne();
    printf("Back in main after functionOne: globalVar = %d\n", globalVar);
    
    functionTwo();
    printf("Back in main after functionTwo: globalVar = %d\n", globalVar);

    return 0;
}
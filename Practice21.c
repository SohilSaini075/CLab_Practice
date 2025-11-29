//C Program to Make a Simple Calculator using if-else

// C Program to implement a Simple Calculator 
// using if-else statements
#include <float.h>
#include <stdio.h>

int main() {
    char op;
    double a, b, res;

    printf("Enter an operator (+, -, *, /): ");
    scanf("%c", &op);

    printf("Enter two operands: ");
    scanf("%lf %lf", &a, &b);

    if (op == '+')
        res = a + b;
    else if (op == '-')
        res = a - b;
    else if (op == '*')
        res = a * b;
    else if (op == '/')
        res = a / b;
    else {
        printf("Error! Operator is not correct.\n");
        res = -DBL_MAX;
    }
  
    if (res != -DBL_MAX)
        printf("Result: %.2lf\n", res);

    return 0;
}


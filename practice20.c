// Convert Decimal to Binary using strings

#include<stdio.h>
int main()
{
    int n;
    char binaryNum[33];
    binaryNum[32] = '\0';
    int index = 31;

    printf("Enter a decimal number: ");
    scanf("%d", &n);

    if (n == 0) {
        printf("Binary representation: 0\n");
        return 0;
    }

    while (n > 0) {
        binaryNum[index] = (n % 2) + '0';
        n = n / 2;
        index--;
    }

    printf("Binary representation: %s\n", &binaryNum[index + 1]);

    return 0;
}
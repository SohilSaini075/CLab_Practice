#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main() {
    char input[100];
    char digits[100];
    int j = 0;

    scanf("%s", input);

    for (int i = 0; i < strlen(input); i++) {
        if (isdigit(input[i])) {
            digits[j++] = input[i];
        }
    }
    digits[j] = '\0';

    int num = atoi(digits);

    int secretCode = num * 2;

    printf("%d\n", secretCode);

    return 0;
}
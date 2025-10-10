#include <stdio.h>
int main() {
    char source[] = "Hello World";
    char substring[6];
    int start = 6, length = 5;
    int i, j = 0;
    for (i = start; i < start + length; i++) {
        substring[j++] = source[i];
    }
    substring[j] = '\0';
    printf("%s\n", substring);
    return 0;
}
#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int smallest = 9;
    while (N > 0) {
        int digit = N % 10;
        if (digit < smallest) {
            smallest = digit;
        }
        N = N / 10;
    }

    printf("%d\n", smallest);
    return 0;
}

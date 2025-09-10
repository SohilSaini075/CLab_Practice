//WAP to enter a number till the user wants, At the end it should display the count of positive,negatuve and zero's entered by the user

#include <stdio.h>

int main() {
    int num, choice;
    int positives = 0, negatives = 0, zeros = 0;

    do {
    
        printf("Enter a number: ");
        scanf("%d", &num);

        // Count based on input
        if (num > 0) {
            positives++;
        } else if (num < 0) {
            negatives++;
        } else {
            zeros++;
        }

        printf("Do you want to enter another number? (1 for Yes / 0 for No): ");
        scanf("%d", &choice);

    } while (choice == 1);

    printf("\nResults:\n");
    printf("Positive numbers: %d\n", positives);
    printf("Negative numbers: %d\n", negatives);
    printf("Zeros: %d\n", zeros);

    return 0;
}

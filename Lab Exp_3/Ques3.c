// According to the gregorian calendar, it was Monday on the date 01/01/01. If Any year is input through the keyboard write a program to find out what is the day on 1st January of this year.

#include <stdio.h>

int main() {
    int year, day;
    int leapYears, normalYears;

    printf("Enter year: ");
    scanf("%d", &year);

    int yearsCompleted = year - 1;
    leapYears = yearsCompleted / 4 - yearsCompleted / 100 + yearsCompleted / 400;
    normalYears = yearsCompleted - leapYears;

    day = (normalYears * 1 + leapYears * 2) % 7;

    printf("\n1st January %d is ", year);

    switch(day) {
        case 0: printf("Monday\n"); break;
        case 1: printf("Tuesday\n"); break;
        case 2: printf("Wednesday\n"); break;
        case 3: printf("Thursday\n"); break;
        case 4: printf("Friday\n"); break;
        case 5: printf("Saturday\n"); break;
        case 6: printf("Sunday\n"); break;
    }

    return 0;
}
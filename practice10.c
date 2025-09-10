/*
The population of a town is 10,000. The population has increased steadily at the rate of 10% per year for the last 10 years.
WAP  to decide the population at the end of each year in the last decade.
*/

#include <stdio.h>
#include <math.h>

int main() {
    int year;
    double population = 10000;

    printf("Yearly Population Growth (10%% per year for 10 years):\n");
    for(year = 1; year <= 10; year++) {
        population = population * 1.10;
        printf("End of year %d: %.0f\n", year, population);
    }

    return 0;
}
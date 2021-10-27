#include <stdio.h>
#include <stdlib.h>

#define months 12
#define salariMin 1000
#define salaryMax 5000

int main()
{
    int salary[months];

    for(int i = 0; i < months; i++)
        salary[i] = salariMin + rand() % (salaryMax - salariMin + 1);
    for(int i = 0; i < months; i++)
        printf("% 6d", (i + 1));
    printf("\n");
    for(int i = 0; i < months; i++)
        printf("% 6d", salary[i]);
    printf("\n"); 

    float taxSum = 0.0f;
    for(int i = 0; i < months; i++)
    {
        float tax = salary[i] * 0.02f;
        printf("% 6.2f", tax);
        taxSum += tax;
    }
    printf("\n"); 

    int sumYear = 0;
    for(int i = 0; i < months; i++)
        sumYear += salary[i];
    printf("sumYear = %d\n", sumYear);

    float avgYear = sumYear /(float) months;
    printf("avgYear = %.2f\n", avgYear);

    printf("taxYear = %.2f\n", taxSum);
    printf("\n");

    int diff;
    printf("salary\tdifference\n");
    for(int i = 0; i < months; i++)
    {
        diff = avgYear - salary[i];
        printf("% 5d\t%7d", salary[i], diff);
        printf("\n");
    }    

    return 0;
}
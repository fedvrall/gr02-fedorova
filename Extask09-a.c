#include <stdlib.h>
#include <stdio.h>

#define days 31
#define lowCoeff 10.0f
#define highCoeff 50.0f

int main()
{
    float coeff[days];

    for(int i = 0; i < days; i++)
        coeff[i] = lowCoeff + (highCoeff - lowCoeff) * rand() / RAND_MAX;

    for(int i = 0; i < days; i++)
    {
        printf("%6.2f", coeff[i]);
        if(i % 7 == 6)
            printf("\n");
    }
    if(days % 7 > 0)
        printf("\n");

    float cmin = highCoeff;
    float cmax = lowCoeff;
    for(int i = 0; i < days; i++)
    {
        if(coeff[i] < cmin)
            cmin = coeff[i];
        if(coeff[i] > cmax)
            cmax = coeff[i];
    }
    
    printf("min = %.2f\n", cmin);
    printf("max = %.2f\n", cmax);

    return 0;
}
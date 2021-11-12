#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define days 31
#define lowCoeff 10.0f
#define highCoeff 50.0f
#define eps 0.0001

int main()
{
    float coeff[days];

    FILE *printIn = fopen("Extask09-b.txt", "r");

    if(printIn == NULL)
        puts("Не удалось открыть файл");
    else
    {
        for(int i = 0; i < days; i++)
            fscanf(printIn, "%f", &coeff[i]);
    }
    fclose(printIn);
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

    float findCurse;
    int dayOfCurse = 0;
    printf("Какой курс вы ищите? ");
    scanf("%f", &findCurse);

    for(int i = 0; i < days; i++)
    {
        if(coeff[i] + eps >= findCurse && coeff[i] - eps <= findCurse)
            dayOfCurse = i;
    }

    printf("Курс %.2f был в %d день\n", findCurse, dayOfCurse);

    return 0;
}
    

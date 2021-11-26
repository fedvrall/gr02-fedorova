#include <stdlib.h>
#include <stdio.h>

#define rows 10
#define cols 5

#define markmin 1
#define markmax 10

int main()
{
    int tab[rows][cols];

    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            tab[i][j] = markmin + rand() % (markmax - markmin + 1);
    
    float avg[rows];

    for(int i = 0; i < rows; i++)
    {
        int sum = 0;
        avg[i] = 0.0f;
        for(int j = 0; j < cols; j++)
            sum += tab[i][j];
        avg[i] = sum / (float) cols;
    }

    printf("num");
    for(int j = 0; j < cols; j++)
        printf("\t%d", j + 1);

    printf("\tavg\n");

    for(int i = 0; i < rows; i++)
    {
        printf("%d", i + 1);
        for(int j = 0; j < cols; j++)
            printf("\t%d", tab[i][j]);
        printf("\t%.1f\n", avg[i]);
    }

    return 0;
}
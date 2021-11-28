#include <stdlib.h>
#include <stdio.h>

#define markmin 1
#define markmax 10

int main()
{
    int **tab;
    int rows, cols;
    printf("Введите количество спортсменов и количество оценок: ");
    scanf("%d %d", &rows, &cols);

    tab = (int**) malloc (rows * sizeof(int*));
    for(int i = 0; i < rows; i++)
    {
        tab[i] = (int*) malloc (cols * sizeof(int));
        for(int j = 0; j < cols; j++)
            tab[i][j] = markmin + rand() % (markmax - markmin + 1);
    }
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

    float maxMark = avg[0];
    int maxPerson = 0;
    for(int i = 1; i < rows; i++)
    {
        if(avg[i] > maxMark)
        {
            maxMark = avg[i];
            maxPerson = i;
        }
    }
    printf("Максимальная оценка %.1f у спортсмена номер %d\n", maxMark, maxPerson + 1);
    
    for(int i = 0; i < rows; i++)
        free(tab[i]);
    free(tab);

    return 0;
}
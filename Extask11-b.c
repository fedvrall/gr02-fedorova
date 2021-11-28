#include <stdlib.h>
#include <stdio.h>

#define rows 25
#define cols 5

#define markmin 2
#define markmax 5

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

    float minAvg = avg[0];
    int subj = 0;
    for(int i = 1; i < rows; i++)
    {
        if(avg[i] < minAvg)
        {
            minAvg = avg[i];
            subj = i;
        }
    }
    printf("Минимальный средний балл %.1f у предмета %d\n", minAvg, subj + 1);

    return 0;
}
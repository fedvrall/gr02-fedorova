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

    printf("\nпредмет\t   2\t   3\t   4\t   5\n\n");
    for(int i = 0; i < cols; i++)
    {
        int count2 = 0;
        int count3 = 0;
        int count4 = 0;
        int count5 = 0;
        for(int j = 0; j < rows; j++)
        {
            if(tab[i][j] == 2)
                count2++;
            if(tab[i][j] == 3)
                count3++;
            if(tab[i][j] == 4)
                count4++;
            if(tab[i][j] == 5)
                count5++;
        }
        printf("%4d\t%4d\t%4d\t%4d\t%4d\n", i+1, count2, count3, count4, count5);
    }

    return 0;
}
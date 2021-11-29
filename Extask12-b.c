#include <stdlib.h>
#include <stdio.h>

#define nMax 10
#define mMax 10

#define vMin 10
#define vMax 20

int a[mMax][nMax];
int b[mMax][nMax];
int n, m;

int filling(int m, int n)
{
    for(int i = 0; i < n * 4 / 2; i++)
        putchar(' ');
    printf("a");
        
    for(int i = 0; i < n * 4 / 2; i++)
        putchar(' ');
    putchar('\t');

    for(int i = 0; i < n * 4 / 2; i++)
        putchar(' ');
    printf("b\n");

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            a[i][j] = vMin + rand() % (vMax - vMin + 1);
            printf("% 4d", a[i][j]);
        }
        putchar('\t');
        for(int j = 0; j < n; j++)
        {
            b[i][j] = vMin + rand() % (vMax - vMin + 1);
            printf("% 4d", b[i][j]);
        }
        putchar('\n');
    }



       /* for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
                printf("% 4d", a[i][j]);
            putchar('\t');

            for(int j = 0; j < n; j++)
                printf("% 4d", b[i][j]);
            putchar('\n');
        }*/
}

void addition ()
{
    printf("Полученная матрица: \n");
    int c1[mMax][nMax];
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            c1[i][j] = a[i][j] + b[i][j];
            printf("% 4d", c1[i][j]);
        }
        putchar('\n');
    }
}

void substraction ()
{
    printf("Полученная матрица: \n");
    int c2[mMax][nMax];
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            c2[i][j] = a[i][j] - b[i][j];
            printf("% 4d", c2[i][j]);
        }
        putchar('\n');
    }
}

int main()
{
    printf("Введите n (столбцы) и m (строки): ");
    scanf("%d %d", &n, &m);

    if(n < 0 || n >= nMax || m < 0 || m > mMax)
        puts("Ошибочка");
    else
    {
        int choice;
        do
        {
            printf("\nВыберите, что будем делать: \n");
            printf("Просто заполним матрицы: клавиша 1\n");
            printf("Сложим матрицы: клавиша 2\n");
            printf("Вычтем вторую из первой: клавиша 3\n");
            printf("Выход из программы: клавиша 0\n");
            printf("Пикачу, я выбираю тебя: ");
            scanf("%d", &choice);
            switch(choice)
            {
                case 1:
                    filling(m, n);
                    break;
                case 2:
                    addition();
                    break;
                case 3:
                    substraction();
                    break;
                
            }
        }
        while(choice != 0);

        /*
        for(int i = 0; i < n * 4 / 2; i++)
            putchar(' ');
        printf("c");
        
        for(int i = 0; i < n * 4 / 2; i++)
            putchar(' ');
        putchar('\t');

        for(int i = 0; i < n * 4 / 2; i++)
            putchar(' ');
        printf("d\n");*/

    }

    return 0;
}
#include <stdlib.h>
#include <stdio.h>

//#define nMax 10
//#define mMax 10

#define vMin 10
#define vMax 20

int **a;
int **b;
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

    a = (int**) malloc (m * sizeof(int*));
    b = (int**) malloc (m * sizeof(int*));
    for(int i = 0; i < m; i++)
    {
        a[i] = (int*) malloc (n * sizeof(int));
        for(int j = 0; j < n; j++)
        {
            a[i][j] = vMin + rand() % (vMax - vMin + 1);
            printf("% 4d", a[i][j]);
        }
        putchar('\t');
        b[i] = (int*) malloc (n * sizeof(int));
        for(int j = 0; j < n; j++)
        {
            b[i][j] = vMin + rand() % (vMax - vMin + 1);
            printf("% 4d", b[i][j]);
        }
        putchar('\n');
    }
}

int addition (int m, int n)
{
    printf("Полученная матрица: \n");
    int **c1;
    c1 = (int**) malloc (m * sizeof(int*));
    for(int i = 0; i < m; i++)
    {
        c1[i] = (int*) malloc (n * sizeof(int));
        for(int j = 0; j < n; j++)
        {
            c1[i][j] = a[i][j] + b[i][j];
            printf("% 4d", c1[i][j]);
        }
        putchar('\n');
    }
    for(int i = 0; i < m; i++)
        free(c1[i]);
    free(c1);
}

int substraction (int m, int n)
{
    printf("Полученная матрица: \n");
    int **c1;
    c1 = (int**) malloc (m * sizeof(int*));
    for(int i = 0; i < m; i++)
    {
        c1[i] = (int*) malloc (n * sizeof(int));
        for(int j = 0; j < n; j++)
        {
            c1[i][j] = a[i][j] - b[i][j];
            printf("% 4d", c1[i][j]);
        }
        putchar('\n');
    }
    for(int i = 0; i < m; i++)
        free(c1[i]);
    free(c1);
}

int main()
{
    printf("Введите m (строки) и n (столбцы): ");
    scanf("%d %d", &m, &n);

    //if(n < 0 || n >= nMax || m < 0 || m > mMax)
    //    puts("Ошибочка");
    //else
    //{
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
                    addition(m, n);
                    break;
                case 3:
                    substraction(m, n);
                    break;
                
            }
        }
        while(choice != 0);
   // }
    for(int i = 0; i < m; i++)
    {
        free(a[i]);
        free(b[i]);
    }
    free(a);
    free(b);

    return 0;
}
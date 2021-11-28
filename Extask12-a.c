#include <stdlib.h>
#include <stdio.h>

#define nMax 10
#define mMax 10

#define vMin 10
#define vMax 20

int main()
{
    int n, m;
    printf("Введите n (столбцы) и m (строки): ");
    scanf("%d %d", &n, &m);

    if(n < 0 || n >= nMax || m < 0 || m > mMax)
        puts("Ошибочка");
    else
    {
        int a[mMax][nMax];
        int b[mMax][nMax];
        int c1[mMax][nMax];
        int c2[mMax][nMax];

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
            {
                a[i][j] = vMin + rand() % (vMax - vMin + 1);
                b[i][j] = vMin + rand() % (vMax - vMin + 1);
            }

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
            {
                c1[i][j] = a[i][j] + b[i][j];
                c2[i][j] = a[i][j] - b[i][j];
            }

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
                printf("% 4d", a[i][j]);
            putchar('\t');

            for(int j = 0; j < n; j++)
                printf("% 4d", b[i][j]);
            putchar('\n');
        }

        for(int i = 0; i < n * 4 / 2; i++)
            putchar(' ');
        printf("c");
        
        for(int i = 0; i < n * 4 / 2; i++)
            putchar(' ');
        putchar('\t');

        for(int i = 0; i < n * 4 / 2; i++)
            putchar(' ');
        printf("d\n");

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
                printf("% 4d", c1[i][j]);
            putchar('\t');

            for(int j = 0; j < n; j++)
                printf("% 4d", c2[i][j]);
            putchar('\n');
        }
    }

    return 0;
}
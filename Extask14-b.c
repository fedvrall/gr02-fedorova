#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct record
{
    int numberAcc;
    char fio[32];
    float summ;
    int percent;

    float result;
};

#define rows 3
struct record tab[rows];

int main()
{
    char temp[32];
    for(int i = 0; i < rows; i++)
    {
        printf("[record %d]\n", i);

        printf("account: ");
        gets(temp);
        tab[i].numberAcc = atoi(temp);

        printf("fio: ");
        gets(tab[i].fio);

        printf("sum: ");
        gets(temp);
        tab[i].summ = atof(temp);

        printf("percent: ");
        gets(temp);
        tab[i].percent = atoi(temp);

        putchar('\n');
    }
    for(int i = 0; i < rows; i++)
        tab[i].result = tab[i].summ + (tab[i].summ * tab[i].percent / 100.0f) / 12.0f;

    for(int i = 0; i < rows; i++)
        printf("%d\t%s\t%.2f\t%d\t%.2f\n", tab[i].numberAcc, tab[i].fio, tab[i].summ, tab[i].percent, tab[i].result);

    printf("Поиск информации по № счёта - введите 1, по фио владельца - введите 2\n");
    int n;
    scanf("%d", &n);

    printf("Найти: ");
    if(n == 1)
    {
        int numberAcc;
        scanf("%d", &numberAcc);

        int m = 0;
        for(int i = 0; i < rows; i++)
        {
            if(numberAcc == tab[i].numberAcc)  
            {
                    printf("%d\t%s\t%.2f\t%d\t%.2f\n", tab[i].numberAcc, tab[i].fio, tab[i].summ, tab[i].percent, tab[i].result);
                    m++;
            }    
        }

        if(m < 1)
                printf("Человека с таким № счёта не найдено\n");
    }
    else if(n == 2)
    {
        char fio[32];
        scanf("%s", fio);

        int m = 0;
        for(int i = 0; i < rows; i++)
        {
            char *p = strtok(tab[i].fio, " ");
            if(strcmp(p, fio) == 0)  
            {
                    printf("%d\t%s\t%.2f\t%d\t%.2f\n", tab[i].numberAcc, tab[i].fio, tab[i].summ, tab[i].percent, tab[i].result);
                    m++;
            }    
        }

        if(m < 1)
                printf("Человека с такими данными не найдено\n");
    }
    else
        printf("Извините, такой команды нет");

    return 0;
}
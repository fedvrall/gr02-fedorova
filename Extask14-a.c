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

    return 0;
}
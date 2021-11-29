#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct record
{
    char os[32];
    int virtMem;
    int RAM;
    int price;
};

#define rows 3
struct record tab[rows];

int main()
{
    char temp[32];
    for(int i = 0; i < rows; i++)
    {
        printf("[record %d]\nos, virtMem, ram, price: ", i);
        scanf("%s %d %d %d", tab[i].os, &tab[i].virtMem, &tab[i].RAM, &tab[i].price);

        putchar('\n');
    }

    for(int i = 0; i < rows; i++)
        printf("%s\t%d\t%d\t%d\n", tab[i].os, tab[i].virtMem, tab[i].RAM, tab[i].price);

    char os[32];
    printf("Найти ОС: ");
    scanf("%s", os);
    putchar('\n');
    for(int i = 0; i < rows; i ++)
    {
        if(strcmp(tab[i].os, os) == 0)
        {
            printf("virtMem: %d\n", tab[i].virtMem);
            printf("RAM: %d\n", tab[i].RAM);
        }
    }
    putchar('\n');
    printf("Хочу такую цену: ");
    int price;
    scanf("%d", &price);
    int m = 0;

    FILE *f = fopen("Extask15-out.txt", "w");
    for(int i = 0; i < rows; i++)
    {
        if(price >= tab[i].price)  
        {
            printf("os: %s\n", tab[i].os);
            printf("virtMem: %d\n", tab[i].virtMem);
            printf("RAM: %d\n", tab[i].RAM);
            printf("price: %d\n", tab[i].price);
            fprintf(f, "%s %d %d %d\n", tab[i].os, tab[i].virtMem, tab[i].RAM, tab[i].price);
            m++;
            putchar('\n');
        }
    }

    if(m < 1)
            printf("Извините, по вашим параметрам ничего не найдено\n");

    fclose(f);
    return 0;
}
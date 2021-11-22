#include <stdio.h>
#include <string.h>

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
    printf("search for: ");
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

    return 0;
}
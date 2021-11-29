#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct record
{
    char fio[32];
    char cat[48];
    char num[24];
    char inf[64];
};

#define rows 3
struct record tab[rows];

int main()
{
    for(int i = 0; i < rows; i++)
    {
        printf("[record %d]\n", i);

        printf("fio ");
        gets(tab[i].fio);

        printf("cat ");
        gets(tab[i].cat);

        printf("num ");
        gets(tab[i].num);

        printf("inf ");
        gets(tab[i].inf);

        putchar('\n');
    }

    for(int i = 0; i < rows; i++)
        printf("%s\t%s\t%s\t%s\n", tab[i].fio, tab[i].cat, tab[i].num, tab[i].inf);

    printf("search: ");
    char fio[32];
    gets(fio);

    putchar('\n');
    int n = 0;
    for(int i = 0; i < rows; i++)
    {
        char *p = strtok(tab[i].fio, " ");
        if(strcmp(p, fio) == 0)  
        {
            printf("num: %s\n", tab[i].num);
            printf("inf: %s\n", tab[i].inf);
            n++;
        }    
    }

    if(n < 1)
            printf("Такой фамилии нет\n");

    printf("search: ");
    char cat[32];
    gets(cat);

    FILE *f = fopen("Extask13-out.txt", "w");
    int m = 0;
    for(int i = 0; i < rows; i++)
    {
        char *p = strtok(tab[i].cat, " ");
        if(strcmp(p, cat) == 0)  
        {
            printf("fio: %s\n", tab[i].fio);
            printf("num: %s\n", tab[i].num);
            fprintf(f, "%s %s\n", tab[i].fio, tab[i].num);
            m++;
        }    
    }
    fclose(f);

    if(m < 1)
            printf("Телефонов этой категории не найдено\n");
    return 0; 
}
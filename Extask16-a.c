#include <stdio.h>

struct record
{
    char drugName[64];
    char indications[64];
    int expYears;
    int mfgYear;
}; // 136 байт * n

#define n 3
struct record row[3];

int main()
{
    for(int i = 0; i < n; i++)
    { 
        scanf("%s %s %d %d", 
            row[i].drugName, row[i].indications, &row[i].expYears, &row[i].mfgYear);
    }

    printf("name\tindics\texp\tyear\n");
    for(int i = 0; i < n; i++)
    { 
        printf("%s\t%s\t%d\t%d\n", 
            row[i].drugName, row[i].indications, row[i].expYears, row[i].mfgYear);
    }

    return 0;
}
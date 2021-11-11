#include <stdio.h>
#include <stdlib.h>

#define n 31
#define pmin 740
#define pmax 780
#define pnorm 760

int main()
{
    int pressure[n];
    printf("pressure: \n");
    for(int i = 0; i < n; i++)
    {
        pressure[i] = pmin + rand() % (pmax - pmin + 1); 
        printf("%d ", pressure[i]);
    }
    putchar('\n');

    int below = 0;
    int exact = 0;
    int above = 0;

    for(int i = 0; i < n; i++)
    {
        if(pressure[i] < pnorm)
            below ++;
        if(pressure[i] == pnorm)
            exact ++;
        if(pressure[i] > pnorm)
            above ++;
    }
    printf("below: %d\n", below);
    printf("exact: %d\n", exact);
    printf("above: %d\n", above);

    return 0;
}
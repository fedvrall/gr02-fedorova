#include <stdio.h>

    int chisl1, znam1;
    int chisl2, znam2;

void enter1()
{
    printf("First a/b: ");
    scanf("%d %d", &chisl1, &znam1);
}
void enter2()
{
    printf("Second a/b: ");
    scanf("%d %d", &chisl2, &znam2);
}

void print()
{
    printf("First a/b: %d / %d\n", chisl1, znam1);
    printf("Second a/b: %d / %d\n", chisl2, znam2);
}
void add()
{
    int chisl3 = chisl1 * znam2 + chisl2 * znam1;
    int znam3 = znam1 * znam2;
    printf("%d / %d\n", chisl3, znam3);
}
void substract()
{
    int chisl3 = chisl1 * znam2 - chisl2 * znam1;
    int znam3 = znam1 * znam2;
    printf("%d / %d\n", chisl3, znam3);
}


int main()
{   
    int choice;
    do
    {
        printf("\n");
        printf("0 - exit\n");
        printf("1 - Enter first fraction\n");
        printf("2 - Enter second fraction\n");
        printf("3 - Printing:\n");
        printf("4 - addition\n");
        printf("5 - substracting\n");
        printf("choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: enter1(); break;
            case 2: enter2(); break;
            case 3: print(); break;
            case 4: add(); break;
            case 5: substract(); break;
        }
    }
    while(choice != 0);

    return 0;
}
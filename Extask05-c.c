#include <stdio.h>

    

int nod(int a, int b)
{
    if(a < b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    int nodRes = a % b;
    if(nodRes != 0)
        return nod(b, nodRes);
    return b;
}

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
    int nodAdd = nod(chisl3, znam3);
    //printf("%d / %d\n", chisl3, znam3);
    printf("%d / %d\n", chisl3/nodAdd, znam3/nodAdd);
}
void substract()
{
    int chisl3 = chisl1 * znam2 - chisl2 * znam1;
    int znam3 = znam1 * znam2;
    printf("%d / %d\n", chisl3, znam3);
}
void multipl()
{
    int chisl3 = chisl1 * chisl2;
    int znam3 = znam1 * znam2;
    printf("%d / %d\n", chisl3, znam3);
}
void division()
{
    int chisl3 = chisl1 * znam2;
    int znam3 = znam1 * chisl2;
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
        printf("6 - multiplication\n");
        printf("7 - division\n");
        printf("choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: enter1(); break;
            case 2: enter2(); break;
            case 3: print(); break;
            case 4: add(); break;
            case 5: substract(); break;
            case 6: multipl(); break;
            case 7: division(); break;
        }
    }
    while(choice != 0);

    return 0;
}
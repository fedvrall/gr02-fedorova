#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define maxLastname 50
#define numMarks 3
#define minMark 2
#define maxMark 5

struct element
{
    char lastname[maxLastname];
    int marks[numMarks];

    struct element *prev;
    struct element *next;
};

struct element *first = NULL;
struct element *last = NULL;

int main()
{
    file *f = fopen("extask02-a.txt", "r");

    while(1)
    {
        char lastname[maxLastname];
        if (fscanf(f, "%s", lastname) != 1)
            break;
        
        struct element *e = (struct element *) malloc (sizeof(struct element));
        if (last == NULL)
        {
            e->prev = NULL;
            e-> next = NULL;
            first = e;
            last = e;
        }
        else
        {
            last->next = e;
            e->prev = last;
            e->next = NULL;
            last = e;
        }

        strcpy(e->lastname, lastname);
        for(int i = 0; i < numMarks; i++)
            e->marks[i] = minMark + rand() % (maxMark - minMark + 1);
    }

    fclose(f);

    struct element *current = first;
    while(current != NULL)
    {
        printf("%s", current->lastname);
        for(int i = 0; i < numMarks; i++)
            printf(" %d", current->marks[i]);
        printf("\n");

        current = current->next;
    }
    printf("\n");

    current = last;
    while(current != NULL)
    {
        printf("%s", current->lastname);
        for(int i = 0; i < numMarks; i++)
            printf(" %d", current->marks[i]);
        printf("\n");

        current = current->prev;
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_lastname 50
#define num_marks 3

#define mark_min 2
#define mark_max 5

struct element
{
    char lastname[max_lastname];
    int marks[num_marks];

    struct element *prev;
    struct element *next;
};

struct element *first = NULL;
struct element *last = NULL;

int main()
{
    FILE *f = fopen("Extask02-a.txt", "r");

    while(1)
    {
        char lastname[max_lastname];
        if (fscanf(f, "%s", lastname) != 1) 
            break;

        struct element *e = (struct element *) malloc(sizeof(struct element));
        if (last == NULL)
        {
            first = e;
            last = e;
            e-> prev = NULL;
            e-> next = NULL;
        }
        else
        {
            last->next = e;
            e->prev = last;
            e->next = NULL;
            last = e;
        }
        e->next = NULL;
        last = e; 

        strcpy(e-> lastname, lastname);
        for(int i = 0; i < num_marks; i++)
            e->marks[i] = mark_min + rand() % (mark_max - mark_min + 1);

    }
    fclose(f);

    struct element *current = first;
    //struct element *buffer = first;
    while(current != NULL)
    {
        printf("%s", current->lastname);
        for(int i = 0; i < num_marks; i++)
            printf(" %d", current->marks[i]);
        printf("\n");

        current = current->next;
    }
    putchar('\n');

    struct element *cur = first;
    struct element *buffer = 0;
    int count = 0;
    while(cur != NULL)
    {
        for(int i = 0; i < num_marks; i++)
        {
            if(cur->marks[i] == 2)
                count++;
        }
        if(count >= 2)
            {
                buffer = cur;
                cur = buffer->prev;
                cur -> next = buffer -> next;
                cur = buffer -> next;
                cur -> prev = buffer -> prev;
            }
        count = 0;
        printf("%s", cur->lastname);

        for(int i = 0; i < num_marks; i++)
            printf(" %d", cur->marks[i]);
        printf("\n");

        cur = cur->next;
    }
   putchar('\n');
   
    cur = last;
    while(cur != NULL)
    {
        printf("%s", cur->lastname);
        for(int i = 0; i < num_marks; i++)
            printf(" %d", cur->marks[i]);
        printf("\n");

        cur = cur->prev;
    }

    return 0;
}
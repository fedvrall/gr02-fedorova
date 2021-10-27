#include <stdio.h>
#include <string.h>

int main()
{
    char workString[256];
    fgets(workString, 256, stdin); 

    char *p = strchr(workString, '\n');
    if(p != NULL)
        p[0] = '\0';

    size_t lengthStr = strlen(workString);
    printf("length: %ld\n", lengthStr);

    int space = 0;
    for(int i = 0; i < lengthStr; i++)
    {
        if(workString[i] == 32) 
            space++;
    }
    
    if(lengthStr > 0)
        space++;
    printf("words: %d\n", space);

    return 0;
}
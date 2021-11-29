#include <stdio.h>
#include <string.h>
#include <ctype.h>

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

    workString[0] = toupper(workString[0]);
    for(int i = 0; i <= lengthStr; i++)
    {
        if(workString[i] == 32) 
            workString[i+1] = toupper(workString[i+1]);
    }

    printf("New string: %s\n", workString);

    char* tok = strtok(workString, " ");

    while (tok != NULL) {
        int n = strlen(tok);
        printf("%d %s\n", n, tok);
        tok = strtok(NULL, " ");
    }

    return 0;
}
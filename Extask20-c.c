#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define max_simb 256

int main()
{
    FILE *f = fopen("Extask20-in.txt", "r");
    FILE *endFile = fopen("Extask20-out.txt", "w+");

    int m = 0;
    char p[max_simb];
    char s[max_simb];

    while(1)
    {
        if(fgets(s, max_simb, f) == NULL)  
            break;

        char *c = strchr(s, '\n');
        if (c != NULL)
            *c = '\0';
        printf("%s ", s);

        int l = strlen(s);
        printf("%d\n", l);
        if(l > m)
        {
            m = l;
            strcpy(p, s);
        }
    }
    putchar('\n');
    printf("max string: %s\n", p);
    printf("max length: %d\n", m);

    fclose(f);
    f = fopen("Extask20-in.txt", "r");

    while(1)
    {
        if(fgets(s, max_simb, f) == NULL)  
            break;

        char *c = strchr(s, '\n');
        if (c != NULL)
            *c = '\0'; 

        char *a = "*";
        int l = strlen(s);
            
        if(l < m)
        {
            for(int i = 0; i < m-l; i++)
                strcat(s, a);
        }
        fprintf(endFile, "%s\n", s);
    }

    fclose(f);
    fclose(endFile);

    return 0;
}
#include <stdio.h>
#include <string.h>

#define max_simb 256

int main()
{
    FILE *f = fopen("Extask20-in.txt", "r");

    int m = 0;
    char p[max_simb];
    while(1)
    {
        char s[max_simb];
        if(fgets(s, max_simb, f) == NULL)  
            break;
        char *c = strchr(s, '\n');
        if (c != NULL)
            *c = '\0';

        int l = strlen(s);
        if(l > m)
        {
            m = l;
            strcpy(p, s);
        }
    }
    printf("string: %s\n", p);
    printf("length: %d\n", m);

    fclose(f);

    return 0;
}
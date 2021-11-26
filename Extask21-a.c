#include <stdio.h>
#include <string.h>

#define max_simb 256

int main()
{
    FILE *f = fopen("Extask21-in.txt", "r");
    FILE *f1 = fopen("Extask21-out.txt", "w+");

    int i = 1;

    while(1)
    {
        char s[max_simb];
        if(fgets(s, max_simb, f) == NULL)  
            break;
        char *c = strchr(s, '\n');
        if (c != NULL)
            *c = '\0';

        fprintf(f1, "%d %s\n", i, s);

        i++;
    }

    fclose(f);
    fclose(f1);

    return 0;
}
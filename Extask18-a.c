#include <stdio.h>
#include <string.h>

int main()
{
    char s[30];
    fgets(s, 30, stdin);

    char *n = strchr (s, '\n');
    if(n != NULL)
        *n = '\0';

    char d[100];
    int di = 0;
    char old = s[0];
    int r = 0;

    int l = strlen(s);
    for(int i = 1; i <= l; i++)
    {
        char c = s[i];
        if(old == c)
            r++;
        else
        {
                d[di] = old;
                di++;
                if(r > 0)
                {
                    int w = sprintf(d + di, "%d", r + 1);
                    di += w;
                }
                r = 0;
        }
        old = c;
    }
    d[di] = '\0';
    puts(d);

    return 0;
}
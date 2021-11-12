#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float f(float x)
{
    return -3.0f * cosf(x);
}

int main()
{
    float a, b;
    printf("a, b: ");
    scanf("%f %f", &a, &b);

    float eps;
    printf("eps: ");
    scanf("%f", &eps);

    FILE *printIn = fopen("Extask04-c.txt", "w+");

    float c;
    int steps = 1;
    fprintf(printIn, "step\tc\t\tfa\t\tfc\t\tabs(fc)>0\n");
    while(1)
    {
        fprintf(printIn, "%d\t", steps);
        c = (a + b) / 2.0f;
        fprintf(printIn, "%.4f\t", c);
        float fa = f(a);
        fprintf(printIn, "%.4f\t", fa);
        float fc = f(c);
        fprintf(printIn, "%.4f\t", fc);

        if(fabsf(fc) <= eps)
        {
            fprintf(printIn, "no\n");
            fprintf(printIn, "x: %f\n", c);
            fprintf(printIn, "fx: %f\n", fc);
            break;
        }
        if(fa * fc > 0.0f)
        {
           a = c;
           fprintf(printIn, "yes\n");
        }
        else
        {
            b = c;
            fprintf(printIn, "yes\n");
        }
        steps++;
    }

    fprintf(printIn, "Справились за %d шагов\n", steps);
    fclose(printIn);
    
    return 0;
}
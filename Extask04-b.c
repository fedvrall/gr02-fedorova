#include <stdio.h>
#include <math.h>

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

    float c;
    int steps = 1;
    printf("step\tc\t\tfa\t\tfc\t\tabs(fc)>0\n");
    while(1)
    {
        printf("%2d\t", steps);
        c = (a + b) / 2.0f;
        printf("%f\t", c);
        float fa = f(a);
        printf("%f\t", fa);
        float fc = f(c);
        printf("%f\t", fc);

        if(fabsf(fc) <= eps)
        {
            printf("no\n");
            printf("x: %f\n", c);
            printf("fx: %f\n", fc);
            break;
        }
        if(fa * fc > 0.0f)
        {
           a = c;
           printf("yes\n");
        }
        else
        {
            b = c;
            printf("yes\n");
        }
        steps++;
    }
    
    return 0;
}
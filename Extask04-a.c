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
    while(1)
    {
        c = (a + b) / 2.0f;
        float fa = f(a);
        float fc = f(c);

        if(fabsf(fc) <= eps)
        {
            printf("x: %f\n", c);
            printf("fx: %f\n", fc);
            break;
        }
        if(fa * fc > 0.0f)
            a = c;
        else
            b = c;
    }
    
    return 0;
}
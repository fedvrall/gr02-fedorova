#include <stdio.h>
#include <math.h>

#define g 9.8f
#define eps 0.01f

int main()
{
    float x, y;
    float x0, y0;
    printf("x0, y0: ");
    scanf("%f %f", &x0, &y0);

    float v0, a;
    printf("v0, a: ");
    scanf("%f %f", &v0, &a);

    float rad = a * (float) M_PI / 180.0f;
    float v0x = cosf(rad) * v0;
    float v0y = sinf(rad) * v0;

    float d = v0y * v0y + 4.0f * g / 2.0f * y0;
    printf("d = %f\n", d);

    float t1 = (-v0y - sqrtf(d)) / (2.0f * (-g / 2.0f));
    float t2 = (-v0y + sqrtf(d)) / (2.0f * (-g / 2.0f));
    printf("t1 = %f, t2 = %f\n", t1, t2);

    float t = 0.0f;
    while(1)
    {
        x = x0 + v0x * t;
        y = y0 + v0y * t - g * t * t / 2.0f;

        printf("t = %f, x = %f, y = %f\n", t, x, y);

        if(y < 0.0f)
            break;
        t += eps;
    }

    return 0;
}
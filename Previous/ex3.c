#include <stdio.h>
int main()
{
    float x;
    while (1)
    {
        printf("Enter x: ");
        scanf("%f", &x);
        float result;
        result = (x * x * x) + (x * x) + (x) + 7;
        printf("Result: %f\n", result);
    }

    return 0;
}
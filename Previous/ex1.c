#include<stdio.h>
#include<string.h>


int main()
{
    int x[10], sum = 0;
    printf("Enter 10 values\n");
    for(int i = 0; i < 10; i++)
    {
        scanf("%d", &x[i]);
        sum += x[i] * x[i];
    }
    printf("Sum: %d", sum);
    return 0;
}
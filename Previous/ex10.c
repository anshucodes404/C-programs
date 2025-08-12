#include<stdio.h>
void main()
{
    int *j;
    int *fun();
    j = fun();
    printf("\n%d", *j);
    // printf("\n%d", k);
}

int *fun()
{
    static int k = 35;
    return &k;
}
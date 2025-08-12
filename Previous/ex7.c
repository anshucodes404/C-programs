#include<stdio.h>
float square(float);

int main()
{
   float num;
   printf("Enter a number: "); scanf("%f", &num);
   printf("Square: %.2f\n", square(num));
   return 0;
}

float square(float n)
{
    return n*n;
}
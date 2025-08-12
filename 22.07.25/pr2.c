// Write a program to create an array of n elements using dynamic memory allocation. Calculate sum of
// all the prime elements of the array using function and de - allocate the memory of the array after its use.

#include <stdio.h>
#include<stdlib.h>

int findPrimeSum(int *ptr, int n);

int main()
{
    int n;
    printf("Enter the no. of elements you want in the array: ");
    scanf("%d", &n);
    int *ptr = (int *)calloc(n, sizeof(int));
    int sum = findPrimeSum(ptr, n);
    printf("Sum of prime numbers: %d", sum);
    free(ptr);
    return 0;
}

int findPrimeSum(int *ptr, int n)
{
    // taking input from the user
    int sum = 0;
    int flag = 1;
    printf("Enter %d elements\n", n);
    for (int i = 0; i < n; i++)
    {
        flag = 1;
        scanf("%d", (ptr + i));
        for (int j = 2; j * j <= *(ptr + i); j++)
        {
            if (*(ptr + i) % j == 0 )
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            
            sum += *(ptr + i);
        }
    }
    return sum;
}

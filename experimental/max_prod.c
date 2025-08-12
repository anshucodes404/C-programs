// 1, 2, 5, -1, 6, 0, 3, 5, 0, 2, -1, 6, -1, 3
// want to find maximum product in continuous sub Array
#include <stdio.h>

int main()
{
    int arr[] = {1, 2, 5, -1, 6, 0, 3, 7, 5, 0, 2, -1, 6, -1, 3};
    int n = sizeof(arr) / 4;
    int products[n];

    int product = 1, count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            products[count++] = product;
            product = 1;
        }
        else if (i == n - 1)
        {
            product *= arr[i];
            products[count++] = product;
        }
        else
        {
            product *= arr[i];
        }
    }

    int max = products[0];
    if (sizeof(products) / 4 > 1)
    {
        for (int i = 1; i <= count; i++)
        {
            if (max < products[i])
                max = products[i];
        }
    }

    printf("Max product is: %d", max);

    return 0;
}

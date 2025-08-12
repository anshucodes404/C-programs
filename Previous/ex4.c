#include<stdio.h>
int main()
{
    int n;
    printf("Enter n: "); scanf("%d", &n);
    int arr[n];
    printf("Enter elements\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int largest = arr[0];
    int _2ndlargest = arr[0];

    for (int i = 1; i < n; i++)
    {
        if(arr[i] > largest)
        {
            largest = arr[i];
        }

        if(arr[i] < largest && arr[i] > _2ndlargest)
        {
            _2ndlargest = arr[i];
        }
    }


    printf("Second Largest number: %d", _2ndlargest);
    return 0;
}
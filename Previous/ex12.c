#include<stdio.h>
int main()
{
    int arr[4][5], arr2[20] = {0}, i, j, k, z = 0, isPresent, count = 0;
    printf("Enter 20 elements of 2D array\n");
    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 5; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    //Making an array with no duplicates
    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 5; j++)
        {
            isPresent = 0;
           for(k = 0; k < 20; k++)
           {
            if(arr[i][j] == arr2[k])
            {
                isPresent = 1;
                break;
            }
           }
           if(!isPresent)
           {
            arr2[z++] = arr[i][j];
           }
        }
    }

    //Checking each element of arr2 in arr

    for(k = 0; k < z; k++)
    {
      count = 0;
      for(i = 0; i < 4; i++)
      {
        for(j = 0; j < 5; j++)
        {
            if(arr2[k] == arr[i][j])
            {
                count++;
            }
        }
      }
      printf("%d was found %d times\n", arr2[k], count);
    }
    return 0;
}
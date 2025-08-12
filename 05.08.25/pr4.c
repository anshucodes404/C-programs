// Let A be nXn square matrix array. WAP by using appropriate user defined functions for the
// following:
// a) Find the number of nonzero elements in A
// b) Find the sum of the elements above the leading diagonal.
// c) Display the elements below the minor diagonal.
// d) Find the product of the leading diagonal elements.
// Sample Input:
// Enter the value of n: 3
// Enter the elements: 1 2 3 4 5 6 7 8 9
// Sample Output:
// Number of nonzero elements: 9
// Sum of the elements above the leading diagonal:11
// Elements below the minor diagonal: 6 8 9
// Product of the leading diagonal elements: 45


#include <stdio.h>


int main()
{
    int n, nonZeros = 0, sum = 0, product = 1, count = 0;
    printf("Enter the no. of rows in square matrix: ");
    scanf("%d", &n);

    int arr[n][n];
    int below[(n * n - n) / 2];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
            // counting number of non-Zeros
            if (arr[i][j] != 0)
                nonZeros++;
            // sum of elements above leading diagonal
            if (j > i)
                sum += arr[i][j];
            // taking product of diagonal elements
            if (i == j)
                product *= arr[i][j];
            // if(i ) //need to configure the condition
            //     below[count++] = arr[i][j];
        }
    }

    printf("Non Zero elements are: %d\n", nonZeros);
    printf("Sum of elements above leading diagonal: %d\n", sum);
    printf("Product of elements in leading diagonal: %d\n", product);
    // printf("Elements below of minor diagonals\n");
    // for(int i = 0; i < count; i++){
    //     printf("%d  ", below[i]);
    // }
}
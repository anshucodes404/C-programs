#include <stdio.h>

int main()
{
    int count = 1, nonZeros = 0, i, j;
    // int arr[10][10] = {
    //     {0, 0, 0, 0, 0, 0, 5, 0, 0, 0},
    //     {0, 4, 0, 0, 0, 0, 0, 0, 8, 0},
    //     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    //     {3, 0, 0, 0, 0, 0, 0, 6, 0, 0},
    //     {0, 0, 0, 0, 0, 0, 0, 0, 0, 7},
    //     {0, 0, 9, 0, 0, 0, 0, 0, 0, 0},
    //     {0, 4, 0, 0, 0, 0, 0, 0, 0, 0},
    //     {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
    //     {0, 0, 0, 0, 2, 0, 0, 0, 0, 0},
    //     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    // };

    int arr[5][5];
    printf("Enter the values for sparse matrix\n");

    //taking input from user
    for (i = 0; i < 5; i++){
        for (j = 0; j < 5; j++){
            scanf("%d", &arr[i][j]);
            if(arr[i][j] > 0){
                nonZeros++;
            }
        }
    }

        int sparse[nonZeros + 1][3];

    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            if(arr[i][j] != 0){
                sparse[count][0] = i;
                sparse[count][1] = j;
                sparse[count++][2] = arr[i][j];
            }
        }
    }

    sparse[0][0] = 5;  // number of rows in original matrix
    sparse[0][1] = 5;  // number of columns in original matrix
    sparse[0][2] = count - 1;  // number of non-zero elements

    //Printing the sparse matrix
    for(i = 0; i <= sparse[0][2]; i++){ 
        for(j = 0; j < 3; j++){
            printf("%d ", sparse[i][j]);
        }
        printf("\n");
    }
    return 0;
}
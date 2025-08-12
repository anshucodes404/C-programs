#include <stdio.h>

int main()
{
    int count = 1, i, j;
    int arr[10][10] = {
        {0, 0, 0, 0, 0, 0, 5, 0, 0, 0},
        {0, 4, 0, 0, 0, 0, 0, 0, 8, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {3, 0, 0, 0, 0, 0, 0, 6, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 7},
        {0, 0, 9, 0, 0, 0, 0, 0, 0, 0},
        {0, 4, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 2, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    int sparse[11][3];

    for(i = 0; i < 10; i++){
        for(j = 0; j < 10; j++){
            if(arr[i][j] != 0){
                sparse[count][0] = i;
                sparse[count][1] = j;
                sparse[count++][2] = arr[i][j];
            }
        }
    }

    sparse[0][0] = 10;  // number of rows in original matrix
    sparse[0][1] = 10;  // number of columns in original matrix
    sparse[0][2] = count - 1;  // number of non-zero elements

    //Printing the sparse matrix
    for(i = 0; i <= sparse[0][2]; i++){  // Changed condition to use count of elements
        for(j = 0; j < 3; j++){
            printf("%d ", sparse[i][j]);
        }
        printf("\n");
    }
    return 0;
}
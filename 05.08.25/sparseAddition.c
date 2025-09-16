#include <stdio.h>

int main()
{
    int sparse1[][3] = {
        {2, 3, 4},
        {0, 0, 5},
        {0, 1, 6},
        {1, 0, 8},
        {1, 1, 5}};
    int sparse2[][3] = {
        {2, 3, 4},
        {0, 1, 4},
        {0, 2, 3},
        {1, 1, 3},
        {1, 2, 6}};

    int max_row = sparse1[0][2] + sparse2[0][2] + 1;
    int sparse3[max_row][3]; // result matrix

    sparse3[0][0] = sparse1[0][0];
    sparse3[0][1] = sparse1[0][1];
    int i = 1, j = 1, k = 1;

    while (i <= sparse1[0][2] && j <= sparse2[0][2])
    {
        if (sparse1[i][0] == sparse2[j][0])
        { // same row
            if (sparse1[i][1] == sparse2[j][1])
            { // same col
                sparse3[k][0] = sparse1[i][0];
                sparse3[k][1] = sparse1[i][1];
                sparse3[k][2] = sparse1[i][2] + sparse2[j][2];
                i++;
                j++;
                k++;
            }
            else if (sparse1[i][1] < sparse2[j][1])
            {
                sparse3[k][0] = sparse1[i][0];
                sparse3[k][1] = sparse1[i][1];
                sparse3[k][2] = sparse1[i][2];
                i++;
                k++;
            }
            else
            {
                sparse3[k][0] = sparse2[j][0];
                sparse3[k][1] = sparse2[j][1];
                sparse3[k][2] = sparse2[j][2];
                j++;
                k++;
            }
        }
        else if (sparse1[i][0] < sparse2[j][0])
        {
            sparse3[k][0] = sparse1[i][0];
            sparse3[k][1] = sparse1[i][1];
            sparse3[k][2] = sparse1[i][2];
            i++;
            k++;
        }
        else
        {
            sparse3[k][0] = sparse2[j][0];
            sparse3[k][1] = sparse2[j][1];
            sparse3[k][2] = sparse2[j][2];
            j++;
            k++;
        }
    }

    while (i <= sparse1[0][2])
    {
        sparse3[k][0] = sparse1[i][0];
        sparse3[k][1] = sparse1[i][1];
        sparse3[k][2] = sparse1[i][2];
        i++;
        k++;
    }

    while (j <= sparse2[0][2])
    {
        sparse3[k][0] = sparse2[j][0];
        sparse3[k][1] = sparse2[j][1];
        sparse3[k][2] = sparse2[j][2];
        j++;
        k++;
    }

    sparse3[0][2] = k - 1; // total non-zero count

    // printing result
    for (i = 0; i <= sparse3[0][2]; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", sparse3[i][j]);
        }
        printf("\n");
    }

    return 0;
}

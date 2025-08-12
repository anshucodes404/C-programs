#include <stdio.h>
int main()
{
    struct Book
    {
        int id;
        // char name;
        //  int price;
    };
    // int arr[3];
    // int *ptr = arr;
    struct Book *arr[3];
    
    for (int i = 0; i < 3; i++)
    {
        scanf("%d", *arr[i].id);
    }
}

// WAP using pointer, DMA to reverse the contents of an array of n elements.

#include<stdio.h>
#include<stdlib.h>

int main(){
    int n_085;
    printf("Enter the size of array: ");
    scanf("%d", &n_085);
    int* ptr_085 = (int*) calloc(n_085, sizeof(int));

    printf("Enter %d numbers\n", n_085);
    //taking input from user
    for(int i = 0 ; i < n_085; i++){
        scanf("%d", (ptr_085 + i));
    }

    //reversing the array
    for(int i = 0; i < n_085 / 2; i++){
        int temp_085 = *(ptr_085 + i);
        *(ptr_085 + i) = *(ptr_085 + (n_085 - i - 1));
        *(ptr_085 + (n_085 - i - 1)) = temp_085;
    }

    //printing the array
    for(int i = 0; i < n_085; i++){
        printf("%d ", *(ptr_085 + i));
    }
}
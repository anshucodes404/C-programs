// WAP using pointer, DMA to search an element in an array of n numbers.

#include<stdio.h>
#include<stdlib.h>

int main(){
    int n, item, i, flag = 0;
    printf("Enter the size of array: "),
    scanf("%d", &n);
    int* ptr = (int *)calloc(n, sizeof(int));
    for(i = 0; i < n; i++){
        scanf("%d", ptr + i);
    }

    printf("Enter the element to search: ");
    scanf("%d", &item);

    for(i = 0; i < n; i++){
        if(*(ptr + i) == item ){
            flag = 1;
            break;
        }
    }

    if(!flag){
        printf("Element do not exist\n");
    } else {
        printf("%d was found at index: %d\n", item, i );
    }

}
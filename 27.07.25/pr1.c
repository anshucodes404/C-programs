// WAP using DMA to find out the smallest and largest element stored in an array of n integers.

#include<stdio.h>
#include<stdlib.h>
int main(){
    int n_085, j = 0, k = 0, min_085, max_085 ;
    printf("Enter no. of elements in even quantity : ");
    scanf("%d", &n_085);
    //using DMA to allocate the memory
    int* ptr_085 = (int* )calloc(n_085, sizeof(int));
    int smaller_085[n_085/2];
    int larger_085[n_085/2];

    printf("Enter %d numbers\n", n_085);
    //Taking input fron user
    for (int i = 0; i < n_085; i++)
    {
        scanf("%d", (ptr_085 + i));
    }

    //Now seperating the array between smaller and larger in each pair formed
    for(int i = 0; i < n_085; i += 2){
        if(*(ptr_085 + i) < *(ptr_085 + i + 1)){
            smaller_085[j++] = *(ptr_085 + i);
            larger_085[k++] = *(ptr_085 + i + 1) ;
        }
        if(*(ptr_085 + i) > *(ptr_085 + i + 1)){
            larger_085[j++] = *(ptr_085 + i);
            smaller_085[k++] = *(ptr_085 + i + 1) ;
        }
    }
    
    //Now finding smaller and larger number from the respective arrays
    min_085 = smaller_085[0];
    max_085 = larger_085[0];
    for(int i = 1; i < n_085 / 2; i++){
        if(smaller_085[i] < min_085){
            min_085 = smaller_085[i];
        }
        if(larger_085[i] > max_085){
            max_085 = larger_085[i];
        }
    }

    free(ptr_085);
    printf("Min number: %d\n", min_085);
    printf("Max number: %d\n", max_085);

    return  0;

}
    //classic
    // min = arr[0];
    // max = arr[0];
    // for(int i = 0; i < n; i++){
    //     if(arr[i] < min){
    //         min = arr[i];
    //     }
    //     if(arr[i] > max){
    //         max = arr[i];
    //     }
    // }
// }
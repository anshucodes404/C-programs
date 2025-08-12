// Write a program to read two numbers and compare the numbers using function call by address.

#include<stdio.h>

void compare(int *a, int *b);

int main(){
    int a, b;
    printf("Enter two numbers\n");
    scanf("%d %d", &a, &b);
    compare(&a, &b);
    return 0;
}

//passing arguments by address
void compare(int *a, int *b){
    if(*a > *b){
        printf("%d is greater than %d", *a, *b);
    }

    else if(*a < *b){
        printf("%d is smaller than %d", *a, *b);
    }
    else{
        printf("Both are equal");
    }
}
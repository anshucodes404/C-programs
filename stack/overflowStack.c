#include<stdio.h>
int arr[6];
int top = -1;
void push(int n);
void pop();
int main(){
    push(5);
    push(7);
    push(3);
    push(4);
    pop();
    push(10);
    push(8);
    push(0);
    push(9);
    pop();
    pop();
}

void push(int n)
{
    arr[++top] = n;
}

void pop(){
    int n = arr[top--];
    printf("%d ", n);
}

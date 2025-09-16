#include<stdio.h>
#include<string.h>
#define MAX 30
char str[MAX];
int top = -1;
void push(char ch);
char pop();
int main(){
    int i;
    char str[MAX];
    printf("Enter a string: ");
    scanf(" %[^\n]", str);

    for ( i = 0; str[i] != '\0' ; i++){
        push(str[i]);
    }

    printf("%d\n", strlen(str));
    for ( i = 0; i < strlen(str) ; i++)
    {
        str[i] = pop();
    }
    // str[i] = '\0';
    i = 0;
    while(str[i] != '\0'){
        printf("%c", str[i++]);
    }
    printf("\n");
    return 0;
}

void push(char ch){
    if(top == MAX){
        printf("Stack is full\n");
        return;
    }
    str[++top] = ch;
}

char pop(){
    if(top == -1){
        printf("Stack is empty\n");
        return -1;
    }
    char ch = str[top--];
    return ch;
}
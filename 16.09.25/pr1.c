#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int top = -1;
int stack[MAX];

void isEmpty()
{
    if (top == -1)
        printf("Stack is Empty\n");
    else
        printf("Stack is not Empty\n");
}

void display()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return;
    }

    for (int i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
}

void push()
{
    if (top == MAX)
    {
        printf("Stack is full\n");
        return;
    }

    int x;
    printf("Enter the value: ");
    scanf("%d", &x);
    stack[++top] = x;
    printf("Element inserted\n");
}

void pop()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    int x = stack[top--];
    printf("Element popped: %d\n", x);
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n");
        printf("1. Check Empty\n");
        printf("2. Display elments\n");
        printf("3. Push\n");
        printf("4. Pop\n");
        printf("5. Quit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            isEmpty();
            break;
        case 2:
            display();
            break;
        case 3:
            push();
            break;
        case 4:
            pop();
            break;
        case 5:
            printf("Quitting...");
            exit(0);
        default:
            printf("Invalid Choice\n");
            break;
        }
    }
}
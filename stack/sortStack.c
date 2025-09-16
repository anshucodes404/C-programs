#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

int isEmpty()
{
    return (top == -1);
}

int peek()
{
    return stack[top];
}

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

void insertSorted(int x)
{
    if (isEmpty() || peek() <= x)
    {
        push(x);
    }
    else
    {
        int temp = pop();
        insertSorted(x);
        push(temp);
    }
}

void sortStack()
{
    if (!isEmpty())
    {
        int temp = pop();
        sortStack();
        insertSorted(temp);
    }
}

// Example usage
int main()
{
    push(30);
    push(-5);
    push(18);
    push(14);
    push(-3);

    sortStack();

    printf("Sorted stack (top to bottom):\n");
    while (!isEmpty())
    {
        printf("%d ", pop());
    }
    return 0;
}

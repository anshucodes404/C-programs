#include<stdio.h>
#include<stdlib.h>
//implementation of stack using linked list

struct Node{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void isEmpty(){
    if(head == NULL){
        printf("Stack is empty\n");
        return;
    }
    printf("Stack is not empty\n");
}

void display(){
    if(head == NULL){
        printf("Stack is empty\n");
        return;
    }
    struct Node *temp = head;
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("END\n");
}

void push(){
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the value: ");
    scanf("%d", &(temp->data));

    temp->next = head;
    head = temp;
}

void pop(){
    if (head == NULL)
    {
        printf("Stack is empty\n");
        return;
    }

    if(head->next == NULL){
        struct Node *temp = head;
        free(temp);
        head = NULL;
        return;
    }
    struct Node *temp = head;
    struct Node *tempPrev = NULL;
    while(temp->next != NULL){
        tempPrev = temp;
        temp = temp->next;
    }
    int x = temp->data;
    tempPrev->next = NULL;
    free(temp);
    printf("Element popped: %d\n", x);
}

int main(){
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
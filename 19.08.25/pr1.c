#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val;
    struct Node *next;
};

void displayLL(struct Node** head){
    if(*head == NULL){
        printf("Linked List is empty\n");
    } else {
        struct Node *temp = *head;
        while(temp != NULL){
            printf("%d --> ", temp->val);
            temp = temp->next;
        }
        printf("END\n");
    }
}

void checkEmpty(int size)
{
    if (size == 0)
    {
        printf("Linked List is empty\n\n");
    }
    else
    {
        printf("Linked List is not empty\n\n");
    }
}

struct Node *createNode()
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode)
    {
        printf("Memory allocation failed!!\n");
        exit(1);
    }

    int val;
    printf("Enter value: ");
    scanf("%d", &val);
    newNode->val = val;
    newNode->next = NULL;

    return newNode;
}

void insertFirst(struct Node **head, int *size, struct Node** tail)
{
    
    struct Node *newNode = createNode();

    if(*head == NULL){ //means this is the first element we are inserting
        *head = newNode;
        *tail = newNode;
        (*size)++;
    } else {
        newNode->next = *head;
        *head = newNode;
        (*size)++;
    }
}

void inserEnd(struct Node** tail, int* size, struct Node** head){
    struct Node *newNode = createNode();

    if(*tail == NULL){
        *head = newNode;
        *tail = newNode;
        (*size)++;
    } else {
        (*tail)->next = newNode;
        *tail = newNode;
        (*size)++;
    }
}

void insertAtPosition(struct Node** head, int* size, struct Node** tail){
    int pos;
    printf("Enter position: ");
    scanf("%d", &pos);

    if(pos < 1 || pos > *size){
        printf("Position is more than the valid size(%d)\n", *size);
        return;
    }
    if(pos == 1){
        insertFirst(head, size, tail);
    } else if(pos == *size){
        inserEnd(tail, size, head);
    } else {
        
    }
}

    int main()
{
    struct Node *head = NULL;
    struct Node *tail = NULL;
    int option;
    int size = 0;

    while (1)
    {
        printf("MENU FOR OPERATIONS ON LINKED LIST\n");
        printf("1. Display the Linked List\n");
        printf("2. Empty Checking\n");
        printf("3. Insert at Beginning\n");
        printf("4. Insert at End\n");
        printf("5. Insert at a Position\n");
        printf("6. Delete from Beginning\n");
        printf("7. Delete from End\n");
        printf("8. Delete from a position\n");
        printf("9. Delete a Value\n");
        printf("10. Total number of nodes\n");
        printf("11. Search an Element\n");
        printf("12. QUIT\n");

        printf("Enter your Choice: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            displayLL(&head);
            break;
        case 2:
            checkEmpty(size);
            break;
        case 3:
            insertFirst(&head, &size, &tail);
            break;
        case 4:
            inserEnd(&tail, &size, &head);
            break;
        case 5:
            insertAtPosition(&head, &size, &tail);
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            break;
        case 11:
            break;
        case 12:
            exit(0);
        default:
            printf("Invalid Option\n");
        }
    }

    return 0;
}
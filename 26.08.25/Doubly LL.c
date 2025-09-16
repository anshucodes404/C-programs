//Operations on doubly linked list
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int val;
    struct Node *next;
};

void displayLL_085(struct Node **head_085)
{
    if (*head_085 == NULL)
    {
        printf("Linked List is empty\n");
    }
    else
    {
        struct Node *temp_085 = *head_085;
        while (temp_085 != NULL)
        {
            printf("%d --> ", temp_085->val);
            temp_085 = temp_085->next;
        }
        printf("END\n");
    }
}

void checkEmpty_085(int size_085)
{
    if (size_085 == 0)
    {
        printf("Linked List is empty\n\n");
    }
    else
    {
        printf("Linked List is not empty\n\n");
    }
}

struct Node *createNode_085()
{
    struct Node *newNode_085 = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode_085)
    {
        printf("Memory allocation failed!!\n");
        exit(1);
    }

    int val_085;
    printf("Enter value: ");
    scanf("%d", &val_085);
    newNode_085->val = val_085;
    newNode_085->prev = NULL;
    newNode_085->next = NULL;

    return newNode_085;
}

void insertFirst_085(struct Node **head_085, int *size_085, struct Node **tail_085)
{

    struct Node *newNode_085 = createNode_085();

    if (*head_085 == NULL)
    { // means this is the first element we are inserting
        *head_085 = newNode_085;
        *tail_085 = newNode_085;
        (*size_085)++;
    }
    else
    {
        (*head_085)->prev = newNode_085;
        newNode_085->next = *head_085;
        *head_085 = newNode_085;
        (*size_085)++;
    }
}

void inserEnd_085(struct Node **tail_085, int *size_085, struct Node **head_085)
{
    struct Node *newNode_085 = createNode_085();

    if (*tail_085 == NULL)
    {
        *head_085 = newNode_085;
        *tail_085 = newNode_085;
        (*size_085)++;
    }
    else
    {
        (*tail_085)->next = newNode_085;
        newNode_085->prev = *tail_085;
        *tail_085 = newNode_085;
        (*size_085)++;
    }
}

void insertAtPosition_085(struct Node **head_085, int *size_085, struct Node **tail_085)
{
    int pos_085;
    printf("Enter position: ");
    scanf("%d", &pos_085);

    if (pos_085 < 1 || pos_085 > *size_085)
    {
        printf("Position is more than the valid size(%d)\n", *size_085);
        return;
    }
    if (pos_085 == 1)
    {
        insertFirst_085(head_085, size_085, tail_085);
        return;
    }
    if (pos_085 == *size_085)
    {
        inserEnd_085(tail_085, size_085, head_085);
        return;
    }
    else
    {
        int count_085 = 0;
        struct Node *temp_085 = *head_085;
        while (pos_085 > 1)
        {
            temp_085 = temp_085->next;
            pos_085--;
        }
        struct Node *node_085 = createNode_085();
        temp_085->next->prev = node_085;
        node_085->next = temp_085->next;
        temp_085->next = node_085;
        node_085->prev = temp_085;
    }
}

void deleteFirst_085(struct Node **head, int *size)
{
    if(*size == 0){
        printf("Linked list is empty\n\n");
        return;
    }
    struct Node *temp_085 = *head;
    *head = (*head)->next;
    (*head)->prev = NULL;
    free(temp_085);
    (*size)--;
}

void deleteEnd_085(struct Node **head, struct Node **tail, int *size)
{
    if (*size == 0)
    {
        printf("Linked list is empty\n\n");
        return;
    }
    struct Node *temp_085 = *tail;
    temp_085->prev->next = NULL;
    *tail = temp_085->prev;
    free(temp_085);
    (*size)--;
}

void deletePosition_085(struct Node **head, struct Node **tail, int *size)
{
    struct Node *temp_085 = *head;
    int position_085;
    printf("Enter the position want to be deleted: ");
    scanf("%d", &position_085);
    if (position_085 < 1 || position_085 > *size)
    {
        printf("Position is more than the valid size(%d)\n", *size);
        return;
    }
    if (position_085 == 1)
    {
        deleteFirst_085(head, size);
        return;
    }
    else if (position_085 == *size)
    {
        deleteEnd_085(head, tail, size);
        return;
    }
    else
    {
        int count_085 = 1;
        while (count_085 < position_085 - 1)
        {
            temp_085 = temp_085->next;
            count_085++;
        }
        struct Node *node_085 = temp_085->next;
        temp_085->next = node_085->next;
        node_085->next->prev = node_085->prev;
        free(node_085);
    }
}

void deleteValue_085(struct Node **tail, struct Node **head, int *size)
{
    if(*size == 0){
        printf("Linked list is empty");
        return;
    }
    int value_085;
    printf("Enter value to delete: ");
    scanf("%d", &value_085);
    struct Node* temp_085 = *head;
    while(temp_085->next->val != value_085){
        temp_085 = temp_085->next;
    }
    struct Node *p_085 = temp_085->next;
    temp_085->next = p_085->next;
    p_085->next->prev = p_085->prev;
    free(p_085);
}

void totalNodes(int size)
{
    printf("Total nodes in the linked List is: %d", size);
}

int searchElement(struct Node *head, struct Node *tail)
{
    int element;
    printf("Enter the element to search: ");
    scanf("%d", &element);
    struct Node *temp = head;
    int index = 0;
    printf("Searching...\n");
    while (temp != NULL)
    {
        if (temp->val == element)
        {
            return index;
        }
        index++;
        temp = temp->next;
    }
    return -1; // if element do not exist then this will return to the main function
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
            displayLL_085(&head);
            break;
        case 2:
            checkEmpty_085(size);
            break;
        case 3:
            insertFirst_085(&head, &size, &tail);
            break;
        case 4:
            inserEnd_085(&tail, &size, &head);
            break;
        case 5:
            insertAtPosition_085(&head, &size, &tail);
            break;
        case 6:
            deleteFirst_085(&head, &size);
            break;
        case 7:
            deleteEnd_085(&head, &tail, &size);
            break;
        case 8:
            deletePosition_085(&head, &tail, &size);
            break;
        case 9:
            deleteValue_085(&tail, &head, &size);
            break;
        case 10:
            totalNodes(size);
            break;
        case 11:
            int index = searchElement(head, tail);
            if (index == -1)
            {
                printf("Element do not exist\n\n");
            }
            else
            {
                printf("Element found at index %d\n\n", index);
            }
            break;
        case 12:
            exit(0);
        default:
            printf("Invalid Option\n");
        }
    }

    return 0;
}
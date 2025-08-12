//Create a linked List and continue until user inputs any special character

#include<stdio.h>
#include<stdlib.h>

struct node
{
    char ch;
    struct node *next;
};

struct node* createNode(char ch){
    struct node* newNode = (struct node* )malloc(sizeof(struct node));
    if(!newNode){
        printf("Memory allocation failed!");
        exit(1);
    }
    newNode->ch = ch;
    newNode->next = NULL;

    return newNode;
}


void appendNode(struct node** head, char ch){
    struct node* newNode = createNode(ch);
    if(*head == NULL){
        *head = newNode;
    } else {
        struct node* temp = *head;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = newNode;
    }
}

// New: returns 1-based index of first occurrence, or -1 if not found
int searchElement(struct node* head, char target) {
    int position = 1;
    struct node* current = head;
    while (current != NULL) {
        if (current->ch == target) {
            return position;
        }
        current = current->next;
        position++;
    }
    return -1;
}

// New: returns pointer to nth node from end (n >= 1), or NULL if out of range
struct node* getNthFromEnd(struct node* head, int n) {
    if (n <= 0) return NULL;
    struct node* lead = head;
    struct node* follow = head;

    for (int i = 0; i < n; i++) {
        if (lead == NULL) return NULL; // list shorter than n
        lead = lead->next;
    }

    while (lead != NULL) {
        lead = lead->next;
        follow = follow->next;
    }
    return follow;
}

int main(){
    struct node *head = NULL;
    int choice;
    char ch;
    
    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Append value\n");
        printf("2. Search value\n");
        printf("3. Find nth value from end\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        switch (choice) {
            case 1: {
                printf("Enter a character to append: ");
                scanf(" %c", &ch); // leading space to skip whitespace
                appendNode(&head, ch);
                printf("Appended '%c' to the list.\n", ch);
                break;
            }
            case 2: {
                printf("Enter a character to search: ");
                scanf(" %c", &ch);
                int pos = searchElement(head, ch);
                if (pos == -1) {
                    printf("Character '%c' not found.\n", ch);
                } else {
                    printf("Character '%c' found at position %d.\n", ch, pos);
                }
                break;
            }
            case 3: {
                int n;
                printf("Enter n: ");
                if (scanf("%d", &n) != 1) {
                    printf("Invalid n.\n");
                    // clear stdin on invalid integer input
                    int c; while ((c = getchar()) != '\n' && c != EOF) {}
                    break;
                }
                struct node* nth = getNthFromEnd(head, n);
                if (nth == NULL) {
                    printf("Invalid n or list too short.\n");
                } else {
                    printf("%d-th node from end contains '%c'.\n", n, nth->ch);
                }
                break;
            }
            case 4:
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
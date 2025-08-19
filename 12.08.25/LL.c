#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char ch_085;
    struct Node *next_085;
};

struct Node *createNode(char ch_085)
{
    struct Node *newNode_085 = (struct Node *)malloc(sizeof(struct Node));

    newNode_085->ch_085 = ch_085;
    newNode_085->next_085 = NULL;

    return newNode_085;
}

void append(struct Node **head_085, struct Node **tail_085, char ch_085, int *size_085)
{
    struct Node *newNode_085 = createNode(ch_085);
    (*size_085)++;
    printf("%d ", *size_085);
    if (*head_085 == NULL)
    {
        *head_085 = newNode_085; 
        *tail_085 = newNode_085;
    }
    else
    {
        (*tail_085)->next_085 = newNode_085; 
        *tail_085 = newNode_085;           
    }
}

int search(struct Node **head_085, char ch_085)
{

    if (*head_085 == NULL)
    {
        printf("List do not contain any characters\n");
        return -1;
    }

    struct Node *temp_085 = *head_085;
    int count_085 = 1;
    while (temp_085 != NULL)
    {
        if (temp_085->ch_085 == ch_085)
        {
            return count_085;
        }
        temp_085 = temp_085->next_085;
        count_085++;
    }
    return -1; 
}

char findFromEnd(struct Node **head_085, int n_085, int size_085)
{
    struct Node *temp_085 = *head_085;
    if (n_085 > size_085)
    {
        printf("n is out of bound\n");
        return '*';
    }
    if (n_085 <= 0)
    {
        printf("Enter positive n\n");
        return '*';
    }
    for (int i = 1; i <= size_085 - n_085; i++) 
    {
        temp_085 = temp_085->next_085;
    }
    return temp_085->ch_085;
}

void displayList(struct Node **head_085, int size_085)
{
    if (*head_085 == NULL)
    {
        printf("List contain no Characters\n");
        return;
    }

    struct Node *temp_085 = *head_085;
    printf("List: ");
    for (int i = 1; i <= size_085; i++)
    {
        printf("%c ", temp_085->ch_085);
        if (temp_085->next_085 != NULL)
        {
            printf("--> ");
        }
        temp_085 = temp_085->next_085;
    }
    printf("\n");
    printf("Size of list: %d\n", size_085);
}

int main()
{
    int choice_085;
    struct Node *head_085 = NULL;
    struct Node *tail_085 = NULL;
    int size_085 = 0;
    char ch_085;
    do
    {
        printf("\nEnter choice\n");
        printf("1. Add a character\n2. Search a character\n3. Find nth character from end\n4. Display List\n\n");
        scanf("%d", &choice_085);
        switch (choice_085)
        {
        case 1:
            printf("Enter a character: ");
            scanf(" %c", &ch_085);
            if (ch_085 == '!' && ch_085 == '@' && ch_085 == '#' && ch_085 == '$' && ch_085 == '%' && ch_085 == '^' && ch_085 == '&' && ch_085 == '*' && ch_085 == '-')
            {
                printf("Special characters cannot be accepted\n");
                break;
            }
            append(&head_085, &tail_085, ch_085, &size_085);
            printf("Character successfully added: %c\n", ch_085);
            break;

        case 2:
            printf("Enter a character to search: ");
            scanf(" %c", &ch_085);
            int nodeNo_085 = search(&head_085, ch_085);
            printf("%c was found at Node no. %d\n", ch_085, nodeNo_085);
            break;

        case 3:
            int n_085;
            printf("Enter the value of n: ");
            scanf("%d", &n_085);
            char res_085 = findFromEnd(&head_085, n_085, size_085);
            if (res_085 != '*')
            {
                printf("%c is the character at %dth node\n", res_085, n_085);
            }
            break;

        case 4:
            displayList(&head_085, size_085);
            break;

        default:
            printf("Invalid choice!!\n");
        }
    } while (1);
    return 0;
}
#include<stdio.h>
#include<stdlib.h>

struct student
{
    char name[30];
    int roll;
    int marks;
};

int main(){
    struct student *ptr = (struct student *)malloc(sizeof(struct student));
    
    if(ptr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    //taking input the user's data
    printf("Enter the Student name: ");
    scanf(" %[^\n]", ptr -> name);
    printf("Enter student roll no.: ");
    scanf("%d", &ptr->roll);
    printf("Enter student marks: ");
    scanf("%d", &ptr->marks);

    //printing the data
    printf("Student name: %s\n", ptr->name);
    printf("roll no.: %d\n", ptr->roll);
    printf("marks: %d\n", ptr->marks);

    free(ptr);  // Free allocated memory
    return 0;
}
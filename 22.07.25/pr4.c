// Write a program to create a structure to store the information of n number of Employees.Employee’s
// information includes data members : Emp - id, Name, Designation, basic_salary, hra %, da %.Display
// the information of employees with gross salary.Use array of structure.

#include <stdio.h>

struct employee
{
    int Emp_id;
    char name[30];
    char designation[15];
    float basic_salary;
    int hra;
    int da;
};

int main()
{
    int n;
    printf("Enter no. of employees in your company: ");
    scanf("%d", &n);
    struct employee employees[n];

    // taking input employee details
    for (int i = 0; i < n; i++)
    {
        printf("Enter details of employee %d", i + 1);
        printf("Enter employee id: ");
        scanf("%d", &employees[i].Emp_id);
        printf("Enter employee name: ");
        scanf(" %[^\n]", employees[i].name);
        printf("Enter employee designation: ");
        scanf(" %[^\n]", employees[i].designation);
        printf("Enter employee basic_salary: "); 
        scanf("%f", &employees[i].basic_salary);
        printf("Enter employee hra: ");
        scanf("%d", &employees[i].hra);
        printf("Enter employee da: ");
        scanf("%d", &employees[i].da);
    }

    // Printing employee details
    for (int i = 0; i < n; i++)
    {
        printf("Employee id: %d", employees[i].Emp_id);
        printf("Employee name: %s", employees[i].name);
        printf("Employee designation: %s", employees[i].designation);
        printf("Employee basic_salary: %f", employees[i].basic_salary);
        printf("Employee hra: %d", employees[i].hra);
        printf("Employee da: %d", employees[i].da);
        float gross_salary = employees[i].basic_salary * (employees[i].hra + employees[i].da) / 100;
        printf("Gross salary: %f", gross_salary);
    }
}
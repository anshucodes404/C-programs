// WAP using structure and DMA to store n employees’ data such as employee name, gender,
// designation, department, basic pay.Calculate the gross pay of each employee as follows : 
//Gross pay = basic pay + HR + DA, HR = 25 % of basic, DA = 50 % of basic.

#include<stdio.h>

struct employee
{
    char name_085[30];
    char gender_085;
    char designation_085[15];
    char department_085[15];
    float basicPay_085;
};

int main()
{
    int n_085, hra_085 = 25, da_085 = 50;
    printf("Enter no. of employees in your company: ");
    scanf("%d", &n_085);
    struct employee employees[n_085];

    // taking input employee details
    for (int i = 0; i < n_085; i++)
    {

        printf("Enter details of employee %d", i + 1);
        printf("Enter employee name: ");
        scanf(" %[^\n]", employees[i].name_085);
        printf("Enter Gender of the employee(M/F): ");
        scanf("%d", &employees[i].gender_085);
        printf("Enter employee designation: ");
        scanf(" %[^\n]", employees[i].designation_085);
        printf("Enter employee department: ");
        scanf(" %[^\n]", employees[i].department_085);
        printf("Enter employee basic_salary: ");
        scanf("%f", &employees[i].basicPay_085);
    }

    // Printing employee details
    for (int i = 0; i < n_085; i++)
    {
        printf("Employee name: %s", employees[i].name_085);
        printf("Employee name: %c", employees[i].gender_085);
        printf("Employee designation: %s", employees[i].designation_085);
        printf("Employee basic_salary: %f", employees[i].basicPay_085);
        float gross_salary_085 = employees[i].basicPay_085 * (hra_085 + da_085) / 100;
        printf("Gross salary: %f", gross_salary_085);
    }
}
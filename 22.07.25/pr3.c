// Write a menu driven program to create a structure to represent complex number and perform the
// following operation using function : 1. addition of two complex number(call by value) 2. multiplication of two complex number(call by address)
//  Sample Input
//  Output : Enter complex number 1 : 3, 4; Enter complex number 2 : 4, 5 
//  MENU
// 1. addition
// 2. multiplication
 // Enter your choice : 1 => Sum = 7 + 9i; Enter your choice : 2 Product = 4 + 19i

 #include<stdio.h>
 
 void operation(int choice);

 struct compNum
 {
    int real;
    int imaginary;
 }a, b;
 
 int main(){
    int choice;
    printf("MENU\n1. ADD\n2. Multiply\n");
    printf("Enter your choice: "); scanf("%d", &choice);
    operation(choice);
    return 0;
 }

 void operation(int choice){
    int realPart = 0, imag = 0;
    printf("Enter first number real and imaginary part: "); scanf("%d %d", &a.real, &a.imaginary);
    printf("Enter second number real and imaginary part: "); scanf("%d %d", &b.real, &b.imaginary);
    switch (choice)
    {
    case 1:
        //case of sum
        realPart = a.real + b.real;
        imag = a.imaginary + b.imaginary;
        printf("Sum of both complex number: %d + %di", realPart, imag);
        break;

    case 2:
        //case of product
        realPart = (a.real * b.real) - (a.imaginary * b.imaginary);
        imag = (a.real * b.imaginary) + (a.imaginary * b.real);
        printf("Product of both the complex number: %d + %di", realPart, imag);
        break;

    default : printf("Choice is not found") ;
    }
 }

#include<stdio.h>

int reverse(int num, int rev_num)
{
    if(num == 0)
    {
        return rev_num;
    }
    return reverse(num/10, rev_num * 10 + num % 10);
}

int main()
{
    int num, rev_num;
    printf("Enter a number: "); scanf("%d", &num);
    rev_num = reverse(num, 0);
    printf("Reversed number: %d\n", rev_num);
    return 0;
}
#include<stdio.h>
#include<string.h>


int main()
{
    int marks[50], i = 0, u_9 = 0, u_19 = 0, u_29 = 0,u_39 = 0,u_49 = 0,u_59 = 0,u_69 = 0,u_79 = 0,u_89 = 0,u_100 = 0;
    printf("Enter marks of the students\n");
    for ( i = 0; i < 50; i++)
    {
       scanf("%d", &marks[i]);

       if(marks[i] >= 0 && marks[i] <= 9)
       {
          u_9++;
       }
       else if(marks[i] >= 10 && marks[i] <= 19)
       {
          u_19++;
       }
       else if(marks[i] >= 20 && marks[i] <= 29)
       {
          u_29++;
       }
       else if(marks[i] >= 30 && marks[i] <= 39)
       {
          u_39++;
       }
       else if(marks[i] >= 40 && marks[i] <= 49)
       {
          u_49++;
       }
       else if(marks[i] >= 50 && marks[i] <= 59)
       {
          u_59++;
       }
       else if(marks[i] >= 60 && marks[i] <= 69)
       {
          u_69++;
       }
       else if(marks[i] >= 70 && marks[i] <= 79)
       {
          u_79++;
       }
       else if(marks[i] >= 80 && marks[i] <= 89)
       {
          u_89++;
       }
       else if(marks[i] >= 90 && marks[i] <= 100)
       {
          u_100++;
       }
    }

    printf("%d %d %d %d %d %d %d %d%d %d", u_9, u_19,u_29,u_39,u_49,u_59,u_69,u_79,u_89,u_100);
    
    return 0;
}
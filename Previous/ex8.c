#include<stdio.h>
#include<string.h>

int main()
{
   char str[30], str_ref[30];
   int len = 0, i, j, isPresent, new_len = 0, count;
   printf("Enter a string: ");
   gets(str);
   while(str[len] != '\0')
   {
     len++;
   }

   for(i = 0; i < len; i++)
   {
    isPresent = 0;
     for(j = 0; j < len; j++)
     {
        if(str[i] == str_ref[j])
        {
            isPresent = 1;
            break;
        }
     }
     if(!isPresent)
     {
        str_ref[new_len] = str[i];
        new_len++;
     }
   }
   //String without any duplicate caharacters 
   puts(str_ref);

  for(i = 0; i < new_len; i++)
  {
    count = 0;
    for(j = 0; j < len; j++)
    {
        if(str_ref[i] == str[j])
        {
            count++;
        }
    }
    printf("%c occurs %d times\n", str_ref[i], count);
  }

   return 0;
}
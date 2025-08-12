// WAP to add two distances (in km-meter) by passing structure to a function.

#include<stdio.h>

struct distance{
    int km_085;
    int m_085;
}D1_085, D2_085;

void addDistance(struct distance D1, struct distance D2){
    int km = D1.km_085 + D2.km_085;
    int m = D1.m_085 + D2.m_085;
    printf("Total Distance: %d Km %d m", km ,m);
}

int main(){
   printf("Enter first distance in km m: ");
   scanf("%d %d", &D1_085.km_085, &D1_085.m_085);
   printf("Enter second distance in km m: ");
   scanf("%d %d", &D2_085.km_085, &D2_085.m_085);
   addDistance(D1_085, D2_085);
   return 0;
}


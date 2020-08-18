#include <stdio.h>

void scambia(int *p, int *q){
   int t= *p;
   *p=*q;
   *q=t;

}

int main(){
int x, y;
scanf("%d" ,&x);
scanf(" %d" ,&y);
int *a= &x, *b=&y;
scambia(a, b);
printf("%d %d ", *a,*b);

return 0;

}

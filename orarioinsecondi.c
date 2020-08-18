#include <stdio.h>

void split_time(long int tot_sec, int *h, int *m, int *s){
     *h= tot_sec/3600;
     *m= (tot_sec-*h*3600)/60;
     *s= tot_sec- *h*3600- *m*60;
      
}

int main(){
int n, h, m, s;
int *a=&h, *b=&m, *c=&s;
scanf("%d", &n);
split_time(n, a,b,c);
printf("%d : %d: %d", h, m,s);
return 0;

}

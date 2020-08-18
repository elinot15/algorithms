#include <stdio.h>
#include <stdlib.h>

int main(){
int n;
int conta=0;
scanf("%d" , &n);
for(int i=n; i>0; i--){
   if(n%i==0){
   printf("%d \n", i);
   conta=conta+1;
   }
   }
   printf("conta: %d \n", conta);
}

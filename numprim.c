#include <stdio.h>

int primo(int n){
int ris=0;
for(int i=2; i<n; i++){
if(n%i==0){
ris=1;
break;
}
}
return ris;
}

int main(){
int n;
scanf("%d" , &n);
int ris= primo(n);
if(ris==0)
printf("NUMERO PRIMO \n");

else
printf("non primo \n");


}

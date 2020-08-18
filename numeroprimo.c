#include <stdio.h>
#include <stdlib.h>

int main(){
int n;
int conta=0;
printf("inserire un intero: ");
scanf("%d" , &n);

for(int i=1; i<=n; i++){
	if(n%i==0){
	conta=conta+1;
	//printf("%d \n", conta);
	}
}

if(conta>=3)
printf("il numero non è primo");

if(conta==2)
printf("NUMERO PRIMO");
}

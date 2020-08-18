#include <stdio.h>
#include <stdlib.h>

int main(){
int n;
int conta=0;
printf("inserisci un intero: ");
scanf("%d" , &n);
for( ; ; ){
	if(conta==n)
	break;
	
	if(conta%2==0){
	for(int i=0; i<n; i++){
    printf("+");
    }
    printf("\n");
   }
   
   	if(conta%2!=0){
	for(int i=0; i<n; i++){
    printf("0");
    }
    printf("\n");
   }
   
   conta=conta+1;
}

}

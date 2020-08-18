#include <stdio.h>

int main(){
int somma=0;
int n;
int conta=0;

while(conta!=10){
scanf("%d", &n);
somma=somma+n;
if(n!=0){
conta=conta+1;
}
}

printf("somma %d \n" , somma);
}

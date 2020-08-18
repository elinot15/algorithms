#include <stdio.h>

int main(){
int n;
int somma=0;
int conta=0;
float media=0.0;

while(n!=0){
scanf("%d", &n);
somma=somma+n;
conta= conta+1;
}
conta=conta-1;
media= (float)somma/(float)conta;
printf("somma %d \n" , somma);
printf("somma %d \n" , conta);
printf("media %2f \n" , media);
}

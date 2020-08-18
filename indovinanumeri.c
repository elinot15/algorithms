#include <stdio.h>

int main(){
int n;
printf("inserisci il numero da indovinare: ");
scanf("%d", &n);
int indovina=0;

while(indovina!=n){
scanf("%d", &indovina);
if(n<indovina){
printf("il numero è %d ? < \n", indovina);
}
if(n>indovina){
printf("il numero è %d ? > \n", indovina);
}
}
printf("il numero è %d ? = \n", n);
}

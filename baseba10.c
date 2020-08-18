#include <stdio.h>
#include <math.h>

int main(){
	int base;
	scanf(" %d", &base);
	int indice=0;
	char numeri[100];
	char ch= getchar();
	while(ch!='.'){
	numeri[indice] = ch;
	indice=indice +1;
	ch= getchar();
	}
	
	int valori[indice];
	for(int i=1; i<indice; i++){
	valori[i]= numeri[i]-48;
    }
    
    
    int ris=0;
    for(int i=0; i<indice-1; i++){
    ris=ris+(int)(pow((double)base,(double)indice-2-i))*valori[i+1];
    //printf("%d " , indice-2-i);
    //printf("%d \n" , valori[i+1]);
    }
    
    printf("%d" , ris);
    
}


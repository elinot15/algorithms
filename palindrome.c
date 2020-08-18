#include <stdio.h> 

int main(){
	int indice=0;
	char parole[100];
		char ch= getchar();
		
		while(ch!='.'){
			parole[indice]= ch;
			indice=indice+1;
			ch= getchar();
		}
	  int ris=0;
	  int meta= (indice)/2;
		for(int i=0; i< meta; i++){
			if(parole[i]!=parole[indice-1-i]){
			printf("NON È PALINDROMA");
			ris=ris+1;
			break;	
			}
		}
		if(ris==0){
			printf("palindroma");
		}		
}

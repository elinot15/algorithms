#include <stdio.h> 

int main(){
	int indice=0;
	char parole[100];
		char ch= getchar();
		while(ch!='\n'){
			parole[indice]= ch;
			indice=indice+1;
			ch= getchar();
		}
		
	for(int i=0; i<indice-1; i++){
	if(parole[i+1]==' '){
	i=i+1;
    }
	printf("%c" , parole[i]);
    }
}

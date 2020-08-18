#include <stdio.h>

int main(){
	
	int n=0, i, k=0;
	
	typedef struct{
		char nome[50];
		char cognome[50];
		int tel;
	} Rubrica;
	
	Rubrica r[100];
	
	while(n!=-1&&k<=100){
		printf("Menu': \n 0: Visualizza rubrica \n 1: Aggiungi nuova voce \n Premere -1 per uscire.\n");
		scanf("%d", &n);
		if(n==0)
			for(i=0; i<=k-1; i++)
				printf("%s %s:%d \n", r[i].nome, r[i].cognome, r[i].tel);
		if(n==1){
			printf("Inserire il nome: ");
			scanf(" %s", r[k].nome);
			printf("Inserire il cognome: ");
			scanf(" %s", r[k].cognome);
			printf("Inserire il numero: ");
			scanf(" %d", &r[k].tel);
			k++;
		}
	}

	return 0;

}


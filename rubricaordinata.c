#include <stdio.h>
#include <string.h>

int main(){
	
	int n=0, i, k=0;
	
	typedef struct{
		char nome[50];
		char cognome[50];
		int tel;
	} Rubrica;
	
	Rubrica r[100];
	char name[50], surname[50];
	int cell;
	printf("Menu': \n 0: Visualizza rubrica \n 1: Aggiungi nuova voce \n Premere -1 per uscire.\n");
	scanf("%d", &n);
	while(n!=-1&&k<=100){
		if(n==0){
			for(i=0; i<=k-1; i++)
				printf("%s %s:%d \n", r[i].nome, r[i].cognome, r[i].tel);
			}
		if(n==1){
		    printf("Inserire il nome: ");
			scanf(" %s", name[]);
			printf("Inserire il cognome: ");
			scanf(" %s", surname[]);
			printf("Inserire il numero: ");
		    scanf(" %d", &cell);
		    
		    if(k==0){
			r[0].nome= t[0].nome;
			r[0].cognome= t[0].cognome;
		    r[0].tel= t[0].tel;
		}
		else{
			for(i=0; i<=k; i++)
				if(strcmp(r[i].nome, t[0].nome)>0){
					for(int j=k-1; j>=i; j--)
						r[j+1].nome=r[j].nome;
						r[j+1].cognome=r[j].cognome;
						r[j+1].tel=r[j].tel;
					r[i].nome=t[0].nome;
					r[i].cognome= t[0].cognome;
					r[i].tel= t.tel;
					break;
				}
			if((strcmp(r[i].nome, t[0].nome))==0){
				r[k].nome=t[0].nome;
				r[k].cognome= t[0].cognome;
				r[k].tel=t.tel;
			}
					
		}
		
		printf("Menu': \n 0: Visualizza rubrica \n 1: Aggiungi nuova voce \n Premere -1 per uscire.\n");
		scanf("%d", &n);
		k++;
			
		}
	}
	
	

	return 0;

}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**Crea un nuovo registro che permetta la prenotazione di n posti.
*Se esiste già un registro di prenotazione, quest’ultimo deve essere cancellato.*/
char **newBook (int n, char **book){
	if(book!=NULL)
	free(book);
    return book = calloc(n, sizeof(char *));
 
}

/**Se il posto k è libero, prenota il posto k per il cliente identificato da name. 
Altrimenti, stampa un messaggio di errore.*/
void book(int k, char *name, char **book){
	if(book[k]!=0)
	printf("errore");
	
	else{
    char *p;
      p=malloc(sizeof(char)*strlen(name));
      int i=0;
      while(*(name+i)!='\0'){
        p[i]=name[i];
        i++;
      }
      book[k]=p;
      printf("Posto prenotato!\n");
    }
}

/** Se il posto k è occupato, cancella la prenotazione di k.
 * Altrimenti, stampa un messaggio di errore.*/
void cancel(int k, char **book){
	if(book[k]==0) 
	printf("errore");
	
	else{
	free(book[k]);
	book[k]=0;
}
}
/**Sposta il cliente dal posto f rom al posto to se ciò è possibile 
(ossia, from è occupato e to libero). Altrimenti,stampa un messaggio di errore.*/
void move(int from, int to, char **book){
	if(book[from]==0 && book[to]!=0)
	printf("errore");
	
	else{
	book[to]= book[from];
	book[from]=0;
    }

}

/**Stampa il contenuto del registro (posti prenotati).*/
void printBook(char **book, int n){
	int i;
	printf("REGISTER[0..%d]:\n", n-1);
	for(i=0; i<n ; i++)
	if(book[i]!=0){
	printf("%d -->", i);
	printf("%s \n", book[i]);
    }
}

int main(){
char c;
char *name;
char **bookReg=0;
int n, k, from, to;
while((c=getchar()) != 'f'){
	switch(c){
		
	case 'b':
	scanf(" %d\n", &n);
	bookReg= newBook(n, bookReg);
	break;
	
	case '+':
	scanf(" %d", &k);
	scanf(" %s \n", name);
	book(k, name, bookReg);
	break;
	
	case '-': 
	scanf(" %d\n", &k);
	cancel(k, bookReg);
	break;
	
	case 'm': 
	scanf(" %d", &from);
	scanf(" %d\n", &to);
	move(from, to, bookReg);
	break;
	
	case 'p': 
	printBook(bookReg, n);
	break;
	}
}
	
return 0;
}


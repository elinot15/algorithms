#include <stdio.h>
#include <stdlib.h>
struct element{
		int info;
		struct element *next;
	};
	typedef struct element element; 
	
/**che inserisce in testa alla lista h un nuovo elemento contenente n e 
 * restituisce la lista ottenuta (ossia, l’indirizzo del primo elemento della nuova lista)*/
    element * insert (int n , element *h){
	element *inserisci;
	inserisci= malloc(sizeof(element));
	inserisci -> info= n;
	inserisci -> next = *h;
	h= &inserisci;
	return inserisci;
}

/**stampa tutti gli elementi della lista h.*/
void printList (element *h){
	while(h!=NULL){
	printf("elemento lista %d \n", h-> info);
	h= h->next;
    }
    printf("\n");
}
/**stampa quanti elementi ha lista*/
void elementi(element *h){
	int contatore=0;
	while((*h)->info!=NULL){
	contatore++;
}
printf(" la lista contiene %d elementi", contatore);
}

/**che cerca l’intero n nella lista h. Se n è nella lista la funzione 
 * restituisce 1 altrimenti restituise 0*/
 int isMember (int n , element *h){
	 int restituisci=0;
	 while((h!=NULL){
		 if(h->info == n){
			 restituisci=1;
			 break;
		 }
		 h= h->next;
	 }
	 return restituisci;
 }
/**che cancella l’elemento con valore n nella lista h e restituisce la lista ottenuta. 
 * Distinguere i casi in cui l’elemento da cancellare è il primo della lista e il caso in 
 * cui non è il primo. Se n non è nella lista, la funzione non deve fare nulla.*/
void delete (int n , element **h){
	element *cur, 
	element *prev;
	
	if((*h) -> info== n){
		cur= *h;
		*h=(*h) -> next;
		free(cur);
		
	}
	else{
    for ( cur = *h , prev = NULL ;
			  cur != NULL && cur -> info != n ;
			  prev = cur , cur = cur -> next );
		prev -> next = cur -> next ;
        free ( cur );
	}
}
/**che cancella tutti gli elementi della lista h*/
void destroy (element **h){
	element *cur;
	while((h!=NULL){
		cur= h;
		h=h -> next;
		free(cur);
	}
}

/**stampare gli elementi della lista al contrario*/
int * listToArray ( element *h , int n){
	 int *p;
	 p= malloc( sizeof (size) );
	 int i;
	 for(i=0; i<n; i++){	
	p[n]= h -> info;
	h=h->next;
    }
    return a;
    
}

void printInverso(element *h){
	if(h->next==NULL)
	printf("%d\t", h->info);

else{
printInverso(h->next)
printf("%d\t", h->info);
}
}

int main (){
	int n, count=0;
	char c;
	element *head= NULL;
	
    
while((c=getchar()) != 'f'){
	switch(c){
	
	case '+':
	scanf(" %d", &n);
    if(!isMember(n, head)){
    insert(n, &head);
    count++;
    }
    break;
	
	case '-': 
	scanf(" %d", &n);
    if(isMember(n, head)){
    delete(n, &head);
    count--;
    }
    break;
	
	case '?': 
	scanf(" %d", &n);
	int membro=isMember(n, l);
	if(membro==1)
	printf("elemento presente nella lista");
	else
	printf("elemento non presente");
	break;
	
	case 'c': 
	printf("%d\n", count);
    break;
	
	case 'p': 
	printList(head);
	break;
	
	case 'o': 
	printInverso(head);
	break;
	
	case 'd': 
	destroy(head);
	head=NULL
	count=0;
	break;
	}
}
free(head);
return 0;
} 

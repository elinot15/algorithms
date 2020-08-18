#include <stdio.h>
#include <stdlib.h>

struct element {
  int info;   
  struct element *next;
};

typedef struct element  element;  


element *insert(int n, element *h);
void printList(element *h);

/* SI MODIFICHI OPPORTUNAMENTE IL SEGUENTE PROTOTIPO DI FUNZIONE */
element *find( int n , element *h);




/*  Inserisce un nuovo elemento contenente n in testa alla lista  h   
    Restituisce la lista ottenuta. */
element *insert(int n, element *h){
  element *new = malloc(sizeof(element));
  new->info = n;
  new->next = h;
  return new;
}


/* Stampa gli elementi della lista   h */
void printList(element *h){
  /* h e' usato  per attraversare la  lista */
  for( ; h!= NULL; h=h->next)
    printf("%d ", h->info);
  putchar('\n');
}



/* Cerca l'intero  n nella lista  h.   
   Se n e' nella lista  restituisce  l'indirizzo del primo elemento che lo contiene,
   altrimenti restituisce NULL. */

/***************** SI COMPLETI OPPORTUNAMENTE QUESTA FUNZIONE *********/

element *find( int n , element *h ){
   element *e=h;
   while(e!=NULL){
	   if(e->info==n)
	   return e;
	   else
	   e= e->next;
   }
	   return NULL;
}
/***************** SI COMPLETI OPPORTUNAMENTE QUESTA FUNZIONE ********
ALTRO MODO DALLA PROVA DI ALESSIA	
element *find(int n, element *head){
  element *e=head;
  while(e!=NULL&&e->info!=n){
    e=e->next;
  }

  if(!e)
    return NULL;
  else
    return e;
}
/*****************************************************/




int main(){
  element *head;
  int c, n;   

  head = NULL;
  while((c=getchar())!= 'f'){
    switch(c){

    case '+':  // + n:  aggiungi n (se non e' gia' nell'insieme)
	scanf("%d", &n);
	if(find(n,head) == NULL){// n non e' nella lista
	  head = insert(n, head);
	}
	break;

    case '?':  // ? n:  n e' nell'insieme?
	scanf("%d", &n);
	if(find(n,head)!= NULL)
	  printf("%d appartiene all'insieme\n", n);
	else
	  printf("%d non appartiene all'insieme\n", n);
	break;

    case 'p':   // stampa gli elementi dell'insieme
      printList(head);
      break;

    } // end switch
  } // end while
  return 0;
}

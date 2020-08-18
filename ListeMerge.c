#include <stdio.h>
#include <stdlib.h>

struct element {
  int info;
  struct element *next;
};

typedef struct element element;

element *insert(int n, element *h);
void printList(element *h);
element *merge(element*h1, element *h2);

/******** SI DEFINISCA OPPORTUNAMENTE LA FUNZIONE MAIN ********/
int main(){
  int n;
  element *l1=NULL;
  element *l2=NULL;
  scanf("%d", &n);
  while(n!=0){
    l1=insert(n, l1);
    scanf("%d", &n);
  }

  scanf("%d", &n);
  while(n!=0){
    l2=insert(n, l2);
    scanf("%d", &n);
  }
  l1=merge(l1, l2);
  printList(l1);
}

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



/* Fonde due liste alternando gli elementi.
Restituisce l'indirizzo della lista ottenuta */

/******** SI DEFINISCA OPPORTUNAMENTE LA FUNZIONE MERGE ********/
element *merge(element*h1, element *h2){
  element *merge=NULL;
  element* ris=NULL;
  while(h1!=NULL){
    merge=insert(h1->info, merge);
    merge=insert(h2->info, merge);
    h1=h1->next;
    h2=h2->next;
  }

  while(merge!=NULL){
    ris=insert(merge->info, ris);
    merge=merge->next;
  }

  return ris;
}
/*****************************************************/

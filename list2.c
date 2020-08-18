#include <stdio.h>
#include <stdlib.h>
#define FALSE 0
#define TRUE 1
 
struct element{
  int info;
  struct element *next;
};
 
typedef struct element element;
 
typedef struct{
  int count;
  element *head;
} list;
 
/*
Inserisce in testa alla lista h un nuovo elemento contenente n (se n non è già nella lista);
restituisce il puntatore al primo elemento della lista
*/
void insert(int n, list *l){
  element *new_node;
  new_node=malloc(sizeof(element));
  new_node->info=n;
  new_node->next=l->head;
 
  l->head=new_node;
}
 
//stampa tutti gli elementi della lista h passata come argomento
void printList(list *l){
    element *h=l->head;
    while(h!=NULL){
      printf("%d\t", h->info);
      h=h->next;
    }
    printf("\n");
}
 
/*
Cerca l'intero n nella lista h;
se n è nella lista restituisce 1, altrimenti 0
*/
int isMember(int n, list *l){
    element *h;
    h=l->head;
    while(h!=NULL){
      if((h->info)==n)
        return TRUE;
      h=h->next;
    }
    return FALSE;
}
 
/*
Cancella l'elemento con valore n nella lista h e restiruisce la lista ottenuta;
Se n non è nella lista, la funzione non fa nulla
*/
//element *delete(int n, element *h){
void delete(int n, list *l){
    element *cur;
    element *prev;
 
    if((l->head)->info==n){
      cur=l->head;
      l->head=(l->head)->next;
      free(cur);
    }
      else{
        for(cur=l->head, prev=NULL; cur!=NULL && cur->info!=n; prev=cur, cur=cur->next)
          ;
        prev->next=cur->next;
        free(cur);
      }
}
 
//cancella tutti gli elementi della lista h
void destroy(list *l){
  element *cur;
  element *h=l->head;
  while(h!=NULL){
    cur=h;
    h=h->next;
    free(cur);
  }
}
 
/*data una lista h contenente n interi, restituisce l’indirizzo di un array
di interi creato dinamicamente contenente gli elementi della lista.
*/
 
int * listToArray(list *l, int n){
  int *a=malloc(sizeof(int)*n);
  int i;
  element *h=l->head;
  for(i=0; i<n; i++){
    a[i]=h->info;
    h=h->next;
  }
 
  return a;
}
 
void printInv(list *l){
  if((l->head)->next==NULL)
    printf("%d\t", (l->head)->info);
 
  else{
    list *l1=malloc(sizeof(list));
    l1->head=(l->head)->next;
    l1->count=(l->count)-1;
    printInv(l1);
    printf("%d\t", (l->head)->info);
  }
}
 
int main(){
 
  list *l=malloc(sizeof(list));
  l->head=NULL;
  l->count=0;
  int n;
  char c;
  int *i;
  int *a;
 
  while((c=getchar())!= 'f'){
    switch(c){
      case '+': scanf(" %d", &n);
                if(!isMember(n, l)){
                  insert(n, l);
                  (l->count)++;
                }
                break;
 
      case '-': scanf(" %d", &n);
                if(isMember(n, l)){
                  delete(n, l);
                  (l->count)--;
                }
                break;
 
      case '?': scanf(" %d", &n);
                if(isMember(n, l))
                  printf("L'elemento %d appartiene alla lista\n", n);
                else
                  printf("L'elemento %d non appartiene alla lista\n", n);
                break;
 
      case 'c': printf("%d\n", l->count);
                break;
 
      case 'p': printList(l);
                break;
 
      case 'o': //Metodo 1: una volta chiamata stampo l'array al contrario e rilascio la memoria
                /*a=listToArray(l, l->count);
                for(i=a+(l->count-1); i>=a; i--)
                  printf("%d\t", *i);
                free(a);
                printf("\n");
                break;*/
                //Metodo 2: ricorsivo
                printInv(l);
                printf("\n");
                break;
 
      case 'd': destroy(l);
                l->head=NULL;
                l->count=0;
                break;
    }
  }
 
  free(l);
  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#define FALSE 0
#define TRUE 1
 
struct element{
  int info;
  struct element *next;
};
 
typedef struct element element;
 
/*
Inserisce in testa alla lista h un nuovo elemento contenente n (se n non è già nella lista);
restituisce il puntatore al primo elemento della lista
*/
/*element *insert(int n, element *h){
  element *new_node;
  new_node=malloc(sizeof(element));
  new_node->info=n;
  new_node->next=*h;
  //return new_node;
  h=&new_node;
}*/
 
void insert(int n, element **h){
  element *new_node;
  new_node=malloc(sizeof(element));
  new_node->info=n;
  new_node->next=*h;
  //return new_node;
  *h=new_node;
}
 
//stampa tutti gli elementi della lista h passata come argomento
void printList(element *h){
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
int isMember(int n, element *h){
    while(h!=NULL){
      if((h->info)==n){
        return TRUE;
      }
      h=h->next;
    }
 
    return FALSE;
}
 
/*
Cancella l'elemento con valore n nella lista h e restiruisce la lista ottenuta;
Se n non è nella lista, la funzione non fa nulla
*/
//element *delete(int n, element *h){
void delete(int n, element **h){
    element *cur;
    element *prev;
 
    if((*h)->info==n){
      cur=*h;
      *h=(*h)->next;
      free(cur);
    }
      else{
        for(cur=*h, prev=NULL; cur!=NULL && cur->info!=n; prev=cur, cur=cur->next)
          ;
          prev->next=cur->next;
          free(cur);
      }
    //return h;
}
 
//cancella tutti gli elementi della lista h
void destroy(element *h){
  element *cur;
  while(h!=NULL){
    cur=h;
    h=h->next;
    free(cur);
  }
}
 
/*data una lista h contenente n interi, restituisce l’indirizzo di un array
di interi creato dinamicamente contenente gli elementi della lista.
*/
 
int * listToArray(element *h, int n){
  int *a=malloc(sizeof(int)*n);
  int i;
  for(i=0; i<n; i++){
    a[i]=h->info;
    h=h->next;
  }
 
  return a;
}
 
void printInv(element *h){
  if(h->next==NULL)
    printf("%d\t", h->info);
 
  else{
    printInv(h->next);
    printf("%d\t", h->info);
  }
}
 
int main(){
 
  int count;
  count=0;
  //int *a;
  //int *i;
 
  element *head=NULL;
  int n;
  char c;
 
  while((c=getchar())!= 'f'){
    switch(c){
      case '+': scanf(" %d", &n);
                if(!isMember(n, head)){
                  insert(n, &head);
                  count++;
                }
                break;
 
      case '-': scanf(" %d", &n);
                if(isMember(n, head)){
                  delete(n, &head);
                  count--;
                }
                break;
      case '?': scanf(" %d", &n);
                if(isMember(n, head))
                  printf("L'elemento %d appartiene alla lista\n", n);
                else
                  printf("L'elemento %d non appartiene alla lista\n", n);
                break;
 
      case 'c': printf("%d\n", count);
                break;
 
      case 'p': printList(head);
                break;
 
      case 'o': //Metodo 1: una volta chiamata stampo l'array al contrario e rilascio la memoria
                /*a=listToArray(head, count);
                for(i=a+count-1; i>=a; i--)
                  printf("%d\t", *i);
                free(a);
                printf("\n");
                break;*/
                //Metodo 2: ricorsivo
                printInv(head);
                printf("\n");
                break;
 
      case 'd': destroy(head);
                head=NULL;
                count=0;
                break;
    }
  }
 
  free(head);
  return 0;
}

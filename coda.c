#include <stdio.h>
#include <stdlib.h>


struct element {  // definizione di un elemento della lista
  int info;
  struct element *next;    // prossimo elemento
};

typedef struct element  element;

typedef struct queue{
 element *head;
 element *tail;	
}*Queue;

Queue init_queue(){
  Queue q=malloc(sizeof(struct queue));
  q->head=NULL;
  q->tail=NULL;
  return q;
}

void enqueue(Queue q, int n){
	element *new=malloc(sizeof(element));
	new->info=n;
	if(q->head==NULL){
	q->head=new;
	q->tail=new;
}
    else{
		q->tail->next=new;
		q->tail=new;
		
	}
	new->next=NULL;
}

int dequeue(Queue q){
  int n;
  element *old=q->head;
  if(q!=NULL&& q->head!=NULL){
    n=q->head->info;
    q->head=q->head->next;
    free(old);
    return n;
  }

  return 0;
}

element *insert(int n, element *h);
void printList(element *h);
element *delete(int x, element *h);


int main(){
   int n;
  Queue q=init_queue();
  scanf("%d", &n);
  while(n!=0){
    enqueue(q, n);
    scanf("%d", &n);
  }
  element *e=q->head;
  while(e!=NULL){
    if((e->info)%2==0){
      q->head=delete(e->info,q->head);
    }
    e=e->next;
  }
  printList(q->head);
  return 0;
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


/* Cancella l'elemento  x nella lista h  e restituisce la lista ottenuta */
element *delete(int n, element *h){
  element *tmp, *p;
  if(h->info == n){  // l'elemento da cancellare e' il primo
    tmp = h;
    h = h->next;
    free(tmp);
  }
  else{  // l'elemento da cancellare non  e' il primo
    for(p = h; p->next != NULL && p->next->info != n; p = p->next)
	    ; /* p e' l'elemento che precede x oppure l'ultimo della lista */
    if ( p->next != NULL ) {
        tmp = p->next;
	p->next = p->next->next;
    	free(tmp);
    }
  }
  return h;
}

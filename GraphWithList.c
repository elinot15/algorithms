#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

struct listnode{
  struct listnode *next ;
  int v;
};

struct graph{
  int n , m;
  struct listnode **A;
};

typedef struct graph *Graph;

struct queue{
    struct listnode *head;
    struct listnode *tail;
};

typedef struct queue *Queue;

void printqueue(Queue q){
  if(q->head==NULL)
    return;
  printf("\n\tstampocoda: ");
  struct listnode *p;
  for(p=q->head; p!=NULL; p=p->next)
    printf("%d ", p->v);
  printf("fine coda\n");
  //getchar();
}

Queue createqueue(){
  Queue q=malloc(sizeof(struct queue));
  q->head=NULL;
  q->tail=NULL;

  return q;
}

int emptyq(Queue q){
  if(q==NULL||q->head==NULL)
    return 1;
  else
    return 0;
}

void enqueue (Queue q, int i){
  struct listnode *new=malloc(sizeof(struct listnode));
  new->v=i;
  new->next=NULL;

  if(q->head==NULL)
    q->head=new;
  else
    q->tail->next=new;

  q->tail=new;
}

int dequeue(Queue q){
  if(q==NULL)
    return -1;
  struct listnode *h=q->head;
  if(h==NULL)
    return -1;
  int v=h->v;
  q->head=q->head->next;
  free(q->head);
  return v;
}

/* crea un grafo con n nodi */
Graph graph_new (int n){
  Graph g=malloc(sizeof(struct graph));
  g->n=n;
  g->m=0;
  g->A=calloc(n, sizeof(struct listnode *));

  return g;
}

/* distrugge il grafo g */
void graph_destroy (Graph g){
  int i;
  struct listnode *node;
  struct listnode *next;
  for(i=0; i<g->n; i++){
    node=g->A[i];
    while(node!=NULL){
        next=node->next;
        free(node);
        node=next;
    }
  }
  free(g->A);
  free(g);
}

void destroyqueue(Queue q){
  struct listnode *node;
  for(node=q->head; node!=NULL; node=node->next){
    free(node);
  }

  free(q);
}

struct listnode *vertexinsert(struct listnode * head, int value){
  struct listnode * node=head;
  int check=0;
  while(node!=NULL){
    if(node->v==value)
      check=1;
    if(check)
      break;
    node=node->next;
  }

  if(check)
    return NULL;

  else{
    struct listnode* node=malloc(sizeof(struct listnode));
    node->next=head;
    node->v=value;
    return node;
  }

}

/* inserisce l’arco (v,w) nel grafo g */
void graph_edgeinsert (Graph g, int v, int w){
  if(v==w)
    return;
  struct listnode * node;
  if((node=vertexinsert(g->A[v], w))!=NULL){
    g->A[v]=node;
    g->A[w]=vertexinsert(g->A[w], v);
    g->m++;
  }
}

/* legge da standard input un grafo (specificare il formato!!) */
Graph graph_read (){

  int v, w;
  v=0;
  w=0;
  int n;
  scanf("%d", &n);
  Graph g = graph_new(n);

  while(v!=-1&&w!=-1){
      scanf(" %d %d", &v, &w);
      graph_edgeinsert(g, v, w);
  }

    return g;
}

/* stampa su standard output un grafo (specificare il formato!!) */
void graph_print (Graph g){
  int i;
  for(i=0; i<g->n; i++){
    struct listnode *node=g->A[i];
    while(node!=NULL){
      printf("%d -- %d\n", i, node->v);
      node=node->next;
    }
    free(node);
  }
}

void dfs1(struct graph *g, int i, int *aux, int indice){
  struct listnode *t;
  aux[i]=1;
  int j;
  indice++;
  for(t=g->A[i]; t; t=t->next)
    if(!aux[t->v]){
      printf("\n");
      for(j=0; j<indice; j++)
        printf("\t");
      printf("%d,",t->v);
      dfs1(g,t->v,aux, indice);
    }
}

void dfs(struct graph *g) {
  int i, *aux = calloc(g->n,sizeof(int));
  if(!aux){fprintf(stderr,"Errore di Allocazione\n"); exit(-4);}
    for(i=0; i<g->n; i++)
      if(!aux[i]){
        printf("\n%d,",i);
        dfs1(g,i,aux,0);
      }
  free(aux);
}

void bfs1(Graph g, int i, int *aux){
  struct listnode *t;
  Queue q=createqueue();
  enqueue(q, i);
  while(!emptyq(q)){
    i=dequeue(q);
    aux[i]=1;
    for(t=g->A[i]; t; t=t->next)
      if(!aux[t->v]){
        enqueue(q, t->v);
        printf("%d,", t->v);
        aux[t->v]=1;
      }
  }
  destroyqueue(q);
}

void bfs (Graph g){
  int i, *aux = calloc(g->n, sizeof(int));
  if(!aux){fprintf(stderr, "Errore di allocazione\n"); exit(-4);}
  for(i=0; i<g->n; i++)
    if(!aux[i]){
    printf("\n%d,", i);
    bfs1(g, i, aux);
    }
  free(aux);
}

Graph gen(float p, int n){
  srand(time(NULL));
  int i, j;
  float x;
  Graph g=graph_new(n);
  for(i=0; i<n; i++)
    for(j=0; j<n; j++){
      x=(float)rand()/(float)(RAND_MAX);
      if(x<p)
        graph_edgeinsert(g, i, j);
    }

  return g;
}

int degree(int v, Graph g){
  int conta=0;

  struct listnode * node=g->A[v];
  while(node!=NULL){
    conta++;
    node=node->next;
  }

  return conta;
}

int path(Graph g, int v, int w, int *aux){

  struct listnode *node=g->A[v];
  while(node!=NULL){
    if(w==node->v){
      return 1;
    }
    node=node->next;
  }

  node=g->A[v];
  aux[v]=1;
  while(node!=NULL){
    if(aux[node->v]!=1)
      if(path(g, node->v, w, aux))
        return 1;
    node=node->next;
  }
  return 0;
}

int count_cc(Graph g, int i, int *aux){
  struct listnode *t;
  aux[i]=1;
  int conta=0;
  for(t=g->A[i]; t; t=t->next)
    if(!aux[t->v]){
      conta++;
      conta+=count_cc(g,t->v,aux);
    }
  if(conta>=1)
    return 1;
  else
    return 0;
}

int ccc(Graph g) {
  int i, *aux = calloc(g->n,sizeof(int));
  if(!aux){fprintf(stderr,"Errore di Allocazione\n"); exit(-4);}
  int conta=0;
    for(i=0; i<g->n; i++)
      if(!aux[i]){
        conta+=count_cc(g,i,aux);
      }
  free(aux);

  return conta;
}

void cc(Graph g, int v){
  int *aux = calloc(g->n,sizeof(int));
  if(!aux){fprintf(stderr,"Errore di Allocazione\n"); exit(-4);}
  printf("%d,", v);
  dfs1(g,v,aux, 0);
  free(aux);
}

void create_span(Graph g, Graph spant, int i, int *aux){
  struct listnode *t;
  Queue q=createqueue();
  enqueue(q, i);
  while(!emptyq(q)){
    i=dequeue(q);
    aux[i]=1;
    for(t=g->A[i]; t; t=t->next)
      if(!aux[t->v]){
        enqueue(q, t->v);
        graph_edgeinsert(spant, i, t->v);
        aux[t->v]=1;
      }
  }
  destroyqueue(q);
}

void span(Graph g, int v){
  Graph spant=graph_new(g->n);
  int *aux = calloc(g->n, sizeof(int));
  if(!aux){fprintf(stderr, "Errore di allocazione\n"); exit(-4);}
  create_span(g, spant, v, aux);
  free(aux);

  dfs(spant);
}

int path_len (Graph g, int v, int w, int *aux, int *l){
  struct listnode *node=g->A[v];

  while(node!=NULL){
    if(w==node->v){
      *l=*l+1;
      return *l;
    }
    node=node->next;
  }

  node=g->A[v];
  aux[v]=1;

  while(node!=NULL){
    if(aux[node->v]!=1)
      if(path(g, node->v, w, aux)==1){
        *l=*l+1;
        path_len(g, node->v, w, aux, l);
        return *l;
      }
    node=node->next;
  }

  return -2;
}

int shortestpath(Graph g, int v, int w){
  int *aux1=calloc(g->n, sizeof(int));
  int *aux2=calloc(g->n, sizeof(int));
  int *aux3=calloc(g->n, sizeof(int));
  Graph spant=graph_new(g->n);
  create_span(g, spant, v, aux1);
  int l=0;
  if(!path(g, v, w, aux2))
    return -1;
  else
    return path_len(spant, v, w, aux3, &l);
}

int main(){
  int n=5;
  Graph g=gen(0.3, n);

  graph_print(g);

  //dfs(g);
  //printf("\n");
  //printf("grado: %d", degree(0,g));
  /*int aux[4]={0};
  if(path(g, 1, 2, aux)==1)
    printf("Esiste un cammino %d ", path(g, 1, 2, aux));
  else
    printf("Non esiste un cammino %d ", path(g, 1, 2, aux));*/
  //printf("%d\n", ccc(g));
  //cc(g, 0);
  //bfs(g);
  span(g, 0);
  printf("\n");
  printf("%d", shortestpath(g, 0, 4));

  return 0;
}

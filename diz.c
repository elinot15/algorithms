#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
 
#define HASHSIZE 10
#define N 4
 
typedef struct{
    char *word;
    int *ln_arr;
    int alloc;
    int occ;
} Item;
 
struct element{
    Item *item;
    struct element *next;
};
 
typedef struct element *Chain;
 
typedef struct ht{
  Chain array[HASHSIZE];
  int count;
}*Dict;
 
/*FUNZIONI GENERICHE*/
void printArray (int a[], int size) {
// printf( "inizio printArray di size %d\n", size );
  for (int i=0; i<size; i++)
    printf("%d ", a[i]);
  printf("\n");
}
 
 
 
/*FUNZIONI PER LA GESTIONE DEGLI ITEM*/
 
Item *item_new(char *w, int ln){
  Item *new=malloc(sizeof(Item));
  new->word=w;
  new->ln_arr=malloc(sizeof(int)*N);
  new->ln_arr[0]=ln;
  new->alloc=N;
  new->occ=1;
 
  return new;
}
 
void item_modify(Item *p, int ln){
  if(p->ln_arr[p->occ-1]==ln)
    return;
  if(p->occ==p->alloc){
    p->alloc=p->alloc*2;
    p->ln_arr=realloc(p->ln_arr, sizeof(int)*p->alloc);
  }
 
  p->ln_arr[p->occ]=ln;
  p->occ++;
}
 
void item_print(Item *p){
  if(p==NULL)
    return;
 
  printf("%s: ", p->word);
  printArray(p->ln_arr, p->occ);
}
 
/*FUNZIONI PER LA GESTIONE DELLE CATENE DI COLLISIONE*/
 
Item *chain_find(Chain c, char *w){
  if(c==NULL)
    return NULL;
 
  while(c!=NULL){
    if(strcmp(c->item->word,w)==0)
      return c->item;
    c=c->next;
  }
 
  return NULL;
}
 
Chain chain_insert(Chain c, Item *p){
  Chain new=malloc(sizeof(struct element));
  new->item=p;
  new->next=c;
 
  return new;
}
 
void chain_print(Chain h){
  if(h==NULL)
    return;
  while(h!=NULL){
    item_print(h->item);
    h=h->next;
    printf("\n");
  }
  return;
}
 
/*FUNZIONI PER LA GESTIONE DEI DIZIONARI*/
Dict dict_init(){
  Dict new=malloc(sizeof (struct ht));
  new->count=0;
  for(int i=0; i<HASHSIZE; i++)
    new->array[i]=NULL;
  return new;
}
 
unsigned long hash(char *str){
  unsigned long hash=5381;
  int c;
 
  while((c=*str++))
    hash=((hash<<5)+hash)+c; //hash*33+c
 
  return hash%HASHSIZE;
}
 
Item *dict_lookup(Dict t, char *w){
  if(t==NULL)
    return NULL;
  int h=hash(w);
  Chain c=t->array[h];
  return chain_find(c, w);
}
 
void dict_add(Dict t, Item *p){
  int h=hash(p->word);
  t->array[h]=chain_insert(t->array[h], p);
  t->count++;
}
 
void dict_print(Dict h){
  printf("\n\nDICT\n");
  for(int i=0; i<HASHSIZE; i++){
    printf("%d: ", i);
    chain_print(h->array[i]);
    printf("\n");
  }
}
 
char *read_word() {
  char *w, *p, c;
  int size=N;   // lunghezza iniziale dell'array
  int n=0;          // numero di caratteri letti
  w=malloc(size);
  p=w;      // per ricordare l'indirizzo del primo carattere
 
  while (isalpha(c=getchar())){
    // se ho terminato lo spazio, raddoppio l'allocazione
    if (w-p>=size){
      n=w-p;
      size*=2;
      p=realloc(p, size*sizeof(int));
      w=p+n;
    }
 
    // memorizzo l'i-esimo elemento
    *w++=tolower(c);
  }
 
  *w++='\0';
  *w=c;
  return p;
}
 
// Lettura di una riga terminata da \n e inserisce nel dizionario le parole della riga
// riceve il numero di riga corrente
void line(Dict t, int ln){
  char *p;
  Item *parola;
 
  do{
    p=read_word();
    if(*p=='\0')
      free(p);
    if((parola=dict_lookup(t, p)))
      item_modify(parola, ln);
    else{
      parola=item_new(p, ln);
      dict_add(t, parola);
    }
  }while(p[strlen(p)+1]!='\n');
}
 
int main(){
  Dict d=dict_init();
  int ln=0;
  char com;
  char *w;
 
  while((com=getchar())!='f'){
      switch(com){
        case '+': ln++;
                  line(d, ln);
                  break;
        case '?': getchar();
                  w=read_word();
                  item_print(dict_lookup(d, w));
                  break;
        case 'n': printf("%d", d->count);
                  break;
        case 'l': printf("%d", ln);
                  break;
        case 'p': dict_print(d);
                  break;
        }
      }
  free(d);
  free(w);
  return 0;
}

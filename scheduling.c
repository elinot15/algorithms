#include <stdio.h>
#include <stdlib.h>
 
//devo lasciare vuota la posizione 0 dell'array
struct intervallo{
    int i, f, v;
};
 
typedef struct intervallo *Intervallo;
 
Intervallo new_int(int i, int f, int v){
  Intervallo new = malloc(sizeof(struct intervallo));
  new->i=i;
  new->f=f;
  new->v=v;
 
  return new;
}
 
void print_int(Intervallo p){
  printf("%d-%d %d\n", p->i, p->f, p->v);
}
 
void array_sort(Intervallo *p, int n){
  int j, i, imin;
  Intervallo temp;
  for(i=0; i<n; i++){
    imin=i;
    for(j=i+1; j<n; j++)
      if((p[j]->f)<(p[imin]->f))
        imin=j;
    temp=p[i];
    p[i]=p[imin];
    p[imin]=temp;
  }
  return;
}
 
int peso(Intervallo *p, int j){
  int v=j;
 
  while(v!=0){
    v--;
    if(p[v]->f<=p[j]->i)
      return v;
  }
  return -1;
}
 
int max(int n, int m){
  if(n>m)
    return n;
  return m;
}
 
int *opt(Intervallo *p, int *sol, int n){
  int *m=calloc(n, sizeof(int));
  m[0]=0;
  int i;
  for(i=0; i<n; i++)
    m[i]=max(((p[i]->v)+m[sol[i]]), m[i-1]);
 
  return m;
}
 
void find_solution(Intervallo *p, int *sol, int j, int *optimal){
  if(j==-1)
    return;
  else
    if(p[j]->v+optimal[sol[j]]>=optimal[j-1]){
      print_int(p[j]);
      find_solution(p, sol, sol[j], optimal);
    }
    else
      find_solution(p, sol, sol[j], optimal);
}
 
int main(){
  int n, i, f, v, j;
  scanf("%d", &n);
 
  Intervallo *p=calloc(n, sizeof(Intervallo));
 
  for(j=0; j<n; j++){
    scanf(" %d-%d %d", &i, &f, &v);
    p[j]=new_int(i, f, v);
  }
 
  array_sort(p, n);
  printf("\n");
  /*for(j=0; j<n; j++){
    print_int(p[j]);
  }*/
  int *sol=calloc(n, sizeof(int));
 
  for(i=0; i<n; i++){
      sol[i]=peso(p, i);
      printf("%d\t", sol[i]);
  }
printf("\n");
  int *optimal=opt(p, sol, n);
  int max=0;
  for(i=0; i<n; i++){
      printf("%d\t", optimal[i]);
      if(optimal[i]>optimal[max])
        max=i;
  }
 
  printf("max: %d\n", optimal[max]);
 
  find_solution(p, sol, max, optimal);
 
 
  return 0;
}

#include <stdio.h>
#include <stdlib.h>
 
struct oggetto{
  int peso, valore;
};
 
typedef struct oggetto * Oggetto;
 
Oggetto new_oggetto(int peso, int valore){
  Oggetto new=malloc(sizeof(struct oggetto));
  new->peso=peso;
  new->valore=valore;
  return new;
}
 
void soluzioni( int m, int p, int zaino[p+1][m+1], Oggetto ogg[]){
  int i, j;
  for(j=1; j<=m; j++){
 
    for(i=1; i<=p; i++){
      zaino[i][j]=zaino[i][j-1];
    }
 
    for(i=(ogg[j-1]->peso); i<=p; i++)
      if(ogg[j-1]->valore>zaino[i][j])
        zaino[i][j]=ogg[j-1]->valore;
 
    for(i=1; i<=p; i++)
      if((i+ogg[j-1]->peso)<=p)
        zaino[i+ogg[j-1]->peso][j]=ogg[j-1]->valore+zaino[i][j-1];
 
  }
 
  return;
}
 
 
 
int main(){
  int p, j, i, peso, valore, m;
  m=0;
  printf("Numero di oggetti:");
  scanf("%d", &m);
 
  Oggetto *ogg=calloc(m, sizeof(Oggetto));
 
  for(i=0; i<m; i++){
    scanf("%d-%d", &peso, &valore);
    ogg[i]=new_oggetto(peso, valore);
  }
 
  printf("Peso zaino:");
  scanf("%d", &p);
 
  int zaino[p+1][m+1];
  for(j=0; j<=m; j++)
    for(i=0; i<=p; i++)
      zaino[i][j]=0;
 
  soluzioni(m, p, zaino, ogg);
 
  printf("La soluzione ottima e': %d\n", zaino[p][m]);
  return 0;
}

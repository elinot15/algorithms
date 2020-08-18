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
 
void soluzioni(int *zaino, int n, Oggetto *tipo, int p){
  int i, j, z;
  for(i=1; i<=p; i++){
    for(j=0; j<n; j++){
        if(tipo[j]->peso<=i)
          if(tipo[j]->valore>zaino[i])
            zaino[i]=tipo[j]->valore;
    }
 
    for(j=0; j<n; j++)
      if(zaino[i]+tipo[j]->valore>zaino[i+tipo[j]->peso])
        zaino[i+tipo[j]->peso]=zaino[i]+tipo[j]->valore;
 
    /*for(z=0; z<p; z++){
        printf("%d\t", zaino[z]);
    }
    printf("\n");*/
  }
 
  return;
}
 
 
int main(){
  int p, n, i, peso, valore;
 
  printf("Numero di tipi:");
  scanf("%d", &n);
 
  Oggetto *tipo=calloc(n, sizeof(Oggetto));
 
  for(i=0; i<n; i++){
    scanf(" %d %d", &peso, &valore);
    tipo[i]=new_oggetto(peso, valore);
  }
 
  printf("Peso zaino:");
  scanf("%d", &p);
 
  int *zaino=calloc(p+1, sizeof(int));
 
  soluzioni(zaino, n, tipo, p);
 
  printf("La soluzione ottima e': %d\n", zaino[p]);
  return 0;
}

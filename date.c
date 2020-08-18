#include <stdio.h> 

int main(){
	typedef struct{
		int giorno;
		int mese;
		int anno;
	} Data;
	
	Data d[100];
	int k=0;
	printf("Inserire il giorno: ");
    scanf(" %d" ,  &d[k].giorno);
    printf("Inserire il mese: ");
    scanf(" %d" , &d[k].mese);
    printf("Inserire il anno: ");
    scanf(" %d" , &d[k].anno);
while(d[k].giorno!=0 && d[k].mese!=0 && d[k].anno!=0){	
	k++;
	printf("Inserire il giorno: ");
    scanf(" %d" ,  &d[k].giorno);
    printf("Inserire il mese: ");
    scanf(" %d" , &d[k].mese);
    printf("Inserire il anno: ");
    scanf(" %d" , &d[k].anno);
    
	}
	
	int g1, m1, a1; 
    printf("giorno: ");
	scanf(" %d" , &g1);
	printf("mese: ");
	scanf(" %d" , &m1);
	printf("anno: ");
	scanf(" %d" , &a1);
	
    for(int i=0; i<k; i++){
	   if(d[i].anno< a1){
	   printf("%d/%d/%d \n" , d[i].giorno, d[i].mese, d[i].anno);
   }
   
    if(d[i].anno==a1 && d[i].mese<m1){
	   printf("%d/%d/%d \n" , d[i].giorno, d[i].mese, d[i].anno);
   }
   
   if(d[i].anno==a1 && d[i].mese==m1 && d[i].giorno<g1){
	    printf("%d/%d/%d \n" , d[i].giorno, d[i].mese, d[i].anno);
   }
   }
}
    /**versione 2
     int giorno[100];
     int mese[100];
     int anno[100];

int g, m, a, indice=0;
scanf(" %d" , &g);
scanf(" %d" , &m);
scanf(" %d" , &a);
while(g!=0 && m!=0 && a!=0){
	giorno[indice]=g;
    mese[indice]=m;
    anno[indice]=a;
    indice++;
	scanf(" %d" , &g);
    scanf(" %d" , &m);
    scanf(" %d" , &a);
   }
 
 int g1, m1, a1; 
scanf(" %d" , &g1);
scanf(" %d" , &m1);
scanf(" %d" , &a1);
   
   for(int i=0; i<indice; i++){
	   if(anno[i]< a1){
	   printf("%d/%d/%d \n" , giorno[i], mese[i], anno[i]);
   }
   
    if(anno[i]==a1 && mese[i]<m1){
	   printf("%d/%d/%d \n" , giorno[i], mese[i], anno[i]);
   }
   
   if(anno[i]==a1 && mese[i]==m1 && giorno[i]<g1){
	   printf("%d/%d/%d \n" , giorno[i], mese[i], anno[i]);
   }
   }
}*/



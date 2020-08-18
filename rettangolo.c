#include <stdio.h> 
#include <math.h>
#include <stdlib.h>
#define FALSO 0
#define VERO 1


	typedef  struct {
    int x, y;
	} Punto;
	
	typedef  struct {
	Punto p1 , p2;
	} Rettangolo;
    
	//Dati per argomenti due punti, creare e restituire una nuova struttura rettangolo;
	Rettangolo crea(Punto *p, Punto *q){
	Rettangolo r;
	r.p1=*p;
	r.p2=*q;
	return r;
	}
	
	//stampare i dati del rettangolo passato come argomento;
	void stampa(Rettangolo *r){
		printf("punto1: %d %d \n", (r->p1.x), (r->p1.y));
		printf("punto2:  %d %d \n",(r->p2.x),(r->p2.y));
	}
	
	//calcolare l’area del rettangolo passato come argomento;
	int area(Rettangolo *r){
	int b, h;
	b=abs((r->p2.x)-(r->p1.x));
	h=abs((r->p2.y)-(r->p1.y));
	return b*h;
	}
	
    //calcolare il centro (l’intersezione delle diagonali) del rettangolo passato come argomento;
	
	Punto centroDiagonali(Rettangolo *r){
	Punto p;
	p.x=(abs((r->p2.x)-(r->p1.x)))/2;
	p.y=(abs((r->p2.y)-(r->p1.y)))/2;
	return p;
	}
		
   //traslare il rettangolo passato come argomento di x unità nella direzione x e y unità nella direzione y;
	void traslaRet(Rettangolo *r, int x, int y){
	(r->p1.x)=(r->p1.x)+x;
	(r->p2.x)=(r->p2.x)+x;

	(r->p1.y)=(r->p1.y)+y;
	(r->p2.y)=(r->p2.y)+y;
    }
	
	//stabilire se un punto p cade dentro il rettangolo passato come argomento oppure no, restituendo VERO o FALSO.
	int dentro(Punto *p, Rettangolo *r){
		if((p->x)>=(r->p1.x)&&(p->x)<=(r->p2.x)&&(p->y)>=(r->p1.y)&&(p->y)<=(r->p2.y))
		return VERO;
		
		return FALSO;
		
	}
	
/**dalla scheda sull'allocazione in memoria, funzione che crei un nuovo rettangolo, 
*ne assegni i membri con dati inseriti dall’utente, e ne restituisca l’indirizzo; 
*la memoria necessaria va allocata dinamicamente usando la funzione malloc. */
void creaRet(Punto *p, Punto *q){
	Rettangolo r= malloc(100);
	r.p1=*p;
	r.p2=*q;
	return r;
	}
	

	int main(){
	
	Punto p1, p2;
	printf("Inserisci le coordinate dei due punti della diagonale del rettangolo: \n");
	scanf(" %d %d %d %d", &p1.x, &p1.y, &p2.x, &p2.y);

	Rettangolo r=crea(&p1, &p2);
	stampa(&r);
	
	printf("\n");
	printf("%d\n", area(&r));
	
	Punto centro=centroDiagonali(&r);
	printf("centro:%d, %d\n", centro.x, centro.y);
	
	traslaRet(&r, 1, 1);
	stampa(&r);
	printf("\n");
	
	Punto p;
	/*p.x=1.5;
	p.y=1.5;*/
	
	p.x=5;
	p.y=5;
	
	if(dentro(&p, &r))
		printf("VERO");
	else
		printf("FALSO");
	
	return 0;
}
		
		
		
		
		
		
		
		
		
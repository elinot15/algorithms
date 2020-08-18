#include <stdio.h> 
#include <math.h>
#include <stdlib.h>

int main(){
	typedef  struct {
	int x, y;
	} Punto;
	
	typedef  struct {
	Punto p1 , p2;
	} Rettangolo;
	
	typedef  struct {
	Punto cen ;
	float ra;
	} Cerchio;

	Rettangolo r;
	Cerchio c;
	
	printf("inserire x1 " );
	scanf(" %d", &r.p1.x);
	printf("inserire y1 " );
	scanf(" %d", &r.p1.y);
	printf("inserire x2 " );
	scanf(" %d", &r.p2.x);
	printf("inserire y2 " );
	scanf(" %d", &r.p2.y);
	
	printf("inserire cx " );
	scanf(" %d", &c.cen.x);
	printf("inserire cy " );
	scanf(" %d", &c.cen.y);
	printf("inserire raggio " );
	scanf(" %f", &c.ra);
	
	int diff1= r.p2.x - r.p1.x;
	int diff2= r.p2.y -r.p1.y;
	int lato1= abs(diff1);
	int lato2= abs(diff2);
	printf("Area cerchio %f \n",3.14*c.ra*c.ra );
	printf("Area rettangolo %d \n", 2*lato1 +2*lato2 );
	printf("Perimetro cerchio %f\n", 2*3.14*c.ra  );
	printf("perimetro rettangolo %d \n", lato1*lato2);
}

//gcc equazionesecondogrado.c -lm bisogna compilare scrivendo -lm per richiamare la libreria
# include <stdio.h>
#include <math.h>

int main ( void ) {
	int a,b,c,ris, ris2;
	
printf ("Inserisci intero a !\n");
scanf("%d" , &a);
printf ("Inserisci intero b !\n");
scanf("%d" , &b);
printf ("Inserisci intero c !\n");
scanf("%d" , &c);


ris= (-b +(sqrt(b*b -4.0*a*c)))/2.0 *a;
ris2= (-b -(sqrt(b*b -4.0*a*c)))/2.0 *a;
printf("%d \n", ris);
printf("%d \n", ris2);
return 0;
}

# include <stdio.h>
#include <math.h>

int main ( void ) {
	int a;
	int b;
	int c;
	int ris;
	int ris2;
	
printf ("Inserisci intero a !\n");
scanf("%d" , &a);
printf ("Inserisci intero a !\n");
scanf("%d" , &b);
printf ("Inserisci intero a !\n");
scanf("%d" , &c);

ris= (b +(sqrt(b*b -4*a*c)))/2 *a;
ris2= (b -(sqrt(b*b -4*a*c)))/2 *a;
printf("%d \n", ris);
printf("%d \n", ris2);
return 0;
}

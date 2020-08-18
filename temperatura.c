#include <stdio.h>

int main ( void ) {

	printf ("Inserisci intero !\n");
	int x;
	scanf("%d" , &x);
	x= (x-32)/1.8;
	printf("%d \n", x);
	return 0;
	
}

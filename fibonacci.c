#include <stdio.h>
//versione ricorsiva
int fibo(int n){
if(n==1)
return 1;

if(n==2)
return 1;

else
return fibo(n-1) + fibo(n-2);
}
/**versione non ricorsiva
int fibo(int n){
	int a=1;
	int b=1;
	int c;
	for(int i=3; i<=n; i++){
		c=a+b;
		a=b;
		b=c;
	}
	return b;
}*/

int main ( ) {
int n;
scanf(" %d", &n);
printf("risultato %d \n", fibo(n));

int somma=0;
for(int i=1; i<=n; i++){
somma= somma+fibo(i);	
}
printf("numero chiamata ricorsiva %d \n", somma);

}

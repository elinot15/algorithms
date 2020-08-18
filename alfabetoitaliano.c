#include <stdio.h>
#include <ctype.h>

int main(){
printf("inserisci un carattere: ");
char c;
scanf("%c", &c);
c= tolower(c);
if((c>= 'a' && c<='i') || (c>= 'l' && c<='v') || c=='z')
printf("carattere dell'alfabeto italiano \n");

else
printf("carattere dell'alfabeto straniero \n");
}

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
int main(){
printf("inserisci 2 caratteri: \n");
char uno;
char due;
scanf("%c \n", &uno);
scanf("%c", &due);

uno= tolower(uno);
due= tolower(due);

int diff= uno-due;
diff= abs(diff);
printf("%d \n" , diff);
}

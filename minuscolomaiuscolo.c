#include <stdio.h>
#include <ctype.h>
#define N 100

char *maiuscolo(char *stringa){
char *p= stringa;
while(*p!='0'){
	if(isalpha(*p)){
	*p=toupper(*p);
     }
     p+=1;
}
return stringa;
}

int main(){
char parola[N];
char b, i=0;
b=getchar();
while(b!='0'){
	parola[i]= b; //*(parola+i)= b è uguale
    i++;
    b=getchar();	
}
char *str= maiuscolo(parola);
char *p;

for(p=str; p<str+i; p++)
printf("%c", *p);
}

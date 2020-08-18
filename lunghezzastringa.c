#include <stdio.h>
#include <ctype.h>
#define N 100

int lung_stringa(char *s){
int conta=0;
char *ch= s;
while(*ch!='\0'){
conta++;
ch+=1;
}
return conta; 
}

int main(){
char parola[N]={'\0'};
char b;
int i=0;
b= getchar();
while(b!='\n'){
*(parola +i)= b;
  i++;
  b=getchar();
}

int ris= lung_stringa(parola);
printf("%d" , ris);

return 0;
}

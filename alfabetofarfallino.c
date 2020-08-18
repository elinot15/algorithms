#include <stdio.h> 
#include <stdlib.h>

int lung_stringa(char *s){
int conta=0;
char *ch= s;
while(*ch!='\0'){
conta++;
ch+=1;
}
return conta; 
}

int main(int argc , char *argv[]){
int lung= lung_stringa(argv[1]);
char *parola= argv[1];
char *p;
for(p=parola; p<parola+lung; p++){
int ris=0;
if(*p=='a' || *p=='e' || *p=='i' || *p=='o' || *p=='u'){
printf("%cf%c", *p, *p);
ris=1;
}

if(ris==0){
printf("%c", *p);
}
ris=0;
}
return 0;
}

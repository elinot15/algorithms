#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

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
char *p=parola;
int ris;
int dentro=0;
int due=0;
for(p; p<parola+lung; p++){
	ris=strcmp(p,p+1);
    if(ris>=0 && p==parola+lung-1){
    printf("%c", *p);
    dentro=1;
     }
     if(ris>=0 && dentro==0){
    printf("%c-", *p);
    due=1;
     }
    if(ris<0){
	printf("%c", *p); 
	 }
}
return 0;
}

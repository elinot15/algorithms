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
char *p, *q;
int ris=0;
		p= &parola[0];
		q= &parola[lung-1];
		while(p<=q){
			if(*p!=*q){
			printf("NON È PALINDROMA");
			ris=ris+1;
			break;	
			}
			p+=1;
			q-=1;
		}
		if(ris==0){
			printf("palindroma");
		}
		return 0;		
}



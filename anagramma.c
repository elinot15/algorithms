#include <stdio.h>
#include <ctype.h>

int main(){
	int car=0;
	int quantita[26];
	for(int i=0; i<26; i++){
		quantita[i]=0;
	}
	char ch= getchar();
	while(ch!='\n'){
		if(isalpha(ch)){
		ch=toupper(ch);
	    car= ch-65;
        quantita[car]=quantita[car]+1;
	}
	ch= getchar();
	
}

char cha= getchar();
	while(cha!='\n'){
		if(isalpha(cha)){
		cha=toupper(cha);
	    car= cha-65;
        quantita[car]=quantita[car]-11;
	}
	cha= getchar();
	
}
int ris=0;
printf("\n");
    for(int i=0; i<26; i++){
		if(quantita[i]>0){
         ris=ris+1;
	 }
 }
 
 if(ris==0){
 printf("ANAGRAMMA");
}
}

#include <stdio.h>
#include <ctype.h>

int main(){
	int car=0;
	int quantita[26];
	for(int i=0; i<26; i++){
		quantita[i]=0;
	}
	char ch= getchar();
	while(ch!='.'){
		if(isalpha(ch)){
		ch=toupper(ch);
	    car= ch-65;
        quantita[car]=quantita[car]+1;
	}
	ch= getchar();
	
}
    printf("\n");
    for(int i=0; i<26; i++){
		if(quantita[i]>0){
			printf("%c ", i+65);
			for(int j=0; j<quantita[i]; j++){
				printf("* ");
			}
			printf("\n");
		}
    
}
}

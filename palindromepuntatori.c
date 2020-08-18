#include <stdio.h> 

int main(){
	int ind=0;
	char *p, *q;
	char parole[100];
		char ch= getchar();
		
		while(ch!='.'){
			parole[ind]= ch;
			ind=ind+1;
			ch= getchar();
		}
		int ris=0;
		p= &parole[0];
		q= &parole[ind-1];
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

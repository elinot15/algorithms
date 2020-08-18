#include <stdio.h> 
#include <stdlib.h>
#include <ctype.h>

void *mymalloc(int size){
			int *p;
			p= malloc(size);
				if(p!=NULL)
				return p;
					
				printf("errore!!!");
				exit(EXIT_FAILURE);
				
			
	}


void *myrealloc(void *p, int size){	
		p= realloc(p, size);
		
		if(p!=NULL)
		return p;
					
		printf("errore!!!");
		exit(EXIT_FAILURE);
	}

char *read_line(void){
	int n=0, size=100;
	char ch= getchar();
	char *p;
	p=mymalloc(size);
	
	while((ch=getchar())!= EOF){
	if(n>=size){
	size= size+10;
    p= myrealloc(p, size);
	}
		
	if(ch=='\n'){
	p[n]='\0';
	break;
	}
	p[n++]=ch;
	
	}
	
	return p;
}

char *read_word(void){
	int n=0, size=100;
	char ch= getchar();
	char *p;
	p=mymalloc(size);
	
	while((ch=getchar())!= EOF){
	if(n>=size){
	size= size+10;
    p= myrealloc(p, size);
	}
		
	if(isalpha(ch)==0 && ch!='\n'){
	p[n]='\0';
	break;
	}
	p[n++]=ch;
	
	}
	
	return p;
	}


int main(){
char *q, *t;
q=read_line();
printf("%p", q);
t=read_word();
printf("%p", t);	
}




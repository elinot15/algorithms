#include <stdio.h> 
#include <stdlib.h>

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

	int main(){
	int *p, n=0, size=15, num;
	scanf(" %d", &num);
	p= mymalloc(size);
		while(num!=0){
		if(n>=size){
			size+10;
			p=myrealloc(p, size);

		}
	p[n++]= num;
	scanf(" %d", &num);			
	}
    
	int *i;
	for(i=p+n-1; i>=p; i--)
		printf("%d ", *i);
		
 return 0;
}
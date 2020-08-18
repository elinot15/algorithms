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
		int *p;
		
		p=mymalloc(15);
		printf("%p", p);
        
		printf("\n");
		myrealloc(p, 15);
		printf("%p", p);	
		
		return 0;
	}


#include <stdio.h>

int main(){
	int n;
	scanf("%d" , &n);
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(i==j)
			printf("| ");
			
			if(j>i)
			printf("+ ");
			
			if(j<i)
			printf("0 ");
		}
	printf("\n");
}
}
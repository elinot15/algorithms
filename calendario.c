#include <stdio.h>

int main(){
	int mese;
	int giorno;
	int conta=0;
	int g=1;
	
	printf(" numero mese: ");
    scanf("%d" , &mese);
    
    printf(" numero giorno inizio: ");
    scanf("%d" , &giorno);
    
	if(mese== 1 || mese== 3 || mese==5 || mese== 7 || mese== 8 || mese==10 || mese==12)
	conta= 31;
	if(mese== 4|| mese== 6 || mese==9 || mese== 11)
	conta=30;
	if(mese==2)
	conta=28;
	
	
	printf("L\tM\tM\tG\tS\tD");
	    for(int j=0; j<conta+giorno; j++){
	         if(j>=0 && j<=giorno){
	         printf("\t");
		 } 
	     if(j%6==0){
	     printf("\n");
	    }
	     if(j>= giorno){
	     printf("%d\t" ,g );
	     g++; 
	    }
	}
}

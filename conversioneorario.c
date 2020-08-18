#include <stdio.h>

int main(){
	int ore, minuti;
	printf("inserire le ore: ");
	scanf("%d" , &ore);
	printf("inserire i minuti: ");
	scanf("%d" , &minuti);

	if((ore>=1 && ore<=11)){
		printf("%d:%d AM \n" , ore, minuti);
	}
	if(ore==24){
	printf("0:%d AM \n", minuti);
	}

	if(ore>=13 && ore<=23){
		ore=ore-12;
		printf("%d:%d PM \n" , ore, minuti);
	}
	
	if(ore==12){
		printf("%d:%d PM \n" , ore, minuti);
	}
}

#include <stdio.h> 

int main(){
	int b, n;
	int base[100];
	int indice=0;
	scanf("%d %d",&b,&n);
	while(n!=0){
	base[indice]= n%b;
	indice= indice+1;
	n=n/b;
	}

	printf("\n");
	for(int j= indice-1; j>=0; j--)
	printf("%d" , base[j]);
}

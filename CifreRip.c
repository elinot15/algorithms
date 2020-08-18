#include <stdio.h>
#include <math.h>

int main(){
	
	int n, l, i, j=0;
	scanf("%d", &n);
	
	l=(int)(log10((double)(n)))+1;
	int a[10]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	
	for(i=0; i<l; i++){
		int k=(n%(int)(pow(10, i+1)))/pow(10, i);
		a[k]++;
	}	
		
	for(i=0; i<10; i++)
		if(a[i]>1){
			j=1;
			printf("%d : %d volte \n", i, a[i]);
		}
	
	if(j==0) 
		printf("Il numero non ha cifre ripetute");
	
	return 0;
}

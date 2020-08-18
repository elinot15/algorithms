#include <stdio.h>
#include <math.h> 

int main(){
	int n, l, i, j=0;
	scanf("%d", &n);
	l= (int)(log10((double) (n)))+1;
	int a[10]={0, 0, 0, 0, 0, 0, 0, 0 , 0, 0};
    for(int r=0; r<l; r++){
		int k= (n%(int)(pow(10, r+1)))/pow(10, r);
		    a[k]++;
	}

   for(int i=0; i<10; i++)
	if(a[i]>1){
		j=1;
		printf("%d  %d volte \n", i, a[i]);
	}
	
	if(j==0)
	printf("le cifre non si ripetono");
	
	return 0;
	
}

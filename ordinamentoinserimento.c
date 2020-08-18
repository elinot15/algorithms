#include <stdio.h>
#define N 100
int main(){	//n num j k indici i el 
	
	int n[N];
	int k=0, num, i, j;
	
	scanf("%d", &num);
	
	while(num!=0&&k<=100){
		if(k==0)
			n[0]=num;
		
		else{
			for(i=0; i<=k; i++)
				if(n[i]>num){
					for(j=k-1; j>=i; j--)
						n[j+1]=n[j];
					n[i]=num;
					break;
				}
			if(n[i]!=num)
				n[k]=num;
					
		}
		
		scanf("%d", &num);
		k++;
	}
	
	if(num==0)
		k--;
	
	for(i=0; i<=k; i++)
		printf("%d ", n[i]);
	return 0;

}

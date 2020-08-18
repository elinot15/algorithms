#include <stdio.h> 


void max_secondmax(int a[], int n, int *max, int *second_max){
	int *p;
	*max=0;
	*second_max=0;
	
	for(p=a; p<a+n; p++)
		if(*p>*max){
			*second_max=*max;
			*max=*p;
		}
}

int main(){
	
	int n=8;
	int a[]={0, 4, 8, 2, 6, 10, 7, 4};
	int max, second_max;
	
	max_secondmax(a, n, &max, &second_max);
	
	printf("%d, %d", max, second_max);
}

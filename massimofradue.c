#include <stdio.h>
#define N 100
void max_secondmax (int a[], int n, int *max, int *second_max){
	*max = a[0];
	*second_max = a[0];
	for(int i=1; i<n; i++){
		if(*max<a[i]){
		*max=a[i];
	}
	}
	
	for(int i=1; i<n; i++){
		if(*second_max<a[i] && a[i]!=*max){
		*second_max=a[i];
	}
	}
	
	
}


int main(){
int a[N];
int x, i=0;
scanf(" %d", &x);
while(x!=0){
	a[i]=x;
	i++;
	scanf(" %d", &x);
 }
int p=0, q=0;
max_secondmax(a, i, &p, &q);
printf("maggiore: %d, secondo %d", p, q);
}

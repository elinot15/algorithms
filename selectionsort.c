#include <stdio.h>
#define N 10

	void stampa(int a[] , int lung){
		for(int i=0; i<lung; i++){
		printf("%d ", a[i]);
	}
	}
	
	void scambia(int a[] , int i , int j){
		int temp=a[i];
		a[i]= a[j];
		a[j]=temp;
	}
	
	void selectionsort(int a[] , int n){
		int i=0;
		int max= a[i];
		for(int j=1; j<n; j++){
			if(max < a[j]){
			max= a[j];
			i=j;
		}
		}
		scambia(a, i, n-1);
		stampa (a , N);
		printf("\n");
		if(n<=1)
		return;
		
		else
		selectionsort(a, n-1);
	}
	
int main( ){
	int a[N], temp;
	for(int i=0; i<N; i++){
		printf("inserisci un intero: ");
		scanf(" %d", &temp);
		a[i]= temp;
	}
	selectionsort(a, N);
	stampa (a , N);
	return 0;
}


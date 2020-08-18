#include <stdio.h> 
#define N 10
void scambia (int a[], int i, int j){
	int temp=a[i];
	a[i]= a[j];
	a[j]=temp;
}

void stampa(int a[], int lung){
for(int i=0; i<lung; i++){
printf("%d ", a[i]);
}
}

    int[] unisci(int b[], int c[]){
	int d[N];
	int lungb= (N/2)-1;
	int lungc= (N/2)-1; 
	int i1=0;
	int i2=0;
	int k=0;
	
	while(i1< lungb && i2<lungc){
		if(b[i1]<c[i2]){
			d[k]= b[i1];
			i1++;
		}
		else{
			d[k]= c[i2];
			i2++;
		}
		k++;
	}
	
	if(i1< lungb){
	for(int j=i1 ; j< -1; j++){
		d[k]= b[i1];
		k++;
	}
    }
    
    if(i2< lungc){
	for(int j=i2 ; j< -1; j++){
		d[k]= c[i2];
		k++;
	}
    }
    return d;
}

void mergeSort(int a[]){
	if(N>1){
	int m=N/2;
	int b[m-1];
	int c[m-1];
	for(int i=0; i<=m-1; i++){
		b[i]= a[i];
	}
	for(int j=m; j<N; j++){
		int t=0;
		c[t]= a[j];
		t++;
	}
	
	mergeSort(b);
	mergeSort(c);
	a=unisci(b, c);
}
}

	int main( ){
	int a[N], temp;
	for(int i=0; i<N; i++){
		printf("inserisci un intero: ");
		scanf(" %d", &temp);
		a[i]= temp;
	}
	mergeSort(a);
	stampa (a , N);
	return 0;
}

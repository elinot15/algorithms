#include <stdio.h> 

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

int main(){
int lung;
int temp;
printf("lunghezza array: ");
scanf(" %d", &lung);
int a[lung];
for(int i=0; i<lung; i++){
printf("inserisci un intero: ");
scanf(" %d", &temp);
a[i]= temp;
}
stampa(a, lung);
printf("\n");
scambia(a, 2, 4);
stampa(a, lung);
}

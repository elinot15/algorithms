/**#include <stdio.h>

int main(void){
	int n;
	printf("inserisci la dimensione del quadrato: ");
	scanf(" %d", &n);
	int i=0; 
	int j=n/2;
	int matrice[n][n];
	matrice[i][j]=1;
	int k=2;
 
   for(k=2; k<n*n+1; k++){
       i=i-1;
	   j=j+1;
	   if(i<0){
		   i=n-1;
	   }
	   if(j==n){
		 j=0;  
		}
		if(matrice[i][j]>0 && matrice[i][j]<n*n+1){
		i=i+2;
		j=j-1;
		if(i>n-1){
			i=i%n;
		}
		if(j<0){
			j=n-1;
		}
	}
		matrice[i][j]=k;
}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			printf("%d\t", matrice[i][j]);
		}
		printf("\n");
	}

}*/
#include <stdio.h>
#include <math.h>

void quadrato_magico(int n){
	int quad[100][100] = {}, cont, r = 0, c = n / 2;
	quad[r][c] = 1;

	for(cont = 2; cont <= n * n; cont++){
		if(quad[(r - 1 + n) % n][(c + 1) % n] == 0){
			r = (r - 1 + n) % n;
			c = (c + 1) % n;
			quad[r][c] = cont;
		}
		else{
			r = (r + 1) % n;
			quad[r][c] = cont;
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			for(int k = log10(n*n); k > log10(quad[i][j]); k--)
				printf(" ");
			printf("%d ", quad[i][j]);
		}
		printf("\n");
	}

}

void main(){
	int n;
	printf("Inserisci la dimensione del quadrato: ");
	scanf("%d", &n);
	quadrato_magico(n);
}


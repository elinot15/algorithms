#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 10

int main(){

	char p[N][N];
	int i, j, k=1;
	int rnd;
	rnd=rnd%4;
	
	enum {UP, DOWN, DX, SX};
	
	char ch='A';
	
	for(i=0; i<N; i++)
		for(j=0; j<N; j++)
			p[i][j]='.';
		
	p[0][0]=ch;
	srand(time(NULL));
	int c=0, r=0;
	
	do{
		if(p[r+1][c]!='.'&&p[r-1][c]!='.'&&p[r][c+1]!='.'&&p[r][c-1]!='.')
			break;
		rnd=rand()%4;
		
		switch(rnd){
			case UP:	r--;
						break;
			case DOWN:	r++;
						break;
			case DX:	c++;
						break;
			case SX:	c--;
						break;
		}
		
		if(c<0||r<0||c>=N||r>=N||p[r][c]!='.'){
			switch(rnd){
			case UP:	r++;
						break;
			case DOWN:	r--;
						break;
			case DX:	c--;
						break;
			case SX:	c++;
						break;
			}
			
			
			continue;
		}
		ch++;
		p[r][c]=ch;
		k++;

	}while(ch<'Z');
	
	for(i=0; i<N; i++){
		for(j=0; j<N; j++)
			printf("%c ", p[i][j]);
		printf("\n");
	}
}
/**#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 10

int main(){
	char matrice[10][10];
	int k=0;
	
	for(int i=0; i<10; i++){
		for(int j=0; j<10; j++){
			matrice[i][j]= '.';
		}
	}
	
	for(int i=0; i<10; i++){
		for(int j=0; j<10; j++){
		if(i==0 && j==0){
		matrice[0][0]= 'A'+k;
	    }
	    else{
			
		}
		k++;
	}
}

	for(int i=0; i<10; i++){
		for(int j=0; j<10; j++){
			printf("%c ", matrice[i][j]);
		}
		printf("\n");
	}
}
*/

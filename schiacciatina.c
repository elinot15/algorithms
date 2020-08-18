#include <stdio.h> 

int main(){
int r, s;
char ch;
scanf(" %d",&r);
scanf(" %d",&s);
char matrice[r][s];
for(int k=0; k<r ; k++){
	for(int v=0;v<s; v++){
		scanf(" %c" , &ch);
		matrice[k][v]= ch;
	}
}


    for(int i=0; i<s ; i++)
		for(int j=r-1; j>=0; j--)
			if(matrice[j][i]=='*')
			for(int h= j-1; h>=0; h--)
				if(matrice[h][i]!='*'){
				matrice[j][i]= matrice[h][i];
				matrice[h][i]= '*';
			    break;
			}
		    
		
    printf("\n");
    for(int i=0; i<r ; i++){
	for(int j=0; j<s; j++){
	char c= matrice[i][j];
		printf("%c ",c);
	}
	printf("\n");
}
return 0;
}

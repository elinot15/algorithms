#include <stdio.h> 

int main(){
	int n;
	int voti [5][5];
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
		scanf("%d ", &n);
		voti[i][j]=n;	
		}
	}
	
	float esame1, esame2, esame3, esame4, esame5;
	float studente1, studente2, studente3, studente4, studente5;
	
	for(int k=0; k<5; k++){
		esame1= esame1+ voti[k][0];
	}
	esame1= esame1/5;
	printf("%.2f \n", esame1);
	
	for(int k=0; k<5; k++){
		esame2= esame2+ voti[k][1];
	}
	esame2= esame2/5;
	printf("%.2f \n", esame2);
	
	for(int k=0; k<5; k++){
		esame3= esame3+ voti[k][2];
	}
	esame3= esame3/5;
	printf("%.2f \n", esame3);
	
	for(int k=0; k<5; k++){
		esame4= esame4+ voti[k][3];
	}
	esame4= esame4/5;
	printf("%.2f \n", esame4);
	
	for(int k=0; k<5; k++){
		esame5= esame5+ voti[k][4];
	}
	esame5= esame5/5;
	printf("%.2f \n", esame5);
	
	printf("\n");
	for(int k=0; k<5; k++){
		studente1=studente1+ voti[0][k];
	}
	studente1= studente1/5;
	printf("%.2f \n",studente1);
	
	for(int k=0; k<5; k++){
		studente2= studente2+ voti[1][k];
	}
	studente2= studente2/5;
	printf("%.2f \n", studente2);
	
	for(int k=0; k<5; k++){
		studente3= studente3+ voti[2][k];
	}
	studente3= studente3/5;
	printf("%.2f \n", studente3);
	
	for(int k=0; k<5; k++){
		studente4= studente4 + voti[3][k];
	}
	studente4= studente4/5;
	printf("%.2f \n", studente4);
	
	for(int k=0; k<5; k++){
		studente5= studente5+ voti[4][k];
	}
	studente5= studente5/5;
	printf("%.2f \n", studente5);
	
}

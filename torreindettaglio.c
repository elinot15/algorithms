#include <stdio.h>
#include <string.h>

char torre[3][64] = {};

void hanoi(int n, int from, int temp, int to){
	if(n == 1){
		torre[to][strlen(torre[to])] = torre[from][strlen(torre[from]) - 1];
		torre[from][strlen(torre[from]) - 1] = '\0';
		printf("%s, %s, %s\n", torre[0], torre[1], torre[2]);
	}
	else{
		hanoi(n - 1, from, to, temp);
		torre[to][strlen(torre[to])] = torre[from][strlen(torre[from]) - 1];
		torre[from][strlen(torre[from]) - 1] = '\0';
		printf("%s, %s, %s\n", torre[0], torre[1], torre[2]);
		hanoi(n - 1, temp, from, to);
	}
}

void main(){

	int altezza;
	printf("Altezza: ");
	scanf("%d", &altezza);
	for(int i = 0; i < altezza; i++)
		torre[0][i] = 'A' + i;
	printf("%s, %s, %s\n", torre[0], torre[1], torre[2]);
	hanoi(altezza, 0, 1, 2);
}

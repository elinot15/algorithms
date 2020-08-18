#include <stdio.h>
void hanoi(int n, int from, int temp, int to){
	if(n == 1)
		printf("%d -> %d\n", from, to);
	else{
		hanoi(n - 1, from, temp, to);
		printf("%d -> %d\n", from, to);
		hanoi(n - 1, temp, from, to);
	}

}

void main(){
	int altezza;
	printf("Altezza: ");
	scanf("%d", &altezza);
	hanoi(altezza, 0, 1, 2);
}

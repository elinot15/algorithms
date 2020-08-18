#include <stdio.h>
#include <math.h>
long long int mosse;

void hanoi(int n, int from, int temp, int to){
	mosse++;
	if(n != 1){
		hanoi(n - 1, from, to, temp);
		hanoi(n - 1, temp, from, to);
	}
}

void main(){

	for(int i = 1; i <= 64; i++){
		mosse = 0;
		hanoi(i, 0, 1, 2);
		printf("Con %d anelli hai bisogno di %lld mosse, cioè 2^%d - 1 mosse\n", i, mosse, (int)log2(mosse + 1));
	}
}

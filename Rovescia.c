#include <stdio.h> 

int main(){
	int array[100];
	int n;
	int i=0;
	scanf("%d" , &n);
   
    while(n!=0){
    array[i]= n;
    i=i+1;
    scanf("%d" , &n);
    }
	printf("\n");
	for(int j=i-1; j>=0; j--)
	printf("%d \n" , array[j]);
}
	

#include <stdio.h> 
#define N 100
int main(){
	int array[N];
	int b;
	int i=0;
	int *p;
	scanf(" %d" , &b);
   
    while(b!=0){
    array[i]= b;
    i=i+1;
    scanf(" %d" , &b);
    }
	printf("\n");
	
	for(p=&array[i-1] ; p>=&array[0]; p-=1)
	printf("%d \n" , *p);
	
	return 0;
}

/**altro modo
 * 
int main(){
	
	int num[N];
	int n, i=0, *p;
	scanf(" %d", &n);
	
	while(n!=0){
		*(num+i)=n;
		i++;
		scanf(" %d", &n);
	}
	
	
	for(p=num+i; p>=num; p--)
		printf("%d \n", *p);

	return 0;
}*/

#include <stdio.h> 

int *smallest(int a[], int n){
int *p, *q;
q= a;
int conta=0;
for(p=a; p<a+n; p++){
    if(*p<*q)
    q=p;
}

return q;
}

int main(){
int n=8;
	int a[]={66, 4, 8, 1, 6, 10, 7, 4};
	int *ris= smallest(a, n);
	printf("%d ", *ris);


}

#include <stdio.h>

int main(){
int a,b,c, boolean;
scanf("%d %d %d", &a, &b, &c);

if(((a+b)<c) || ((a+c)<b) || ((c+b)<a))
printf("non è un triangolo");

else{
	if(a==b && b==c){
		printf("triangolo equilatero \n");
        boolean=1;
	}
	if(a!=b && b!=c){
		printf("triangolo scaleno \n");
		 boolean=1;
	}
	if(boolean!=1){
	printf("triangolo isoscele \n");	
	}
	
}

}

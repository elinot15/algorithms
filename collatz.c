#include <stdio.h>

int col(int n) {
	int ris;
if(n%2==0){
ris=n=n/2;
}
else{
ris=(n*3)+1;
}
return ris;
}

int main ( ) {
int num;
int conta=0;
scanf("%d", &num) ;
for( ; ; ){
	if(num==1)
	break;
	
	else 
    num= col(num);
    printf("%d ", num) ;
    conta=conta +1;
}
printf("\n ripetizione %d", conta) ;
}

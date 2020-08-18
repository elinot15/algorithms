#include <stdio.h>

int main(){
int x;
int indice = 2;
printf("inserire un intero: ");
scanf("%d" , &x);
printf("1 ");

while(x > 1) {
    if(x % indice == 0) {
        x = x/indice;
        printf("%d ", indice);
    }
    else
        indice++;
}
}

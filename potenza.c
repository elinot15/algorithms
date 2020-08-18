#include <stdio.h>
#include <math.h>

int pot(int b, int e){
int ris= pow(b, e);
return ris;
}

int main(){
int base, indice;
scanf("%d%d", &base, &indice);
printf("%d", pot(base, indice));

}

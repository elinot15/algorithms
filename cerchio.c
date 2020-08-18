#include <stdio.h>
#include <math.h>

int main(){
float raggio;
printf("inserisci il valore del raggio del cerchio: ");
scanf("%f", &raggio);
float area;
area= raggio*raggio*M_PI;
printf("%.2f \n" , area);
}

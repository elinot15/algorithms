#include <stdio.h>
#include <stdlib.h>

int main(){
int ore1, ore2, minuti1, minuti2, secondi1, secondi2 ;
scanf("%d %d %d" , &ore1, &minuti1, &secondi1);
scanf("%d %d %d" , &ore2, &minuti2, &secondi2);

//if(((ore1>=0 && ore1<=24) && (ore2>=0 && ore2<=24) && (minuti1>=0 && minuti1<=59) && (minuti2>=0 && minuti2<=59) && (secondi1>=0 && secondi1<=59) && (secondi2>=0 && secondi2<=59))){
int risore= abs(ore1-ore2);
int risminuti= abs(minuti1-minuti2);
int rissecondi= abs(secondi1-secondi2);
printf("%d : %d : %d \n" ,risore, risminuti, rissecondi);
printf("%d ", ore1);
printf("%d " , minuti1);
printf("%d " , secondi1);

printf("%d ", ore2);
printf("%d " , minuti2);
printf("%d " , secondi2);


//}
//else
//printf("valori non validi");

}

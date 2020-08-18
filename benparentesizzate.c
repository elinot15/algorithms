#include <stdio.h>

int main(){
	int aperte=0;
	int chiuse=0;
	int car=0;
	int segna=0;
	char ch=getchar();
    while (ch!= '.'){
		car=car+1;
	if(ch =='('){
		aperte++;
	}
	
	if(ch ==')'){
	 chiuse++;
	}
	
	if(aperte<chiuse){
		segna=car;
	printf("la stringa NON è un'espressione ben parentessizzata \n");
	printf("Carattere %d: troppe parentesi chiuse!", segna);
	break;
	}
	
	ch=getchar();
}
	
	if(aperte==chiuse)
	printf("la stringa è un'espressione ben parentessizzata");
	
	if(aperte>chiuse){
	printf("la stringa NON è un'espressione ben parentessizzata \n");
	printf("Carattere %d: mancano le parantesi chiuse!", car);
    }
    

}

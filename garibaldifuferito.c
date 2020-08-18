#include <stdio.h> 

char metodo(char uno, char due){
char ris;
if(due== 'a' || due== 'e' || due== 'i' || due== 'o' || due== 'u'){
ris= uno;
}
else{
	ris=due;
}
return ris;
}

int main(){
char ch;
ch= getchar();
char chiave=ch;
ch= getchar();
while(ch!='.'){
ch= getchar();
if(ch!='.'){
printf("%c", metodo(chiave, ch));
}
}
}

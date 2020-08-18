#include <stdio.h>
#include <ctype.h>

int main(){
	int n;
	int diff;
	scanf("%d" , &n);
	
	char ch=getchar();
    while (ch!= '.'){
	if(isalpha(ch)){
	if(isupper(ch)!=0){ //maiuscolo
      diff= ch+n-'Z'; 
      if(diff<=0){
       ch= ch+n;
   }
   
   if(diff>0){
    ch= 'A'+diff-1;   
   }
	}
	
	if(isupper(ch)==0){
		diff= ch+n-'z';
		
		if(diff<=0){
       ch= ch+n;
   }
    if(diff>0){
    ch= 'a'+diff-1;   
   }
	}
	
	    
	printf("%c" , ch);
    }

    else
    printf("%c" , ch);
    
    ch=getchar();
    }
}


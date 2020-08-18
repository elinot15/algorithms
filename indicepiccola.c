#include <stdio.h>
#include <string.h>

int lung_stringa(char *s){
int conta=0;
char *ch= s;
while(*ch!='\0'){
conta++;
ch+=1;
}
return conta; 
}

int smallest_word_index(char *s[], int n ){
int i=0;
char *min= s[0];
int lm= lung_stringa(min);
for(int j=1; j<n; j++){	
    int lung= lung_stringa(s[j]);
    if(lm>lung){
    min= s[j];
    lm=lung;
    i=j;   
    } 
    
    if(lm==lung){
    int ris=strcmp(min,s[j]);
    if(ris>=0){
    min= s[j];
    lm=lung;
    i=j;  
    }
    }
}
return i;
}

int main(){
char *dict[] = { "ciao", "mo", "come", "funziona", "bene", "questo", "p", "a" };
int lun = 8, pos;
pos = smallest_word_index( dict, lun );
printf( "La parola minima si trova in posizione %d.\n", pos );
return 0;
}

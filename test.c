#include <stdio.h>

 
 
int main(){
  int r=0,c,i, DIMENSIONE;
printf("inserisci la dimensione del quadrato: ");
scanf(" %d", &DIMENSIONE);
int quadrato[DIMENSIONE][DIMENSIONE];

        c=DIMENSIONE/2;
 
        quadrato[r][c]=1;
 
        for(i=1;i<(DIMENSIONE*DIMENSIONE);i++){
                r--;
                if(r<0)
                        r=DIMENSIONE-1;
                c++;
                if(c>(DIMENSIONE-1))
                        c=0;
               
                if(quadrato[r][c]==0){
                        quadrato[r][c]=i+1;
}
                else{
 
                        r=r+2;
                        if(r==(DIMENSIONE))
                                r=0;
                        else if(r==(DIMENSIONE+1))
                                r=1;
 
                        c--;
                        if(c<0)
                                c=DIMENSIONE-1;
 
                        quadrato[r][c]=i+1;
                       
                }
        }
 
        for(r=0;r<DIMENSIONE;r++){
                for(c=0;c<DIMENSIONE;c++){
                printf("%d\t", quadrato[r][c]);
                }
        printf("\n");
        }
       
        return 0;
}

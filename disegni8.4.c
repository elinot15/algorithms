#include <stdio.h>

int main(){
int n;
scanf("%d" , &n);

int r= n+1;
for(int i=0; i<n; i++){
	for(int j=0; j<n+2; j++){
       if(j==r){
       printf("*");	
      }
      if(i== n-3 && j==0){
      printf("*");
      j++;	
	  }
	  
	  if(i== n-2 && j==1){
      printf("*");	
	  }
	  
      else
		  printf(".");	
	}
	r--;
	printf("\n");
}

}

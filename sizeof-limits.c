#include <stdio.h>
#include <limits.h>
int main ( void ) {
printf ("%d ..% d\n", INT_MIN , INT_MAX) ;
printf("%ld \n" , sizeof(INT_MIN));

printf ("%c ..% d\n", SCHAR_MIN , SCHAR_MAX) ;
printf("%ld \n" , sizeof(SCHAR_MIN));

printf ("%c\n", UCHAR_MAX) ;
printf("%ld \n" , sizeof(UCHAR_MAX));

printf ("%d ..%d \n", SHRT_MIN, SHRT_MAX) ;
printf("%ld \n" , sizeof(SHRT_MAX));

printf ("%d\n", USHRT_MAX) ;
printf("%ld \n" , sizeof(USHRT_MAX));

printf ("%ld ..%ld \n", LONG_MIN, LONG_MAX) ;
printf("%ld \n" , sizeof(LONG_MAX));



return 0;
}

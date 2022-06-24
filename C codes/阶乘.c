#include <stdio.h>
#include <math.h>
int main ()
{
	int a, j, jc = 1;
	scanf ("%d",&j); 
	for ( int a = 1; a <= j; ++a) {
		jc *= a;
	}
       
    printf ("%d", jc);   
}

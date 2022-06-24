#include <stdio.h>
#include <math.h>
int main()
{
	int a,b,c;
	float x1,x2,x3;
	scanf("%d %d %d",&a,&b,&c);
	if (a == 0)
	{
		x2 = (double) ((-c)/b);
	 	if ( x2 <= 15 && x2 > 0 ) printf("%.3f", x2); else printf("ƒ„TM’“≤Á «∞…");
	}
	 
	if (a != 0)
	{
		if (b*b - 4 * a*c>=0)
		{
		 x1 =(-b - sqrt(b*b - 4 * a*c)) / (2 * a);
	 	 x2 =(-b + sqrt(b*b - 4 * a*c)) / (2 * a);
	 	 if ( x2 >= x1 ) x3=x2;
	 	 else x3=x1;
		 if ( x3 <= 15 && x3 > 0 )  printf("%.3f", x3); else printf("ƒ„TM’“≤Á «∞…");
		  
		 
	    }
	    if (b*b - 4 * a*c<0)
	    {
	     printf("ƒ„TM’“≤Á «∞…");
		}
	}
}

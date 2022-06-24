#include <stdio.h>
#include <math.h>

int main() 
{
	int n = 0;	
	int a, b;
	scanf ("%d",&n) ;
	int start = 1;
	for ( int i = 1; i < n; i++){
		start *= 10;                            //控制初始和结束值 start    
	}
	for ( int t = start; t < start * 10; t++){  //生成测试数值 t   
		int sum = 0;    //sum=幂的和   
		for ( int j = 1; j <= n; j++){
			int c, d;
			c = pow ( 10, j - 1);
			a = ((t / c) % 10);
			b = pow ( a, n);
			sum += b;
			//if ( sum == t )
			//printf ("%d\n", t);
			//printf ("%d\n", b);
			//printf ("%d\n", sum);
		}	
		if ( sum == t )
		printf ("%d\n", t);	
	}	
}
	 


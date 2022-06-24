/*code information
  writen by George·Dong 
  code version 1.1 Beta*/ 

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int max (int a, int b);

int main()
{
	int len = 0; int peak = 0;
	int i; int control = 0;
	scanf ("%d",&len);
	scanf ("%d",&peak);
	int a[len];
	for (i = 0; i < len; i++)
	{
		scanf ("%d",&a[i]);
	}
	//仅直角三角形 
	if (peak == 0)
	{
		for (control = 0; control < len; control++)
		{
			for (i = 0; i <len-1; i++)
			{
				int exchange = max (a[i],a[i+1]);
				if (exchange == a[i+1]){
					exchange = a[i];
					a[i] = a[i+1];
					a[i+1] = exchange;
				}
			}
		}	
	}
	else if (peak == len -1)
	{
		for (control = 0; control < len; control++)
		{
			for (i = 0; i <len-1; i++)
			{
				int exchange = max (a[i],a[i+1]);
				if (exchange == a[i]){
					exchange = a[i+1];
					a[i+1] = a[i];
					a[i] = exchange;
				}
			}
		}
	}
	//输出等腰三角（+直角）
	else if (peak != 0 && peak != len -1) { 
		int l = peak - 1; int r = peak + 1; 
		//整理出升序数组
		int b[len];
		for (i = 0; i<len; i++)
		{
			b[i] = a [i];
		} 
		for (control = 0; control < len; control++)
		{
			for (i = 0; i <len-1; i++)
			{
				int exchange = max (b[i],b[i+1]);
				if (exchange == b[i]){
					exchange = b[i+1];
					b[i+1] = b[i];
					b[i] = exchange;
				}
			}
		}
		//输出等腰三角
		int c = len -2;   //控制变量 
		a[peak] = b[len-1];
		while (l >= 0 && r < len)
		{
			a[l] = b[c];
			c--;
			a[r] = b[c];
			c--;
			r++; l--;
		}
		
		//输出剩余直角
		if (l == -1)
		{
			while (r<len){
				a[r] = b[c];
				r++; c--;
			}
		}
		else if (r == len)
		{
			while (l >= 0){
				a[l] = b[c];
				l--; c--;
			}
		}
	} 
	//输出 
	for (i = 0; i < len; i++){
		printf ("%d ", a[i]);
	}
	return 0;
}

int max (int a, int b)
{
	if (a >= b) return a;
	else return b;
}

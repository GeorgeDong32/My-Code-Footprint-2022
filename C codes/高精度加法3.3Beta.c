/*
Code Information
  <高精度加法>
  Written by George·Dong
  Code Version 3.3 final 
*/ 
 
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
int sti(char n);
char plus(char a, char b,int* lcp);
char stc(int a);
void reverseorder(char a[]);

int main ()
{
	//输入阶段 
	char a[110]; char b[110];
	scanf ("%s %s",a,b);
	//计算阶段 
	char result[110]; int weishu = 0; int i = 0;
	char bo[110]; char so[110]; int len = 0;
	int lb = 0; int ls = 0;
	//重排数组
	int wa = strlen(a);
	int wb = strlen(b);
	if (wa >= wb) 
	{
		for (i = 0; i < wa; i++)
		{
			bo[i] = a [i];
		}
		lb = i;
		for (i = 0; i < wb; i++)
		{
			so[i] = b [i];
		}
		ls = i;
		len = wa;
	}
	else if (wb > wa)
	{
		for (i = 0; i < wb; i++)
		{
			bo[i] = b [i];
		}
		lb = i;
		for (i = 0; i < wa; i++)
		{
			so[i] = a [i];
		}
		ls = i;
		len = wb;
	}
	//计算 
	int cp = 0;  //进位控制符 
	for (i = 0; i <= len; ++i)//计算结果倒序进入数组 
	{
		//printf("%d",cp);
		if (i == len)
		{
			if (cp == 1) result[i]='1';
			else result[i] -= result[i];
		}
		if (ls > 0)
		{
			result[i] = plus(bo[lb-1],so[ls - 1], &cp);
			lb--; ls--;
		}
		else if (ls <= 0 && lb > 0)
		{
			result[i] = plus(bo[lb-1],'0',&cp);
			lb--;
		}
		//printf ("result[%d]=%c\n",i,result[i]);
	}
	reverseorder(result); 
	//输出
	printf ("%s\n",result);
}

void reverseorder(char a[]) //倒序重排函数 
{
	int lena = 0;
	lena = strlen (a);
	char b[lena];
	int i = 0;
	for (i = 0; i < lena ;i++)
	{
		b[lena-1-i] = a[i];
	}
	for (i = 0; i < lena; i++){
		a[i]= b[i];
	}
	
}

char plus(char a, char b,int* lcp)
{
	int r = sti(a)+sti(b) + *lcp;
	*lcp = 0;
	if (r < 10 && r>= 0)  
		return stc(r);
	else if (r >= 10)
	{
		*lcp = 1;
		//printf("cp = %d\n",*lcp);
		return stc(r%10);	
	}
	
}

int sti(char n)
{
	switch(n){
		case '1':
			return 1;
		case '2':
			return 2;
		case '3':
			return 3;
		case '4':
			return 4;
		case '5':
			return 5;
		case '6':
			return 6;
		case '7':
			return 7;
		case '8':
			return 8;
		case '9':
			return 9;
		case '0':
			return 0;
	}
}

char stc(int a)
{
	switch(a)
	{
		case 0 :
			return '0';
		case 1 :
			return '1';
		case 2 :
			return '2';
		case 3 :
			return '3';
		case 4 :
			return '4';
		case 5 :
			return '5';
		case 6 :
			return '6';
		case 7 :
			return '7';
		case 8 :
			return '8';
		case 9 :
			return '9';
	}
}

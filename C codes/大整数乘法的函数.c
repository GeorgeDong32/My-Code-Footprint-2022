/*
Code Information
  <大整数乘法>
  Written by George·Dong
  Code Version 1.4 Beta 
*/ 
#include <stdio.h>
#include <string.h>
#include <math.h>
	

//函数区
void revStr(char a[])
{
	int len = strlen(a);
	int ec; int count = 0;
	int lc = 0; int rc = len -1;
	while (count < len / 2)
	{
		ec = a[lc];
		a[lc] = a[rc];
		a[rc] = ec;
		lc++; rc--;
		count ++;
	}
}             //checked

char stc(int a)
{
	switch (a)
	{
		case 1:
			return '1';
		case 2:
			return '2';
		case 3:
			return '3';
		case 4:
			return '4';
		case 5:
			return '5';
		case 6:
			return '6';
		case 7:
			return '7';
		case 8:
			return '8';
		case 9:
			return '9';
		case 0:
			return '0';
	}
}

int sti(char a)
{
	switch (a)
	{
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

char* multiply(const char* num1, const char* num2)
{
	char* re= (char*)malloc(sizeof(char)*11000); int j = 0;
	for (j = 0; j < 11000; j++) re[j] = 0;
	//准备阶段(大数前置) 
	int ln1 = strlen(num1); int ln2 = strlen(num2);
	int lu = fmax(ln1,ln2); int ld = fmin(ln1,ln2);
	char up[lu+2]; char down[ld+2];
	int upc; int doc;
	if (ln1 >= ln2)
	{
		int i;
		for (i = 0;i < ln1; i++)	up[i] = num1[i]; upc = i-1;
		for (i = 0; i < ln2; i++)	down[i] = num2[i]; doc = i-1;
	}
	else if (ln2 > ln1)
	{
		int i;
		for (i = 0; i < ln2; i++)	up[i] = num2[i]; upc = i-1;
		for (i = 0; i < ln1; i++)   down[i] = num1[i]; doc = i-1;
	}
	//计算阶段
	int i = 0; int rec = 0; int opt = 0; int pir = 0; int pmax = 0;
	int rm = 0; int ben; int jin = 0; int now;
	for (;doc >= 0; doc--)
	{
		pir = 0 + opt;
		for (i = upc; i >= 0;i--)
		{
			rm = sti(down[doc]) * sti(up[i]) + jin;
			if (opt == 0) now = rm;
			else 
			{
				if (pir <= pmax) now = rm + sti(re[pir]);
				else now = rm;
			}
			jin = 0;
			ben = now % 10;
			jin = now / 10;
			re[pir] = stc(ben);
			pmax = fmax(pmax,pir);
			pir++;
		}
		if (jin != 0) 
		{
			re[pir] = stc(jin); 
			pmax++;
		}
		opt++;
		jin = 0;
	}
	//返回阶段
	revStr(re);     //翻转矩阵 
	return re;
}

int main()
{
	char a[110]; char b[110];
	char* c = NULL;
	scanf("%s",a);
	scanf("%s",b);
	c = multiply(a,b);
	printf("%s",c);
	return 0;
 } 

/*
Code Information
  <加密文书>
  Written by George·Dong
  Code Version 1.4 Beta 
  
Bug List
*/ 

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
void reverse(char* a,int start,int end);    //解密操作函数 
int sti(char c);
void removenum(char* a,int pnum,int* plen);

int main ()
{
	//定义&输入 
	char ciphertext[110];     //密文数组 
	char plaintext[110];      //明文数组 
	gets (ciphertext);
	int len = strlen(ciphertext); 
	int i = 0; int flag = 0; int np = 1;
	int start = 0; int end = 0;
	//解密 
	for (i = 0; i < len; i++)
	{
		if (ciphertext[i] >= '0' && ciphertext[i] <= '9')
		{
			if (ciphertext[i+1] >= '0' && ciphertext[i+1] <= '9'){
				start = sti(ciphertext[i])*10 + sti(ciphertext[i+1]);
				removenum(ciphertext,i,&len);
				removenum(ciphertext,i,&len);
			}
			else {
			start = sti(ciphertext[i]);
			removenum(ciphertext,i,&len);
			}
			end = i-1;
			reverse	(ciphertext,start,end);
		}
	}
	//输出 
	for (i = 0; i < len; i++)
	{
		if (ciphertext[i] >= '0' && ciphertext[i] <= '9')
			flag = 0;
		else flag = 1;
		if (flag)
		{
			printf ("%c",ciphertext[i]);
		}
	}
	return 0;
}

void removenum(char* a,int pnum,int* plen)
{
	int lena = strlen (a);
	int i = 0;
	for (i = pnum; i < lena - 1; i++)
	{
		a[i] = a[i + 1];
	}
	*plen = *plen - 1;
}

void reverse(char* a,int start,int end)
{
	int lc = start;
	int rc = end;
	int count = 0;
	int noo = (end - start + 1) / 2;
	int t = 0;
	while (count < noo){
		t  = a[lc];
		a[lc] = a[rc];
		a[rc] = t;
		lc++;
		rc--;
		count++;	
	}
}

int sti(char c)
{
	switch(c){
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

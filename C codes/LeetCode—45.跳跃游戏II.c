/*
Code Information
  <动态规划练习> for leetCode
  Written by George·Dong
  Code Version 1.0 Beta
*/

//头文件区
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//函数区
//跳跃游戏II
#include <math.h>
int jump(int* nums, int numsSize) 
{
	int s = 0; 
	int mp = 0; 
	int limit = 0;
	for (int i = 0; i < numsSize - 1; i++)
	{
		if (mp >= i) 
		{
			mp = fmax(mp, (i + *(nums + i)));
			if (i == limit)
			{
				limit = mp;
				s++;
			}
		}
	}
	return s;
}

//主函数区（测试样例区）
int main(void)
{
	//默认输入区
	int NOT = 0;
	printf("输入测例个数：");
	scanf("%d", &NOT);
	//测试输入区
	while (NOT)
	{
		printf("请输入测例:\n");
		int step[110] = { 1,1 };
		int sl = 0;
		scanf("%d", &sl);
		for (int i = 0; i < sl; i++)
		{
			scanf("%d", &step[i]);
		}
		printf("%d\n", jump(step,sl));
		NOT--;
	}
	return 0;
}
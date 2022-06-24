/*
Code Information
  <找零总数> for Matrix
  Written by George·Dong Instructed by _single$hot
  Code Version 2.0 Beta
*/

/*动态规划——背包法
  本质上是将递归的结果存在数组中
  本题实质上是给定因数，分解一个数
*/

#include <stdio.h>

int bag[1010];   //生成背包用于存放数据
int bill[8] = { 1,5,10,50,100,200,500,1000 };   //生成纸币的数组

#include <stdio.h>

int bag[1010];   //生成背包用于存放数据
int bill[8] = { 1,5,10,50,100,200,500,1000 };   //生成纸币的数组

int main(void)
{
	//遍历生成整个背包
	int limit = 1000;  //输入上限，用于限制遍历次数，即最大找零数
	bag[0] = 1;
	for (int i = 0; i < 8; i++)   
	{
		for (int j = bill[i]; j < limit; j++)  //遍历所有值
		{
			bag[j] += bag[j - bill[i]];  //递归性质/二叉树
		}
	}
	double num = 0;
	while (scanf("%lf", &num) != EOF)
	{
		int p = 10 * num;
		printf("%d\n", bag[p]);
	}
	return 0;
}

//垃圾站
//Beta 1.0 超时
/*int main(void)
{
	int charge = 0;
	scanf("%d", &charge);
	int sum = charge * 10;
	int check = 0; int count = 0;
	for (int c1 = 0; c1 <= sum; c1++)   //1角
	{
		for (int c2 = 0; c2 <= sum / 5; c2++)  //5角
		{
			for (int c3 = 0; c3 <= sum / 10; c3++)  //1元
			{
				for (int c4 = 0; c4 <= sum / 50; c4++)  //5元
				{
					for (int c5 = 0; c5 <= sum / 100; c5++)  //10元
					{
						for (int c6 = 0; c6 <= sum / 200; c6++)  //20元
						{
							for (int c7 = 0; c7 <= sum / 500; c7++)  //50元
							{
								for (int c8 = 0; c8 <= sum / 1000; c8++)  //100元
								{
									check = c1 + 5 * c2 + 10 * c3 + c4 * 50 + c5 * 100 + c6 * 200 + c7 * 500 + c8 * 1000;
									if (check == sum) {
										count++;
										break;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	printf("%d", count);
	return 0;
}*/
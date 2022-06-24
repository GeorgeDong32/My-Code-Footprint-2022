#include <stdio.h>

int main()
{
	int price , pay;
	printf("输入应付金额") ;
	scanf("%d", &price);
	printf("输入实付金额");
	scanf("%d", &pay);
	int change = pay - price;
	printf("应找%d元", change);
	
	return 0;
}
 

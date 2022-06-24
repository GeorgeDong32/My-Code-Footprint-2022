#include <stdio.h>
#include <math.h> 
int main()
{
	int id[18];
	long long int c, d;
 	long long idn;
 	//身份证号读取与存储 
	printf ("请输入身份证号码:\n");
	scanf ("%lld",&idn);
	c = idn;
	for ( int i = 0; i <= 17; i++ ){
		d = c % 10;
		id[i] = d;
		c /= 10;
	}            
	//身份证校验   
	int n = 0;              //校验中转值
	int sum = 0;            //校验值 
	int a[] = {1,2,4,8,5,10,9,7,3,6,1,2,4,8,5,10,9,7};
	for ( int j = 0; j <= 17; j++) {
		n = id[j] * a[j];
		sum += n;
	}
	//输出 
	if ( (sum % 11) == 1 ) printf ("通过校验,身份合法\n");
	else printf ("未通过校验，请检查\n"); 
	return 0;
	
}

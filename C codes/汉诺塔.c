#include<stdio.h>
long long int count = 0;
void Hanoi(int n, char A, char B, char C)
{
     
    if (n == 1)
    {
    	//printf("move disk %d from peg %c to peg %c\n",n,A,C);
    	count++;
    }
    else
    {
   		Hanoi(n - 1, A, C, B);
    	//printf("move disk %d from peg %c to peg %c\n",n,A,C);
    	count++;
    	Hanoi(n - 1, B, A, C);   
    }
     
}
int main()
{
    int n; int t; int i;
    char A = '1'; 
    char B = '2';
    char C = '3';
    //printf("Input the number of disks:");
    scanf("%d", &t);
    for (i = 0; i < t; i++){
    	scanf ("%d", &n);
    	Hanoi(n, A, B, C);  
	}
	long long int time = count / 365;
	printf ("It needs over %lld years!",time);
}

#include<stdio.h>
//book.h
int betterBookForReaderA(int book1,int book2);

int find6(int a);

int betterBookForReaderB(int book1,int book2);

int isPalindromic(int a);

int betterBookForReaderC(int book1,int book2);

//main.c
void printChoice(int choose,int book1,int book2)
{
    if(choose==-1)
        printf("Sorry. Neither of those books.\n");
    else if(choose==1)
        printf("I guess you will prefer: %d\n",book1);
    else if(choose==2)
        printf("I guess you will prefer: %d\n",book2);

}

int main()
{
    char c;
    int book1, book2;
    scanf("%c %d %d", &c, &book1, &book2);
    int choose;
    if(c == 'A')
        choose = betterBookForReaderA(book1, book2);
    else if(c == 'B')
        choose = betterBookForReaderB(book1, book2);
    else if(c == 'C')
        choose = betterBookForReaderC(book1, book2);

    printChoice(choose, book1, book2);
    return 0;
}

//book.c

int weishu (int n);
int max (int a,int b);

int betterBookForReaderA(int book1,int book2){
	if (weishu(book1)== weishu(book2)){
		return max(book1,book2);
	}
	else if (weishu(book1)> weishu(book2)) return 2;
	else if (weishu(book1)< weishu(book2)) return 1;
}

int find6(int a){
	int count6 =0;
	do {
	int d = a%10;
	a/=10;
	if (d == 6) count6++;
	} while (a > 0);
	if (count6 != 0) return 1;
	else return 0;
}

int betterBookForReaderB(int book1,int book2){
	int r1 = find6(book1); int r2 = find6(book2);
	if (r1 && r2) return 1;
	else if (r1 && r2 != 1) return 1;
	else if (r2 && r1 != 1) return 2;
	else if (r1 != 1 && r2 != 1) return -1;
}

int isPalindromic(int a){
	int reversedInteger = 0, remainder, originalInteger;
 
    originalInteger = a;
    while( a!=0 )
    {
        remainder = a%10;
        reversedInteger = reversedInteger*10 + remainder;
        a /= 10;
    }
    if (originalInteger == reversedInteger)
        return 1;
    else
        return 0;
}

int betterBookForReaderC(int book1,int book2){
	int r1 = isPalindromic(book1); int r2 = isPalindromic(book2);
	if (r1 && r2) return 1;
	else if (r1 && r2 != 1) return 1;
	else if (r2 && r1 != 1) return 2;
	else if (r1 != 1 && r2 != 1) return -1;
}

int weishu (int n){
	int count = 0;
	do {
		int d = n%10;
		n/=10;
		count++;
	} while (n > 0);
	return count;
}

int max (int a,int b){
	if (a >= b) return 1;
	else return 2;
}

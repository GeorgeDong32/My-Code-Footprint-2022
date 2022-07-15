#include <iostream>
#include <string>
using namespace std;

int main()
{
	int i = 0; int q = 10;
	for (int i = 0; i < 10; i++)
	{
		q += 1;
		i += 1;
		cout << q << " " << i << endl;
	}
}

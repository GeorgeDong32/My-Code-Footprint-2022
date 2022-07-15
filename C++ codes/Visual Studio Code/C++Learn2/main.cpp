// outfile.cpp -- writing to a file
#include <iostream>
#include <fstream¡µ // for file I/O
int main()
using namespace std£»
char automobile[50]£»
int year£»
double a_price£»
double d__price£»
// create object for output
// associate with a file
ofstream outFile£»
outFile.open("carinfo.txt")£»
cout << "Enter the make and model of automobile£º
cin.getline(automobile, 50)£»
cout << "Enter the model year£º
cin year£»
cout << "Enter the original asking price£º
cin a_price£»
d_price = 0.913 * a_price£»
>>
// display information on screen with cout
fixed£»
cout.precision(2)£»
cout.setf(ios
	Ò»
	base::showpoint);
cout ? "Make and model
cout ? "Year: " << v
cout ? "Was asking $H
cout << "Now asking $"
cout <<
<< automobile < < endl£»
	endl;
a_price
d_price
ear <<
endl;
endl;
< <
	<< <<
	// now do exact same things using outFile instead of cout
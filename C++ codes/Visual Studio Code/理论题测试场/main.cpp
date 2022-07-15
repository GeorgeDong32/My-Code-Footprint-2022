#include <iostream>
using namespace std;

template<typename T>
class Point {
	T x, y;
public:
	Point(T x_, T y_) :x(x_), y(y_) {}
};

template<typename T>
class Circle : public Point<T> {
	T r;
public:
	Circle(T x_, T y_, T r_) :Point<T>(x_, y_), r(r_) {}
};


int main()
{
	//A
	Circle<double>* a = new Circle<int>(4, 5, 6);

	//B
	Point<int>* a = new Circle<int>(4, 5, 6);

	//C
	Circle<int> a(4, 5, 6);
	Circle<double> b(1, 2, 3);
	a = b;

	//D
	Circle<int> a(1, 2, 2.5);
	Point<int> b(1, 2);
	b = a;

	Circle<int> a(1, 2, 2.5);
	Point<int> b(1, 2);
	b = a;
	return 0;
}
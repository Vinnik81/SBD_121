#include<iostream>
using namespace std;

void Exchange(int a, int b);

void main()
{
	setlocale(LC_ALL, "Russian");
	int a = 2, b = 3;
	Exchange(a, b);
	cout << a << "\t" << b << endl;
}
void Exchange(int a, int b)
{
	cout << &a << "\t" << &b << endl;

	int buffer = a;
	a = b;
	b = buffer;
}
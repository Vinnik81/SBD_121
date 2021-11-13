#include<iostream>
using namespace std;

//#define POINTERS_BASICS
#define POINTERS_AND_ARRAYS

void main()
{
	setlocale(LC_ALL, "");
#ifdef POINTERS_BASICS
int a = 2;
	int* pa = &a;
	cout << a << endl; //Выовод знач. перем. 'а' на экран
	cout << &a << endl; //Получения адреса перем. 'a' прямо при выводе
	cout << pa << endl; //Вывод адресса перем. 'a', хранящегося в указатели 'pa' 
	cout << *pa << endl; //Разыменование указателя 'pa', и получения знач. по адресу в этом указатели

	int* pb;
	int b = 3;
	pb = &b;
#endif // POINTERS_BASICS

#ifdef POINTERS_AND_ARRAYS
	const int n = 5;
	int arr[n] = { 3,5,8,13,21 };
	cout << *arr << endl;
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << "\t";
	}
	cout << endl;

}
#endif // POINTERS_AND_ARRAYS

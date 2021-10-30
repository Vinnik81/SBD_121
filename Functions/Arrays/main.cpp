#include<iostream>
//#include<time.h>	//Библиотека, написанная на языке C
#include<ctime>		//Такая же библиотека, написанная на языке C++
using namespace std;

#define delimetr "\n-----------------------------------\n"

const unsigned int ROWS = 4;
const unsigned int COLS = 5;

void FillRand(int arr[], const unsigned int n, int minRand = 0, int maxRand = 100);	//Заполняет массив случайными числами
void FillRand(double arr[], const unsigned int n, int minRand = 0, int maxRand = 100);	//Заполняет массив случайными числами
template<typename T>void Print(T arr[], const unsigned int n);
//void Print(double arr[], const unsigned int n);
template<typename T>void Print(T arr[ROWS][COLS], const unsigned int ROWS, const unsigned int COLS);

template<typename T>T Sum(T arr[], const unsigned int n);
//char Sum(char arr[], const unsigned int n);

void main()
{
	setlocale(LC_ALL, "");
	const unsigned int n = 5;
	int arr[n];
	//srand(5);
	int minRand, maxRand;
	//cout << "Введите минимальное случайное число: "; cin >> minRand;
	//cout << "Введите максимальное случайное число: "; cin >> maxRand;
	FillRand(arr, n, 200, 300);
	Print(arr, n);
	cout << delimetr;
	cout << "Сумма элементов массива: " << Sum(arr, n) << endl;
	cout << delimetr;
	double brr[n];
	FillRand(brr, n);
	Print(brr, n);

	cout << delimetr;

	int i_arr_2[ROWS][COLS] =
	{
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};
	Print(i_arr_2, ROWS, COLS);

	cout << delimetr << endl;
	double d_arr_2[ROWS][COLS] =
	{
		{2.5, 3.14, 8.3},
		{4.2, 7.3, 9.4},
		{.25}
	};
	Print(d_arr_2, ROWS, COLS);
}



void FillRand(int arr[], const unsigned int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (maxRand - minRand) + minRand;
	}
}
void FillRand(double arr[], const unsigned int n, int minRand, int maxRand)
{
	minRand *= 100;
	maxRand *= 100;
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (maxRand - minRand) + minRand;
		arr[i] /= 100;
	}
}
template<typename T>void Print(T arr[], const unsigned int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
void Print(double arr[], const unsigned int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
template<typename T>void Print(T arr[ROWS][COLS], const unsigned int ROWS, const unsigned int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}

template<typename T>T Sum(T arr[], const unsigned int n)
{
	T sum = T();
	for (int i = 0; i < n; i++)
	{
		sum = +arr[i];
	}
	return sum;
}
char Sum(char arr[], const unsigned int n)
{
	cout << "Буквы сумировать бесполезно ;-)";
	return 0;
}
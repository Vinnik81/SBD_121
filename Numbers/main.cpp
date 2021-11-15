#include<iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	//Основной массив:
	const int N = 10;
	int arr[N];
    cout << "Вывод массива из 10 элементов:" << endl;
	for (int i = 0; i < N; i++)
	{
		arr[i] = rand() % 50;
	}
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;

	//Чётный и нечётный массивы:
	int e = 0, o = 0;
	for (int i = 0; i < N; i++)
	{
		((arr[i] % 2) == 0) ? e++ : o++; //определение чётных и не чётных элементов
	}
	int* even = new int[e], e1 = e;
	int* odd = new int[o], o1 = o;
	for (int i = N - 1; i >= 0; i--)
	{
		((arr[i] % 2) == 0) ? even[--e1] = arr[i] : odd[--o1] = arr[i];
	}
	cout << "Вывод чётного массива:" << endl;
	for (int i = 0; i < e; i++)
	{
		cout << (long long)even[i] << "\t";
	}
	cout << endl;
	cout << "Вывод нечётного массива:" << endl;
	for (int i = 0; i < o; i++)
	{
		cout << odd[i] << "\t";
	}
	cout << endl;
	delete[]even;
	delete[]odd;
}


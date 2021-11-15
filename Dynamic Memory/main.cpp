#include<iostream>
using namespace std;

void FillRand(int arr[], const int n);
void Print(int* arr, const int n);

void main()
{
	setlocale(LC_ALL, "");

	int n;
	cout << "¬ведите размер массива: "; cin >> n;
	//ќбъ€вление динамического массива
	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);
	//”далени€ динамического массива
	delete[] arr;
	
}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//через арифметику указателей и оператор разыменовани€
		*(arr + i) = rand() % 100;

	}
}
void Print(int* arr, const int n)
{
	for (int i = 0; i < n; i++)
	{
		//через оператор индесировани€
		cout << arr[i] << "\t";
	}
	cout << endl;
}
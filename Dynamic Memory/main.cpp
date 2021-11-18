#include<iostream>
using namespace std;

#define delimetr "\n####################################################################################################################\n"
#define PUSH "\n***************************************************PUSH*************************************************************\n"
#define POP "\n***************************************************POP***************************************************************\n"
#define ARR "\n***************************************************ARRAY*************************************************************\n"

void FillRand(int arr[], const int n);
void Print(int* arr, const int n);
void Print1(int* arr1, const int n);
void Print2(int* arr2, const int n);
void push_back(int* arr, int* arr1, const int n, const int b); //добовляет значения в конец массива
void push_front(int* arr, int* arr1, const int n, const int f); //добовляет значение в начало массива
void insert(int* arr, int* arr1, const int n, const int val, const int ind); //добовляет значение по указанному индексу
void pop_back(int* arr, int* arr2, const int n); //удаляет значение в конце массива
void pop_front(int* arr, int* arr2, const int n); //удаляет значение в начале массива
void erase(int* arr, int* arr2, const int n, const int ind2); //удаляет значения по указанному индексу 

void main()
{
	setlocale(LC_ALL, "");

	cout << ARR;
	int n;
	cout << "Введите размер массива: "; cin >> n;
	//Объявление динамического массива
	int* arr = new int[n];
	FillRand(arr, n);
	cout << endl;
	Print(arr, n);
	cout << delimetr;
	int* arr1 = new int[n + 1];
	int* arr2 = new int[n - 1];
	char key;
	cout << "\nВведите номер действия: 1 - PUSH, 2 - POP. " << "№ "; cin >> key;
	switch (key)
	{
	case '1':
		int b;
		cout << PUSH;
		cout << "Введите новый элемент массива: "; cin >> b;
		cout << endl;
		cout << "Вывод массива с добавлением значения в конец:\n" << endl;
		push_back(arr, arr1, n, b);
		cout << delimetr;
		int f;
		cout << "Введите новый элемент массива: "; cin >> f;
		cout << endl;
		cout << "Вывод массива с добавлением значения в начало:\n" << endl;
		push_front(arr, arr1, n, f);
		cout << delimetr;
		int val, ind;
		cout << "Введите новый элемент массива: "; cin >> val;
		cout << "\nВведите индекс массива куда нужно вставить значение: "; cin >> ind;
		cout << "\nВывод массива с добавлением значения по заданному индексу:\n" << endl;
		insert(arr, arr1, n, val, ind);
		cout << delimetr;
		break;
	case '2':
		cout << POP << endl;
		cout << "Вывод массива с удалением значения в конце массива:\n" << endl;
		pop_back(arr, arr2, n);
		cout << delimetr;
		cout << "Вывод массива с удалением значения в начале массива:\n" << endl;
		pop_front(arr, arr2, n);
		cout << delimetr;
		int ind2;
		cout << "\nВведите индекс массива откуда нужно удалить значение: "; cin >> ind2;
		cout << "\nВывод массива с удалением значения по заданному индексу:\n" << endl;
		erase(arr, arr2, n, ind2);
		cout << delimetr;
		break;
	default:
		cout << "Вы ввели неверный №!!!";
	}
	//Удаления динамического массива
	delete[] arr;
	delete[] arr1;
}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//через арифметику указателей и оператор разыменования
		*(arr + i) = rand() % 100;

	}
}
void Print(int* arr, const int n)
{
	for (int i = 0; i < n; i++)
	{
		//через оператор индесирования
		cout << arr[i] << "\t";
	}
	cout << endl;
}
void Print1(int* arr1, const int n)
{
	for (int i = 0; i < n + 1; i++)
	{
		cout << arr1[i] << "\t";
	}
}
void push_back(int* arr, int* arr1, const int n, const int b)
{
	for (int i = 0; i < n; i++)
	{
		arr1[i] = arr[i];
	}
	arr1[n] = b;
	Print1(arr1, n);
}
void push_front(int* arr, int* arr1, const int n, const int f)
{
	for (int i = 0; i < n; i++)
	{
		arr1[i + 1] = arr[i];
	}
	arr1[0] = f;
	Print1(arr1, n);
}
void insert(int* arr, int* arr1, const int n, const int val, const int ind)
{
	arr1[ind] = val;
	for (int i = 0; i < ind; i++)
	{
		arr1[i] = arr[i];
	}
	for (int i = ind; i < n; i++)
	{
		arr1[i + 1] = arr[i];
	}
	Print1(arr1, n);
}
void Print2(int* arr2, const int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		cout << arr2[i] << "\t";
	}
}
void pop_back(int* arr, int* arr2, const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr2[i] = arr[i];
	}
	Print2(arr2, n);
}
void pop_front(int* arr, int* arr2, const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr2[i] = arr[i];
	}
	for (int i = 1; i < n; i++)
	{
		cout << arr2[i] << "\t";
	}
}
void erase(int* arr, int* arr2, const int n, const int ind2)
{
	for (int i = 0; i < ind2; i++)
	{
		arr2[i] = arr[i];
	}
	for (int i = ind2; i < n - 1; i++)
	{
		arr2[i] = arr[i + 1];
	}
	Print2(arr2, n);
}
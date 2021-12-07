#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimetr "\n####################################################################################################################\n"
#define PUSH "\n***************************************************PUSH*************************************************************\n"
#define POP "\n***************************************************POP***************************************************************\n"
#define ARR "\n***************************************************ARRAY*************************************************************\n"
#define MULTIDIM_ARR "\n*****************************************MULTIDIM_ARR***********************************************************\n"

template<typename T>T** allocate(const int rows, const int cols);
template<typename T>void clear(T** arr, const int rows);
void FillRand(int* arr, const int n, int minRand = 0, int maxRand = 100);
void FillRand(int** arr, const int rows, const int cols);
template<typename T>void Print(T* arr, const int n);
template<typename T>void Print(T** arr, const int rows, const int cols);
template<typename T>T* push_back(T arr[], int& n, T value);
template<typename T>T* push_front(T arr[], int& n, T value);
template<typename T>T* insert(T arr[], int& n, T value, int index); //добовляет значение по указанному индексу
template<typename T>T* pop_back(T arr[], int& n); //удаляет значение в конце массива
template<typename T>T* pop_front(T arr[], int& n); //удаляет значение в начале массива
template<typename T>T* erase(T arr[], int& n, int index); //удаляет значения по указанному индексу 
template<typename T>T** push_row_back(T** arr, int& rows, const int cols);
template<typename T>T** push_row_front(T** arr, int& rows, const int cols);
template<typename T>T** insert_rows(T** arr, int& rows, const int cols, int index);
template<typename T>T** pop_rows_back(T** arr, int& rows, const int cols);
template<typename T>T** pop_rows_front(T** arr, int& rows, const int cols);
template<typename T>T** erase_rows(T** arr, int& rows, const int cols, int index);
template<typename T>void push_col_back(T** arr, const int rows, int& cols);
template<typename T>void push_col_front(T** arr, const int rows, int& cols);
template<typename T>void insert_col(T** arr, const int rows, int& cols, int index);
template<typename T>void pop_col_back(T** arr, const int rows, int& cols);
template<typename T>void pop_col_front(T** arr, const int rows, int& cols);
template<typename T>void erase_col(T** arr, const int rows, int& cols, int index);

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

void main()
{
	setlocale(LC_ALL, "");

#ifdef DYNAMIC_MEMORY_1
	cout << ARR;
	int n;
	cout << "Введите размер массива: "; cin >> n;
	//Объявление динамического массива
	int* arr = new int[n];
	FillRand(arr, n);
	cout << endl;
	Print(arr, n);
	cout << delimetr;
		int value, index;
		cout << PUSH;
		cout << "Введите новый элемент массива: "; cin >> value;
		cout << endl;
		cout << "Вывод массива с добавлением значения в конец:\n" << endl;
		arr = push_back(arr, n, value);
		Print(arr, n);
		cout << delimetr;
		cout << "Введите новый элемент массива: "; cin >> value;
		cout << endl;
		cout << "Вывод массива с добавлением значения в начало:\n" << endl;
		arr = push_front(arr, n, value);
		Print(arr, n);
		cout << "Введите новый элемент массива: "; cin >> value;
		cout << "\nВведите индекс массива куда нужно вставить значение: "; cin >> index;
		cout << "\nВывод массива с добавлением значения по заданному индексу:\n" << endl;
		arr = insert(arr, n, value, index);
		Print(arr, n);
		cout << delimetr;
		cout << POP << endl;
		cout << "Вывод массива с удалением значения в конце массива:\n" << endl;
		arr = pop_back(arr, n);
		Print(arr, n);
		cout << delimetr;
		cout << "Вывод массива с удалением значения в начале массива:\n" << endl;
		arr = pop_front(arr, n);
		Print(arr, n);
		cout << delimetr;
		cout << "\nВведите индекс массива откуда нужно удалить значение: "; cin >> index;
		cout << "\nВывод массива с удалением значения по заданному индексу:\n" << endl;
		arr = erase(arr, n, index);
		Print(arr, n);
		cout << delimetr;
	//Удаления динамического массива
	delete[] arr;

#endif // DYNAMIC_MEMORY_1

#ifdef DYNAMIC_MEMORY_2
	cout << MULTIDIM_ARR;
	int rows;	//Количество строк
	int cols;	//Количество элементов строки (столбцов)
	int index;
	std::cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;
	int** arr = allocate<int>(rows, cols);
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimetr;
	cout << PUSH;
	arr = push_row_back(arr, rows, cols);
	FillRand(arr[rows - 1], cols, 100, 1000);
	Print(arr, rows, cols);
	cout << delimetr;
	arr = push_row_front(arr, rows, cols);
	FillRand(arr[0], cols, 100, 1000);
	Print(arr, rows, cols);
	cout << delimetr;
	cout << "\nВведите индекс массива куда нужно вставить строку: "; cin >> index;
	arr = insert_rows(arr, rows, cols, index);
	FillRand(arr[index], cols, 100, 1000);
	Print(arr, rows, cols);
	cout << delimetr;
	cout << POP;
	arr = pop_rows_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimetr;
	arr = pop_rows_front(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimetr;
	cout << "\nВведите индекс массива от куда нужно удалить строку: "; cin >> index;
	arr = erase_rows(arr, rows, cols, index);
	Print(arr, rows, cols);
	cout << delimetr;
	cout << PUSH;
	push_col_back(arr, rows, cols);
	for (int i = 0; i < rows; i++)
	{
		arr[i][cols - 1] = rand();
	}
	Print(arr, rows, cols);
	cout << delimetr;
	push_col_front(arr, rows, cols);
	for (int i = 0; i < rows; i++)
	{
		arr[i][0] = rand();
	}
	Print(arr, rows, cols);
	cout << delimetr;
	cout << "\nВведите индекс массива куда нужно вставить столбец: "; cin >> index;
	insert_col(arr, rows, cols, index);
	for (int i = 0; i < rows; i++)
	{
		arr[i][index] = rand();
	}
	Print(arr, rows, cols);
	cout << delimetr;
	cout << POP;
	pop_col_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimetr;
	pop_col_front(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimetr;
	cout << "\nВведите индекс массива от куда нужно удалить столбец: "; cin >> index;
	erase_col(arr, rows, cols, index);
	Print(arr, rows, cols);
	cout << delimetr;
	clear(arr, rows);
#endif // DYNAMIC_MEMORY_2

}

template<typename T>T** allocate(const int rows, const int cols)
{
	T** arr = new T* [rows] {};
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new T [cols] {};
	}
	return arr;
}
template<typename T>void clear(T** arr, const int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}
void FillRand(int* arr, const int n, int minRand, int maxRand)
{
	//Обращение к элементам динамического массива:
	for (int i = 0; i < n; i++)
	{
		//Через арифметику указателей и оператор разыменования:
		*(arr + i) = rand() % (maxRand - minRand) + minRand;
	}
}
void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
template<typename T>void Print(T* arr, const int n)
{
	for (int i = 0; i < n; cout << arr[i++] << "\t");
	//{
	//	//Через оператор индексирования:
	//	//cout << arr[i] << "\t";
	//	//Оператор индексирования возвращает значение по индексу.
	//}
	cout << endl;
}
template<typename T>void Print(T** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}
template<typename T>T* push_back(T arr[], int& n, T value)
{
	//1) Создаем буферный массив нужного размера
	T* buffer = new T[n + 1]{};
	//2) Копируем содержимое исходного массива в новый (буферный) массив:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3) После того как данные скопированы, исходный массив можно удалить
	delete[] arr;
	//4) Подменяем адрес старого массива адресом нового массива:
	arr = buffer;
	//5) Только после этого в массиве 'arr' появляется еще один элемент, 
	//	 в который можно созранить добавляемое значение
	arr[n] = value;
	//6) После того как в массиве появился еще один элемент, количество его элементов 
	//	 увеличилось на 1
	n++;
	//Print(arr, n);
	return arr;
	//						Mission complete.
}
template<typename T>T* push_front(T arr[], int& n, T value)
{
	T* buffer = new T[n + 1]{};
	for (int i = 0; i < n; i++)buffer[i + 1] = arr[i];
	
	delete[] arr;
	buffer[0] = value;
	n++;
	return buffer;
}

template<typename T>T* insert(T arr[], int& n, T value, int index)
{
	T* buffer = new T[n + 1]{};
	for (int i = 0; i < index; i++)buffer[i] = arr[i];
	
	for (int i = index; i < n; i++)buffer[i + 1] = arr[i];
	
	delete[] arr;
	buffer[index] = value;
	n++;
	return buffer;
}

template<typename T>T* pop_back(T arr[], int& n)
{
	T* buffer = new T[--n]{};
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}
template<typename T>T* pop_front(T arr[], int& n)
{
	T* buffer = new T[--n]{};
	for (int i = 0; i < n; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}
template<typename T>T* erase(T arr[], int& n, int index)
{
	T* buffer = new T[--n]{};
	for (int i = 0; i < index; i++)buffer[i] = arr[i];
	
	for (int i = index; i < n; i++)buffer[i] = arr[i + 1];
	
	delete[] arr;
	return buffer;
}
template<typename T>T** push_row_back(T** arr, int& rows, const int cols)
{
	T** buffer = new T* [rows + 1]{};
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	delete[] arr;
	buffer[rows] = new T[cols] {};
	rows++;
	return buffer;
}
template<typename T>T** push_row_front(T** arr, int& rows, const int cols)
{
	T** buffer = new T* [rows + 1]{};
	for (int i = 0; i < rows; i++)buffer[i + 1] = arr[i];
	delete[] arr;
	
	buffer[0] = new T[cols] {};
	rows++;
	return buffer;
}
template<typename T>T** insert_rows(T** arr, int& rows, const int cols, int index)
{
	T** buffer = new T* [rows + 1]{};
	for (int i = 0; i < index; i++)buffer[i] = arr[i];
	
	for (int i = index; i < rows; i++)buffer[i + 1] = arr[i];
	
	delete[] arr;
	buffer[index] = new T[cols];
	rows++;
	return buffer;
}
template<typename T>T** pop_rows_back(T** arr, int& rows, const int cols)
{
	T** buffer = new T* [--rows]{};
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}
template<typename T>T** pop_rows_front(T** arr, int& rows, const int cols)
{
	T** buffer = new T* [--rows]{};
	for (int i = 0; i < rows; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}
template<typename T>T** erase_rows(T** arr, int& rows, const int cols, int index)
{
	T** buffer = new T* [--rows]{};
	for (int i = 0; i < index; i++)buffer[i] = arr[i];
	
	for (int i = index; i < rows; i++)buffer[i] = arr[i + 1];
	
	delete[] arr;
	return buffer;
}
template<typename T>void push_col_back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1]{};
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
template<typename T>void push_col_front(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1]{};
		for (int j = 0; j < cols; j++)buffer[j + 1] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
template<typename T>void insert_col(T** arr, const int rows, int& cols, int index)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1]{};
		for (int j = 0; j < index; j++)buffer[j] = arr[i][j];
		
		for (int j = index; j < cols; j++)buffer[j + 1] = arr[i][j];
		
		delete[] arr[i];
		arr[i] = buffer;
    }
	cols++;
}
template<typename T>void pop_col_back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1]{};
		for (int j = 0; j < cols - 1; j++)buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}
template<typename T>void pop_col_front(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1]{};
		for (int j = 0; j < cols - 1; j++)buffer[j] = arr[i][j + 1];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}
template<typename T>void erase_col(T** arr, const int rows, int& cols, int index)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1]{};
		for (int j = 0; j < index; j++)buffer[j] = arr[i][j];
		
		for (int j = index; j < cols - 1; j++)buffer[j] = arr[i][j + 1];
		
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}
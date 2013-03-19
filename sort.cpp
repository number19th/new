#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
void qSort(int *A, int low, int high) // Название функции
{
	int i = low; // Минимальный индекс
	int j = high; // Максимальный индекс
	int x = A[(low+high)/2];  // x - опорный элемент посредине между low и high
	do 
	{
		while(A[i] < x)
			++i;  // поиск элемента для переноса в старшую часть
		while(A[j] > x)
			--j;  // поиск элемента для переноса в младшую часть
		if(i <= j)
		{           // обмен элементов местами:
			int temp = A[i];
			A[i] = A[j];
			A[j] = temp; // переход к следующим элементам:
			i++;
			j--;
		}
	}
	while(i < j);
	if(low < j) qSort(A, low, j);
	if(i < high) qSort(A, i, high);
};
void main ()
{
	srand(time (NULL));
	static int *Mas; // Массив типа int
	int high; // Число элементов в массиве
	printf ("high = "); 
	scanf ("%d", &high); // Получение числа элементов в массиве
	Mas = new int[high]; // ВЫделение памяти 
	for (int i = 0; i < high; i++) 
	{ // Генерирование элементов массива
		Mas[i] = rand() % 100;
		printf ("%3d ", Mas [i]);
	}
	qSort ( Mas, 0, high-1); // Вызов функции быстрой сортировки
	printf ("\n");
	for (int i = 0; i < high; i++) // Вывод на печать элементов отсортированного массива
		printf ("%3d ", Mas [i]);
	getch ();
}
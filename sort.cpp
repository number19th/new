#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
void qSort(int *A, int low, int high) // �������� �������
{
	int i = low; // ����������� ������
	int j = high; // ������������ ������
	int x = A[(low+high)/2];  // x - ������� ������� ��������� ����� low � high
	do 
	{
		while(A[i] < x)
			++i;  // ����� �������� ��� �������� � ������� �����
		while(A[j] > x)
			--j;  // ����� �������� ��� �������� � ������� �����
		if(i <= j)
		{           // ����� ��������� �������:
			int temp = A[i];
			A[i] = A[j];
			A[j] = temp; // ������� � ��������� ���������:
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
	static int *Mas; // ������ ���� int
	int high; // ����� ��������� � �������
	printf ("high = "); 
	scanf ("%d", &high); // ��������� ����� ��������� � �������
	Mas = new int[high]; // ��������� ������ 
	for (int i = 0; i < high; i++) 
	{ // ������������� ��������� �������
		Mas[i] = rand() % 100;
		printf ("%3d ", Mas [i]);
	}
	qSort ( Mas, 0, high-1); // ����� ������� ������� ����������
	printf ("\n");
	for (int i = 0; i < high; i++) // ����� �� ������ ��������� ���������������� �������
		printf ("%3d ", Mas [i]);
	getch ();
}
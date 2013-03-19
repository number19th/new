#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
void qSort (int *A, int low, int high) // Function name
{
	int i = low; // Minimum index
	int j = high; // Maximum index
	int x = A [(low + high) / 2]; // x - support element halfway between low and high
	do
	{
		while (A [i] <x)
			++i; // look for the feature to move into the upper part
		while (A [j]> x)
			--j; // searching for the item to be transferred to the younger part of the
		if (i <= j)
		{ // Exchange elements places:
			int temp = A [i];
			A [i] = A [j];
			A [j] = temp; // move to the following elements:
			i++;
			j--;
		}
	}
	while (i < j);
	if (low < j) qSort (A, low, j);
	if (i < high) qSort (A, i, high);
};
void main ()
{
	srand (time (NULL));
	static int *Mas; // An array of type int
	int high; // number of elements in the array
	printf ("high =");
	scanf ("%d", & high); // Get the number of elements in the array
	Mas = new int [high]; // memory allocation
	for (int i = 0; i <high; i++)
	{ // Generate an array
		Mas [i] = rand ()% 100;
		printf ("%3d", Mas [i]);
	}
	qSort (Mas, 0, high-1); // call function quicksort
	printf ("\n");
	for (int i = 0; i <high; i++) // Printing the sorted array elements	
		printf ("%3d", Mas [i]);
	getch ();
}
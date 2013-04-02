#include <stdio.h>
#include <conio.h>
#include <locale.h>
struct List
{
	int value;
	void del (int index, List *p)
	{
		List *pF = p;
		for ( ; index - 1 > 1; pF = pF->pNext)
			index--;
		pF->pNext = pF->pNext->pNext;
	}
	List *pNext;
	void add(int index, List *p)
	{
		List *pF = p;
		for ( ; index - 1 > 1; pF = pF->pNext)
			index--;
		List *n_list = new List;
		n_list->value = 19;
		n_list->pNext = pF->pNext;
		pF->pNext = n_list;
	}
};
void main ()
{
	setlocale(LC_ALL,".1251");
	List *list = new List;
	List *p = list;
	int add_index, del_index, get_index;
	for (int i = 0; i < 10; i++)
	{
		list->value = i+1; 
		list->pNext = new List;
		list = list->pNext;
	}
	list->pNext = 0;
	printf ("¬ведите индекс : ");
	scanf ("%d", &add_index);
	list->add (add_index, p);
	list = p;
	while (list->pNext)
	{
		printf ("%d ", list->value);
		list = list->pNext;
	}
	printf ("\n¬ведите индекс : ");
	scanf ("%d", &del_index);
	list->del (del_index, p);
	list = p;
	while (list->pNext)
	{
		printf ("%d ", list->value);
		list = list->pNext;
	}
	printf ("\n¬ведите индекс : ");
	scanf ("%d", &get_index);
	list->getValue(get_index, p);
	getch ();
}
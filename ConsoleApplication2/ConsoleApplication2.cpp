// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;

struct Dlist
{

	int info;
	Dlist* next, * prev;

};


int main()
{

	Dlist* head, * p, * r;
	int x, k, y;
	int max, i, a, b;
	float sr;
	head = new Dlist;
	cin >> x;
	head->info = x;
	head->next = NULL;
	head->prev = NULL;
	p = head;

	a = 0;
	k = 0;

	cin >> x;
	while (x)
	{
		r = new Dlist;
		r->info = x;
		r->next = NULL;
		r->prev = p;
		p->next = r;
		p = r;
		cin >> x;

	}

	p = head->next;
	
	while (p != NULL)
	{
		
		if (p->prev->info % 3 == 0)
		{

			r = p;
			p->prev->next = r->next;
			p->next->prev = p->prev;
			p = p->next;
			delete r;
			p = p->next;

		}
		else
		{
			p = p->next;
		}
		
	}

	if (p != NULL && p->prev->info % 3 == 0)
	{
		r = p;
		p->prev->next = NULL;
		delete r;
	}

	p = head;

	while (p != NULL)
	{

		cout << p->info << setw(3);
		p = p->next;
	}

}
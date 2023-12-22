#include <iostream>
#include "stack.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

	TStack<int> a(10);
	cout << "Выполнен push для числа 1\n";
	a.Push(1);
	cout << "Выполнен push для числа 5\n";
	a.Push(5);
	cout << "Выполнен push для числа 10\n";
	a.Push(10);


	while (!a.IsEmpty()) {
		cout << "Element " << a.GetTop() << endl;
	}
}
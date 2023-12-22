
#include "stack.h"
#include "postfix.h"
#include <iostream>
#include <string>
#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{
	TStack<int> s(200);

	setlocale(LC_ALL, "Rus");

	cout << endl << "Тестирование калькулятора" << endl;

	TPostfix Calc;
	try {
		//cout << Calc.SetInfix("(4+7+3*2*(8/4-57))*2") << endl;
		cout << Calc.SetInfix("1/6") << endl;
		cout << Calc.ToPostfix() << endl;
		cout << Calc.Calculate() << endl;
	}
	catch (const char* e) {
		cout << e << endl;
	}
	return 1;
}
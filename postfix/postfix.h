#ifndef _POSTFIX_ 
#define _POSTFIX_ 
#include "stack.h"
#include <string>
#include <math.h>
using namespace std;

class TPostfix {
	string infix;
	string postfix;
	TStack<char> stack;
	TStack<double> stack_2;

	int Priority(char elem) {

		switch (elem) {

		case '(': return 0; break;
		case ')': return 0; break;
		case '+': return 1; break;
		case '-': return 1; break;
		case '*': return 2; break;
		case '/': return 2; break;
		case '^': return 3; break;

		}

		return -1;
	}


public:
	TPostfix() : stack(100), stack_2(100) {
		infix = "";
		postfix = "";
	}

	string GetExpression() {
		return infix;
	}
	string GetPostfix() {
		return postfix;
	}
	string ToPostfix(){

		unsigned int i = 0;
		postfix = "";

		stack.Clear();
		string src = "(" + infix + ")";

		for (i = 0; i < src.size(); i++) {

			if ((src[i] >= '0') && (src[i] <= '9') || (src[i] == '.')) {
				postfix += src[i];

			}

			else if (src[i] == '(') {

				stack.Push('(');

			}

			else if (src[i] == ')') {
				while (stack.TopView() != '(')
					postfix += stack.GetTop();
				stack.GetTop();
			}
			else if ((src[i] == '+') || (src[i] == '-') || (src[i] == '*') || (src[i] == '/') || (src[i] == '^')) {
				postfix += ' ';
				if (Priority(stack.TopView()) < Priority(src[i]))
					stack.Push(src[i]);
				else {
					while (Priority(stack.TopView()) >= Priority(src[i]))
						postfix += stack.GetTop();
					stack.Push(src[i]);
				}
			}
		}
		return postfix;

	}
	bool Brackets(string a) {
		int Flag = 0;
		for (size_t i = 0; i < a.size(); i++) {
			if (a[i] == '(') {
				Flag++;
			}
			if (a[i] == ')') {
				Flag--;
				if (Flag < 0) return false;
			}
		}
		if (Flag == 0)
			return true;
		else
			return false;
	}
	double Calculate() {
		stack_2.Clear();
		double a, b, res;
		if (!Brackets(postfix)) {
			throw "unequal number of brackets";
		}
		for (size_t i = 0; i < postfix.size(); i++) {
			if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^') {
					if (stack_2.IsEmpty()) {
						throw "Stack is empty";
					}
					b = stack_2.GetTop();
					if (stack_2.IsEmpty()) {
						throw "Stack is empty";
					}
					a = stack_2.GetTop();
					switch (postfix[i]) {
					case '+': res = a + b; break;
					case '-': res = a - b; break;
					case '*': res = a * b; break;
					case '/': res = a / b; break;
					case '^': res = pow(a, b); break;
					}
					stack_2.Push(res);
			}
			else if ((postfix[i] >= '0' && postfix[i] <= '9') || postfix[i] == '.') {
				char *tmp;
				res = strtod(&postfix[i], &tmp);
				stack_2.Push(res);
				size_t g = static_cast<size_t>(tmp - &postfix[i]);
				i += g - 1;
			}
		}
		if (stack_2.IsEmpty()) {
			throw "Stack is empty";
		}
		else {
			res = stack_2.GetTop();
		}
		if (!stack_2.IsEmpty()) {
			throw "Stack is not empty";
		}

		return res;
	}
	string SetInfix(const string str) {
		infix = "";
		if (!Brackets(str)) {
			throw "unequal number of brackets";
		}

		for (size_t i = 0; i < str.size(); i++) {
			if (str[i] != ' ') {
				infix += str[i];
			}
		}

		return infix;
	}
};


#endif
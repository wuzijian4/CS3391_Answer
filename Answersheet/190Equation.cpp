#include <iostream>
#include <stack>
#include <string>
#include <stdio.h>
using namespace std;

int priority(char o) {
	if (o == '(' || o == ')') return 0;
	if (o == '+' || o == '-') return 1;
	if (o == '*' || o == '/') return 2;
	return -1;
}

int isOperator(char op)
{
	if (op == '+' || op == '-' || op == '*' || op == '/')
		return 1;
	return 0;
}
int main() {
	int cases;
	char in;
	cin >> cases;
	cin.ignore(); //skip n characters in the stream, default value of n is 1, or encounter the deliminater, 
	cin.ignore(); //but invlove the deliminater.

	while (cases > 0) {
		stack<char> operator_stack;
		string in;
		while (true)
		{
			getline(cin, in);
			if (in.length() == 0)
				break;

			// get the input, break when the equation finished
			if (in[0] >= 48 && in[0] <= 57) {
				cout << in[0];
			}
			else
			{
				
				if (in[0] == '(')
				{
					operator_stack.push(in[0]);
				}
				else if (in[0] == ')')
				{
					while (operator_stack.top() != '(') {
						cout << operator_stack.top();
						operator_stack.pop();
					}
					operator_stack.pop(); // reomve the ')'
				}
				else if (isOperator(in[0]))
				{
					while (!operator_stack.empty() && priority(in[0]) <= priority(operator_stack.top()))
					{
						cout << operator_stack.top();
						operator_stack.pop();
					}
					operator_stack.push(in[0]);
				}
				else
				{
					cout << in[0];
				}

			}
		}

		while (!operator_stack.empty())
		{
			cout << operator_stack.top();
			operator_stack.pop();
		}

		cout << endl;

		cases--;
		if (cases > 0) 
			cout << endl;
	}
	return 0;
}

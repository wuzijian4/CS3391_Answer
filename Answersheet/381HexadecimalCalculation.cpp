#include <iostream>
#include <string>
#include <stack>
using namespace std;

int priority(char op) {
	if (op == '(' || op == ')') return 0;
	if (op == '+') return 1;
	if (op == '*') return 2;
	return -1;
}

void compute(stack<char>& op, stack<int>& operand) {
	int num1 = operand.top(); operand.pop();
	int num2 = operand.top(); operand.pop();
	char o = op.top(); op.pop();
	if (o == '*') operand.push(num1 * num2);
	if (o == '+') operand.push(num1 + num2);
}

string intToHex(int n, char* set) {
	string result = "";
	const int base = 16;
	if (n == 0)
	{
		result += set[0];
		return result;
	}
	while (n) {
		int i = n % base;
		result = set[i] + result;
		n /= base;
	}
	return result;
}

int main() {
	char lookUpTable[16] = { '0','1','2','3','4','5','6','7','8','9',
		'A','B','C','D','E','F' };
	char ch;
	stack<char> op;
	stack<int> operand;
	while ((ch = getchar()) != EOF)
	{
		if (ch == '\n') {
			while (!op.empty())
				compute(op, operand);
			if (!operand.empty()) {
				string result = intToHex(operand.top(), lookUpTable);
				cout << result << endl;
				operand.pop();
			}
			continue;
		}


		if (isdigit(ch)) {
			operand.push(ch - 48);
		}
		else if (ch >= 65 && ch <= 70) {
			operand.push(int(ch) - 55);
		}
		else if (op.empty() || ch == '(') {
			op.push(ch);
		}
		else if (ch == '+' || ch == '*')
		{
			while (!op.empty() && priority(ch) <= priority(op.top()))
			{
				compute(op, operand);
			}
			op.push(ch);
		}
		else if (ch == ')') {
			while (op.top() != '(')
			{
				compute(op, operand);
			}
			op.pop(); // remove '('
		}

	}

	if (ch == EOF)
	{
		while (!op.empty())
			compute(op, operand);
		if (!operand.empty()) {
			string result = intToHex(operand.top(), lookUpTable);
			cout << result << endl;
			operand.pop();
		}
	}

	return 0;
}
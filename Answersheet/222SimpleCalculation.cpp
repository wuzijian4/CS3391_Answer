#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;


int main() {
	string input;
	int index = 0;
	while (getline(cin, input))
	{
		int i = 0; int j = i;
		long double result = 0;
		for (; i < input.length(); i++)
		{
			if (isspace(input[i]))
				continue;

			while (j < input.length() && isspace(input[j]))
				j++;
			while (j < input.length() && !isspace(input[j]))
				j++;

			string tmp = input.substr(i, j);
			i = j;
			long double out = stold(tmp);
			result += out;
		}
		if (index == 0) {
			cout << fixed << setprecision(4) << result << endl;
			index++;
		}
		else
		{
			cout << endl << fixed << setprecision(4) << result << endl;
		}
	}
	return 0;
}
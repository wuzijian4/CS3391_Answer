#include <iostream>
#include <string>
#include <math.h>
#include <memory.h>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n;
	while (cin >> n)
	{
		string output;
		int p, q;
		do
		{
			p = n / 2;
			q = n % 2;

			if (q == 1)
				output += "1";
			else if (q == 0)
				output += "0";
			n = n / 2;
			if (p == 0)
				break;

		} while (true);
		reverse(output.begin(), output.end());

		cout << output << endl;
	}
	return 0;
}
#include <iostream>
#include <string>
#include <math.h>
#include <memory.h>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int lookUp[10] = { 1,0,0,0,1,0,1,0,2,1 };
	int n;
	while (cin >> n)
	{
		if (n == 0) {
			cout << 1 << endl;
			continue;
		}

		int tmp = 0;
		int p;
		while (n != 0)
		{
			p = n % 10;
			n = n / 10;
			tmp += lookUp[p];
		}
		cout << tmp << endl;
	}
	return 0;
}
#include <iostream>
using namespace std;

int k;  // the maximum number of sections in the box
int a;  // the number of nuts
int b;  // the number of divisors
int v;  // the capacity of each section of the box


int main() {
	while (scanf("%d%d%d%d", &k, &a, &b, &v) != EOF)
	{
		int count = 0;
		while (a > 0)
		{
			if (b >= k - 1) {
				a -= k * v;
				b -= (k - 1);
				count++;
			}
			else
			{
				a -= ((b + 1)*v);
				b = 0;
				count++;
			}
		}
		cout << count << endl;
	}
	return 0;
}
#include <iostream>
using namespace std;

long long b, p, m;


long long BigMod(long long b, long long p, long long m) {
	if (b == 0)
		return 0;

	if (p == 0)
		return 1;
	if (p == 1)
		return b % m;

	long long result = BigMod(b, p / 2, m);
	result = (result*result) % m;

	if (p % 2 == 1)
		result = (result*b) % m;
	return result;

}


int main() {
	while (cin >> b >> p >> m)
	{
		cout << BigMod(b, p, m) << endl;
	}
	return 0;
}
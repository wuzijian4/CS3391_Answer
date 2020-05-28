#include <iostream>
using namespace std;

int main() {
	int cases; int numPeople;
	cin >> cases;
	while (cases > 0)
	{
		cin >> numPeople;
		if (numPeople < 3)
			cout << 0 << endl;
		else
			cout << numPeople - 2 << endl;
		cases--;
	}
	return 0;
}

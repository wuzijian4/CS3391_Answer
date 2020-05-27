#include <iostream>
using namespace std;

bool isBalance;

int mobile() {
	int w1, d1, w2, d2;
	cin >> w1 >> d1 >> w2 >> d2;
	if (w1 == 0) w1 = mobile();
	if (w2 == 0) w2 = mobile();
	if (w1*d1 != w2 * d2) isBalance = false;

	return w1 + w2;
}

int main() {
	int cases;
	cin >> cases;
	cin.ignore();
	
	while (cases)
	{
		isBalance = true;
		mobile();

		if (isBalance)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

		cases--;
		if (cases)
			cout << endl;
	}
	return 0;
}

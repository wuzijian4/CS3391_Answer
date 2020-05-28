#include <iostream>
#include <iomanip>
#include <stdio.h>
using namespace std;

int main() {
	int cases;
	cin >> cases;
	for (int i = 1; i <= cases; i++)
	{
		int walls;
		cin >> walls;

		int tmp;
		cin >> tmp; int high = 0; int low = 0;
		int next;

		for (int j = 1; j < walls; j++)
		{
			cin >> next;
			if (next > tmp)
				high++;
			else if (next < tmp)
				low++;
			tmp = next;
		}
		cout << "Case " << i << ": " << high << " " << low << endl;

	}
	//system("pause");
	return 0;
}
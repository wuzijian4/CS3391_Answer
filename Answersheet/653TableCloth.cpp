#include <iostream>
//#include <memory.h>
using namespace std;

int n, m;
//int table[100][100];

int main() {
	do
	{
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;
		int num = 4; int k = 0;
		//memset(table, 0, sizeof(table));
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				cin >> k;
				//table[i][j] = k;
				if (k == 1) {
					if (i == 1 || i == n || j == 1 || j == m)
						num = 2;
				}
			}
		}
		cout << num << endl;

	} while (true);
	return 0;
}
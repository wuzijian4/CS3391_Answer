#include <iostream>
#include <memory.h>
using namespace std;

int dist[1000][1000];

int cmp(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

int main() {
	int n;
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> dist[i][j];
			}
		}

		// ¼ÆËã×î¶ÌÂ·¾¶
		for (int k = 0; k < n; k++)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (dist[i][j] > dist[i][k] + dist[k][j]) {
						dist[i][j] = dist[i][k] + dist[k][j];
					}
				}
			}
		}

		/*
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << dist[i][j] << " ";
			}
			cout << endl;
		}
		*/


		for (int i = 0; i < n; i++)
		{
			int heat[1000];
			for (int j = 0; j < n; j++)
				heat[j] = dist[i][j];
			qsort(heat, n, sizeof(int), cmp);

			if ((n % 2) == 0) {
				cout << double(heat[n / 2] + heat[n / 2 - 1]) / 2 << endl;
			}
			else
			{
				cout << heat[(n + 1) / 2 - 1] << endl;
			}
		}

	}
	return 0;
}
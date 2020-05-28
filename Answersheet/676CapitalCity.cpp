#include <iostream>
#include <climits>
using namespace std;

#define INF 1000001
int matrix[200][200];
int n, m;

int shortest() {
	for (int k = 1; k <= n; k++)
	{//遍历所有顶点
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				//检测node i 能不能通过node k 到达node j
				int d;
				if (matrix[i][k] == INF || matrix[k][j] == INF)
					d = INF;
				else
					d = matrix[i][k] + matrix[k][j];

				if (matrix[i][j] > d)
				{
					matrix[i][j] = d;
				}
			}
		}

	}

	int min = INT_MAX, city = 0;


	for (int i = 1; i <= n; i++)
	{
		int total = 0;
		for (int j = 1; j <= n; j++)
			total += matrix[i][j];
		if (total < min)
		{
			min = total;
			city = i;
		}
	}
	return city;
}

int main() {
	while (scanf("%d%d", &n, &m) != EOF)
	{
		int u, v, w;

		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				if (i == j)
					matrix[i][j] = 0;
				else
					matrix[i][j] = INF;
			}
		}

		for (int i = 0; i < m; i++)
		{
			cin >> u >> v >> w;
			matrix[u][v] = w;
			matrix[v][u] = w;
		}

		int result = shortest();
		cout << result << endl;
	}
	return 0;
}
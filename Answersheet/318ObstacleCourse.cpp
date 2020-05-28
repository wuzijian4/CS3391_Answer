#include <iostream>
#include <memory.h>
#include <queue>
#include <climits>
using namespace std;

#define INF INT_MAX
int N;
int matrix[200][200];
int visited[40000];
int dis[40000];

int shortest() {
	// 棋盘式图
	for (int i = 0; i < N*N; i++)
		dis[i] = INF;
	dis[0] = matrix[0][0];

	for (int i = 0; i < N*N; i++)
	{
		int u = -1;
		int m = INF;
		for (int j = 0; j < N*N; j++)
		{
			if (!visited[j] && dis[j] <= m)
			{
				u = j;
				m = dis[j];
			}
		}
		visited[u] = 1;
		// 找到u可以到达的， 没有访问过的节点， 分为上下左右四个节点
		int row = u / N; int col = u % N;
		int x = row - 1; int y = col;//up
		if (x >= 0 && !visited[x*N + y] && dis[x*N + y] > dis[u] + matrix[x][y])
			dis[x*N + y] = dis[u] + matrix[x][y];

		x = row + 1;
		if (x<N && !visited[x*N + y] && dis[x*N + y] > dis[u] + matrix[x][y])
			dis[x*N + y] = dis[u] + matrix[x][y];

		x = row; y = col - 1;
		if (y >= 0 && !visited[x*N + y] && dis[x*N + y] > dis[u] + matrix[x][y])
			dis[x*N + y] = dis[u] + matrix[x][y];

		x = row; y = col + 1;
		if (y < N && !visited[x*N + y] && dis[x*N + y] > dis[u] + matrix[x][y])
			dis[x*N + y] = dis[u] + matrix[x][y];

	}

	return dis[N*N - 1];
}

int main() {
	int cases = 1;
	do
	{
		cin >> N;
		if (N == 0)
			break;

		memset(visited, 0, sizeof(visited));
		memset(dis, 0, sizeof(dis));

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> matrix[i][j];


		int result = shortest();
		cout << "Problem " << cases++ << ": " << result << endl;
	} while (true);
	//system("pause");
	return 0;
}
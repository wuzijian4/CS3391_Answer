#include <iostream>
#include <algorithm>
#include <memory.h>
#include <climits>

using namespace std;

int n, t; // �ڵ�����·����
int visited[1005];
int dis[1005];
int G[1005][1005];
#define INF 1000000
// һ����N���㣬 ÿ����֮��ľ���С��X�� ��ô�ܾ���С��(N-1)*x, INF ֻҪ���ڣ�N-1��*x����

int dijkstra() {
	memset(visited, 0, sizeof(visited));
	memset(dis, INF, sizeof(dis));
	dis[1] = 0;
	for (int i = 0; i < n; i++)
	{
		int u = -1;
		int MIN = INF;
		for (int j = 1; j <= n; j++)
		{
			if (visited[j] == 0 && dis[j] < MIN) {
				u = j;
				MIN = dis[j];
			}
		}

		visited[u] = 1;
		for (int v = 1; v <= n; v++) {
			if (visited[v] == 0 && G[u][v] != INF && u != v && dis[u] + G[u][v] < dis[v]) {
				dis[v] = dis[u] + G[u][v];
			}
		}
	}
	return dis[n];
}



int main() {
	while (cin >> n >> t)
	{
		memset(G, INF, sizeof(G));
		for (int i = 0; i < t; i++)
		{
			int n1, n2, d;
			cin >> n1 >> n2 >> d;
			G[n1][n2] = G[n2][n1] = d;
		}
		cout << dijkstra() << endl;
	}
}
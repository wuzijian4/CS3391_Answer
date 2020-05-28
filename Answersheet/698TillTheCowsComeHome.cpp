#include <iostream>
#include <algorithm>
#include <memory.h>
#include <climits>

using namespace std;

int n, t; // 节点数和路径数
int visited[1005];
int dis[1005];
int G[1005][1005];
#define INF 1000000
// 一共有N个点， 每两点之间的距离小于X， 那么总距离小于(N-1)*x, INF 只要大于（N-1）*x即可

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
#include <iostream>
#include <queue>
#include <memory.h>
#include <climits>
#include <algorithm>
using namespace std;

//将每个点拆分成两个点和有权重的边， 这样最多有200个点
int G[300][300];
int f[300][300];
int parent[300];
int visited[300];
int cf[300];
int n, m;
#define INF INT_MAX

bool bfs() {
	queue<int>q;
	int t = 2 * n + 1; int s = 0;
	memset(parent, 0, sizeof(parent));
	memset(visited, 0, sizeof(visited));
	memset(cf, 0, sizeof(cf));
	q.push(s);
	cf[s] = INF;
	visited[s] = 1;

	while (!q.empty())
	{
		int u = q.front(); q.pop();
		for (int v = 0; v <= t; v++) {
			if (!visited[v] && G[u][v] > f[u][v]) {
				visited[v] = true;
				parent[v] = u;
				q.push(v);
				cf[v] = min(cf[u], G[u][v] - f[u][v]);
			}
		}
		if (visited[t])
			return true;
	}
	return false;
}

int MaxFlow(int s, int t) {
	int power = 0;
	while (bfs())
	{
		power += cf[t];
		for (int i = t; i != s; i = parent[i])
		{
			f[parent[i]][i] += cf[t];
			f[i][parent[i]] -= cf[t];
		}
	}
	return power;
}



int main() {
	while (cin >> n)
	{
		int s = 0;
		int t = 2 * n + 1;

		memset(G, 0, sizeof(G));
		memset(f, 0, sizeof(f));

		for (int i = 1; i <= n; i++)
			cin >> G[i + n][i];

		cin >> m;
		int node1, node2, cost;
		for (int i = 1; i <= m; i++)
		{
			cin >> node1 >> node2 >> cost;
			G[node1][node2 + n] = cost;
		}

		int B, D;
		cin >> B >> D;
		int index;
		for (int i = 0; i < B; i++)
		{
			cin >> index;
			G[s][n + index] = INF;
		}

		for (int i = 0; i < D; i++)
		{
			cin >> index;
			G[index][t] = INF;
		}
		cout << MaxFlow(0, t) << endl;
	}
	return 0;
}
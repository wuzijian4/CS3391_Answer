#include <iostream>
#include <queue>
#include <climits>
#include <algorithm>
#include <memory.h>
using namespace std;
// core 和 module 之间构成了一张图, core1 和 core 2 之间一定有一个module
// 因为题目想要找到两个core最佳的分配方式,两个core一个为s 一个为t也就是说要找到一个图最佳的分割方式
// 最小割问题解决的就是找到流量最小的一个分割方式， 将题目转化为minimum cost
// 找minimum cost 就是找使core1 和 core 2 之间断连的minimum cut
// minimum cut == maxmum flow
int n, m;
int G[250][250];
int visited[250];
int f[250][250];
int c[250];
int parent[250];
#define INF INT_MAX


bool bfs(int s, int t) {
	queue<int>q;
	memset(parent, 0, sizeof(parent)); // 每次路径都会变化 所以在这里初始化
	memset(c, 0, sizeof(c)); //每次都会变化 所以写在这里
	memset(visited, 0, sizeof(visited)); //每次更新
	visited[s] = 1;
	q.push(s);
	c[s] = INF;
	while (!q.empty())
	{
		int u = q.front(); q.pop();
		for (int v = 0; v <= t; v++)
		{
			if (!visited[v] && G[u][v] > f[u][v]) {
				visited[v] = true;
				parent[v] = u;
				q.push(v);
				c[v] = min(c[u], G[u][v] - f[u][v]);
			}
		}
		if (visited[t])
			return true;
	}
	return false;

}

int Minimum(int s, int t) {
	int cost = 0;
	while (bfs(s, t))
	{
		cost += c[t];
		for (int i = t; i != s; i = parent[i])
		{
			f[parent[i]][i] += c[t];
			f[i][parent[i]] -= c[t];
		}
	}
	return cost;
}


int main() {
	while (cin >> n >> m)
	{
		memset(G, 0, sizeof(G));
		memset(f, 0, sizeof(f));
		//开始时容量和流量都是0

		for (int i = 1; i <= n; i++)
			cin >> G[0][i] >> G[i][n + 1];

		int a, b, w;
		for (int i = 1; i <= m; i++)
		{
			cin >> a >> b >> w;
			G[a][b] = w;
			G[b][a] = w;
		}
		int s = 0; int t = n + 1;
		int cost = Minimum(s, t);
		cout << cost << endl;
	}

	return 0;
}
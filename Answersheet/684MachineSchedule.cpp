
// minimum vertex cover �ҵ����԰������бߵĶ��㼯�� ����ĸ���������СҪ�仯����
// �� minimum vertex cover ������ maximum bipartite matching, �൱�ڼ�����ÿ����ѡ��һ����
// ��maximum bipartite matching �൱��ÿ���߶�Ϊ1��max flow
#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>
#include <memory.h>
using namespace std;

int n, m, k;
int G[300][300];
int f[300][300];
int visited[300];
int parent[300];
int c[300];
#define INF INT_MAX

bool bfs(int s, int t) {
	memset(parent, 0, sizeof(parent));
	memset(visited, 0, sizeof(visited));
	memset(c, 0, sizeof(c));
	visited[s] = 1;
	queue<int>q;
	q.push(s);
	c[s] = INF;

	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int v = 0; v <= t; v++)
		{
			if (!visited[v] && G[u][v] > f[u][v]) {
				visited[v] = 1;
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

int miniRestart(int s, int t) {
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
	while (cin >> n >> m >> k)
	{
		memset(G, 0, sizeof(G));
		memset(f, 0, sizeof(f));

		int a, b;
		for (int i = 0; i < k; i++)
		{
			cin >> a >> b;
			if (b != 0 && a != 0) {
				// �����ͻ ע�⵱a == 1, b==1;n==1ʱ
				// ����취������n+m+2���� 
				// a < n; n < v < n+m ; v = b + n; b < m-1;
				// s == n+m; t == n+m+1;
				G[a][b + n] = 1;
				G[n + m][a] = 1;
				G[b + n][n + m + 1] = 1;
			}
		}

		int s = n + m; int t = n + m + 1;
		cout << miniRestart(s, t) << endl;

	}
	return 0;
}
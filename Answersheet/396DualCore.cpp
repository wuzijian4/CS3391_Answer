#include <iostream>
#include <queue>
#include <climits>
#include <algorithm>
#include <memory.h>
using namespace std;
// core �� module ֮�乹����һ��ͼ, core1 �� core 2 ֮��һ����һ��module
// ��Ϊ��Ŀ��Ҫ�ҵ�����core��ѵķ��䷽ʽ,����coreһ��Ϊs һ��ΪtҲ����˵Ҫ�ҵ�һ��ͼ��ѵķָʽ
// ��С���������ľ����ҵ�������С��һ���ָʽ�� ����Ŀת��Ϊminimum cost
// ��minimum cost ������ʹcore1 �� core 2 ֮�������minimum cut
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
	memset(parent, 0, sizeof(parent)); // ÿ��·������仯 �����������ʼ��
	memset(c, 0, sizeof(c)); //ÿ�ζ���仯 ����д������
	memset(visited, 0, sizeof(visited)); //ÿ�θ���
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
		//��ʼʱ��������������0

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
// A robot defender may tackle at most once �� ÿ����ֻ�ܱ���һ��
// �൱��ÿ�����capacity��1�� ��������������һ����
#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>
#include <memory.h>
using namespace std;

int l, w, n, d;
int G[250][250];
int f[250][250];
int visited[250];
int c[250];
int parent[250];

struct node
{
	int x, y;
}defender[110];

#define INF INT_MAX

bool bfs(int s, int t) {
	memset(visited, 0, sizeof(visited));
	memset(parent, 0, sizeof(parent));
	memset(c, 0, sizeof(c));

	visited[s] = 0;
	c[s] = INF;
	queue<int> q;
	q.push(s);

	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int v = 0; v <= t; v++)
		{
			if (!visited[v] && G[u][v] > f[u][v]) {
				visited[v] = 1;
				q.push(v);
				parent[v] = u;
				c[v] = min(c[u], G[u][v] - f[u][v]);
			}
		}
		if (visited[t])
			return true;
	}
	return false;
}


int minTackle(int s, int t) {
	int flow = 0;
	while (bfs(s, t))
	{
		flow += c[t];
		for (int i = t; i != s; i = parent[i])
		{
			f[parent[i]][i] += c[t];
			f[i][parent[i]] -= c[t];
		}
	}
	return flow;
}


int main() {
	int count = 1;
	do
	{
		cin >> l >> w >> n >> d;
		if (l == 0 && w == 0 && d == 0 && n == 0)
			break;

		//һ����2*n+2 �����0��n+1
		memset(G, 0, sizeof(G));
		memset(f, 0, sizeof(f));

		int x, y;
		//�ܹ���
		for (int i = 1; i <= n; i++) {
			cin >> defender[i].x >> defender[i].y;
			G[i][i + n] = 1; // ����㵽����ľ�����1
			if (defender[i].y <= d) {
				G[0][i] = 1; // source �������
			}
			if ((w - defender[i].y) <= d) {
				G[i + n][2 * n + 1] = 1; // ���ߵ�ֵ��ΪINF�� ���ӳ���
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i != j) {
					int sq1 = pow(defender[i].x - defender[j].x, 2);
					int sq2 = pow(defender[i].y - defender[j].y, 2);
					int tmp = pow(2 * d, 2);
					if (tmp >= sq1 + sq2) {
						G[i + n][j] = 1;
					}

				}
			}
		}
		int s = 0; int t = 2 * n + 1;
		cout << "Case " << count++ << ": " << minTackle(s, t) << endl;
	} while (true);
	return 0;
}
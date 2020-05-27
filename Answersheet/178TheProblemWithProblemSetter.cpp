#include <iostream>
#include <queue>
#include <climits>
#include <algorithm>
#include <memory.h>
using namespace std;


#define INF INT_MAX
#define N 1100
int f[N][N], c[N][N], a[N], p[N];
//a数组是一个递推数组,p相当于记录路径
int n, m, s, t, flow;
queue <int> q;

void EK()
{
	flow = 0;
	while (!q.empty()) q.pop();
	while (1)
	{
		memset(a, 0, sizeof(a));
		a[s] = INF;
		q.push(s);
		while (!q.empty())
		{
			int u;
			u = q.front(); q.pop();
			for (int v = 1; v <= t; v++)  //枚举所有点v; <u,v>
				if (!a[v] && c[u][v] > f[u][v])
				{
					p[v] = u;  q.push(v);
					a[v] = a[u] < c[u][v] - f[u][v] ? a[u] : c[u][v] - f[u][v];
					//递推
				}
		}

		if (!a[t]) break;
		for (int u = t; u != s; u = p[u])
		{
			f[p[u]][u] += a[t];
			f[u][p[u]] -= a[t];
		}
		flow += a[t];
	}
	return;
}


int main() {
	do
	{
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;
		memset(f, 0, sizeof(f));
		memset(c, 0, sizeof(c));
		memset(p, 0, sizeof(p));
		s = 0; t = n + m + 1;

		int total = 0;
		for (int i = 1; i <= n; i++){
			cin >> c[s][i];
			total += c[s][i];
		}
		for (size_t i = 1; i <= m; i++)
		{
			int numOfCater;
			cin >> numOfCater;
			while (numOfCater--) {
				int cater;
				cin >> cater;
				c[cater][i+n] = 1;
			}
			c[i + n][t] = 1;
		}



		EK();
		
		if (flow == total)
			cout << 1 << endl;
		else
			cout << 0 << endl;

	} while (true);

	return 0;
}

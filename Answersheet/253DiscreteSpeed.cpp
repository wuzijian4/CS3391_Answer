#include <iostream>  
#include <iomanip>   
#include <memory.h>  
#include <queue>     
using namespace std;

#define INF 1000000
int n, m;
int s, g;
int visited[200][200][200];  //当前节点 当前速度 上一个节点

struct edge
{
	double distance;
	int limits;
}matrics[200][200];


struct node
{
	int index;
	int speed;
	int previous;
	double time;
	node(int i, int s, int p, double t) {
		index = i; speed = s; previous = p; time = t;
	}
	bool operator< (const node &n)const {
		return time > n.time;
		// priority queue的默认状态为大顶堆
	}
};


void clean() {
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			matrics[i][j].distance = INF;
			if (i == j)
				matrics[i][j].distance = 0;
			matrics[i][j].limits = -1;
		}
	}
}

double BFS() {

	double t = INF;
	memset(visited, 0, sizeof(visited));
	priority_queue < node> q;
	node e = { s, 0, 0, 0 };
	q.push(e);
	visited[s][0][0] = 1;
	while (!q.empty())
	{
		node p = q.top(); q.pop();
		for (int i = 1; i <= n; i++)
		{
			if (i != p.previous)
			{
				if (matrics[p.index][i].distance != INF && matrics[p.index][i].limits != -1 && i != p.index) {
					for (int j = -1; j <= 1; j++)
					{
						int sp = p.speed + j;
						if (sp > 0 && sp <= matrics[p.index][i].limits) {
							if (!visited[i][sp][p.index]) {
								double t2 = p.time + matrics[p.index][i].distance / (double)sp;
								node p2 = { i, sp, p.index, t2 };

								q.push(p2);
								if (p2.index == g && p2.speed == 1) {

									if (t > p2.time) {
										t = p2.time;
									}
								}
								visited[i][sp][p.index] = 1;
							}
						}
					}
				}
			}
		}
	}

	return t;
}

int main() {
	do
	{
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;
		clean();
		cin >> s >> g;
		int x, y, d, c;
		for (int i = 0; i < m; i++)
		{
			cin >> x >> y >> d >> c;
			matrics[x][y].distance = matrics[y][x].distance = d;
			matrics[x][y].limits = matrics[y][x].limits = c;
		}

		double t = BFS();
		if (t == INF)
			cout << "unreachable" << endl;
		else
			cout << fixed << setprecision(5) << t << endl;
	} while (true);
	return 0;
}
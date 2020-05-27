#include <iostream>
#include <memory.h>
#include <queue>
#include <iomanip>
#include <stdio.h>

using namespace std;

int visited[21]; // 最多只有20个节点
int G[21][21];
int n;

struct node
{
	int index;
	int numOfConquer;
};


int bfs(int s, int t) {
	memset(visited, 0, sizeof(visited));
	visited[s] = 1;
	node p = { s, 0 };
	queue<node> q;
	q.push(p);
	while (!q.empty())
	{
		node p2 = q.front(); q.pop();
		if (p2.index == t)
			return p2.numOfConquer;

		for (int i = 1; i <= 20; i++)
		{
			if (!visited[i] && i != p2.index && G[p2.index][i] == 1) {
				int num = p2.numOfConquer + 1;
				node temp;
				temp.index = i;
				temp.numOfConquer = num;
				visited[i] = 1;
				q.push(temp);
			}
		}

	}
	return -1;
}



int main() {
	int count = 1;
	while (cin>>n)
	{

		memset(G, 0, sizeof(G));
		int index = 1;
		for (int i = 0; i < n; i++)
		{
			int adjacency;
			cin >> adjacency;
			G[index][adjacency] = 1;
			G[adjacency][index] = 1;
		}

		int n2 = 0;
		for (int i = 2; i <= 19; i++)
		{
			index++;
			cin >> n2;
			for (int j = 0; j < n2; j++)
			{
				int adjacency;
				cin >> adjacency;
				G[index][adjacency] = 1;
				G[adjacency][index] = 1;
			}
		}

		int pairs;
		cin >> pairs;
		cout << "Test Set #" << count++ << endl;
		for (int i = 0; i < pairs; i++)
		{
			int s, t;
			cin >> s >> t;
			int result = bfs(s, t);
			printf("%2d to %2d: %d\n", s, t, result);

		}
		cout << endl;
	}
	return 0;
}

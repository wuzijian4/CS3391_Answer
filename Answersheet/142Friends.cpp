#include <iostream>
#include <stdlib.h>
#include <memory.h>
#include <algorithm>
using namespace std;

int parent[30005];

int find(int e) {
	if (parent[e] < 0)
		return e;
	else
		return parent[e] = find(parent[e]);
}

void Unionset(int e1, int e2) {
	parent[e1] += parent[e2];
	parent[e2] = e1;
}

void Union(int e1, int e2) {	
	int root1 = find(e1);
	int root2 = find(e2);

	if (root1 == root2)
		return;
	if (parent[root1] < parent[root2])
		Unionset(root1, root2);
	else
		Unionset(root2, root1);
}

int main() {
	int cases;
	cin >> cases;

	while (cases--)
	{
		int n, m;
		cin >> n >> m;
		memset(parent, -1, sizeof(parent));
		int c1, c2;
		for (int i = 0; i < m; i++)
		{
			cin >> c1 >> c2;
			Union(c1, c2);
		}
		int mini = parent[0];
		for (int i = 1; i <= n; i++)
			mini = min(mini, parent[i]);
		cout << abs(mini) << endl;
	}
	//system("pause");
	return 0;
}

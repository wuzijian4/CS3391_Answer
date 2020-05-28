#include <iostream>
#include <stdlib.h>
#include <memory.h>
using namespace std;

int n, m;
int parent[510];


struct edge
{
	int from;
	int to;
	int ppa;
};

int cmp(const void* a, const void* b) {
	edge* x = (edge*)a;
	edge* y = (edge*)b;
	return y->ppa - x->ppa;
	//decresing order	
}

int find(int e) {
	if (parent[e] < 0)
		return e;
	else
		return parent[e] = find(parent[e]);
}

void UnionSet(int e1, int e2) {
	parent[e1] += parent[e2];
	parent[e2] = e1;
}

void Union(int e1, int e2) {
	int root1 = find(e1);
	int root2 = find(e2);

	if (root1 == root2)
		return;

	if (parent[root1] < parent[root2])
		UnionSet(root1, root2);
	else
		UnionSet(root2, root1);
	return;
}



int main() {
	do
	{
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;
		edge *edges = new edge[m + 1];
		edge *Maxedges = new edge[m + 1];
		for (int i = 0; i < m; i++)
			cin >> edges[i].from >> edges[i].to >> edges[i].ppa;

		qsort(edges, m, sizeof(edge), cmp);

		int k = 0;

		for (int i = 0; i < m; i++)
		{
			if (edges[i].ppa != edges[0].ppa)
				break;
			else
				Maxedges[k++] = edges[i];
		}

		memset(parent, -1, sizeof(parent));
		for (int i = 0; i < k; i++) {
			Union(Maxedges[i].from, Maxedges[i].to);
		}

		int min = parent[0];
		for (int i = 1; i <= n; i++)
		{
			if (min > parent[i])
				min = parent[i];
		}
		cout << abs(min) << endl;

		delete(edges);
		delete(Maxedges);
	} while (true);
	return 0;
}
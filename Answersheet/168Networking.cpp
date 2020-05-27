#include <iostream>
#include <memory.h>
#include <stdlib.h>
using namespace std;

int p, r;
int parent[51];
// the maximum of nodes is 50

struct edge
{
	int n1, n2;
	int len;
};

int cmp(const void *a, const void *b) {
	edge *x = (edge*)a;
	edge *y = (edge*)b;
	return x->len - y->len;
}

int find(int e) {
	if (parent[e] < 0)
		return e;      // find the parent node
	else
		return parent[e] = find(parent[e]); // path compression, point to the top most element
}

bool Union(int e1, int e2, int len) {
	int root1 = find(e1);
	int root2 = find(e2);

	//并查集， 将不在同一个set的node合并在一起
	if (root1 == root2)
		return false; // two nodes belong to the same set, 
	//cycle formed, return false;

	if (parent[root1] < parent[root2]) {
		parent[root1] += parent[root2];
		parent[root2] = root1;
	}
	else
	{
		parent[root2] += parent[root1];
		parent[root1] = root2;
	}
	return true;
}


int main() {
	do
	{
		cin >> p >> r;
		if (p == 0)
			break;
		if (r == 0) {
			cout << 0 << endl;
			continue;
		}

		edge *edges = new edge[r+1];
		memset(parent, -1, sizeof(parent));
		for (int i = 0; i < r; i++)
			cin >> edges[i].n1 >> edges[i].n2 >> edges[i].len;

		qsort(edges, r, sizeof(edge), cmp);
		int numOfEdges = 0;
		int cable = 0;
		for (int i = 0; i < r; i++)
		{
			if (Union(edges[i].n1, edges[i].n2, edges[i].len))
			{
				cable += edges[i].len;
				numOfEdges++;
			}
			if (numOfEdges == p - 1)
				break;
		}
		cout << cable << endl;
	} while (true);
	return 0;
}

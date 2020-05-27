#include <iostream>
#include <memory.h>
#include <stdlib.h>
using namespace std;

int n, m;
int parent[150];  // 初始值为-1，数组大小为节点总数
// the maximum of nodes is 50

struct edge
{
	int n1, n2;
	int len;
};

int cmp(const void *a, const void *b) {
	edge *x = (edge*)a;
	edge *y = (edge*)b;
	return y->len - x->len;
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
		// 如果root1 的node大于 root2 的node，将root2合并到root1
	}
	else
	{
		parent[root2] += parent[root1];
		parent[root1] = root2;

	}
	return true;
}


int main() {
	int cases;
	cin >> cases;
	for (int count = 1; count <= cases; count++)
	{
		cin >> n >> m;
		edge* e = new edge[m + 1];
		memset(parent, -1, sizeof(parent));
		for (size_t i = 0; i < m; i++)
		{
			cin >> e[i].n1 >> e[i].n2 >> e[i].len;
		}
		qsort(e, m, sizeof(edge), cmp);
		int minMax = e[0].len;
		int numOfEdge = 0;
		for (int i = 0; i < m; i++)
		{
			if (Union(e[i].n1, e[i].n2, e[i].len)) {
				numOfEdge++;
				if (e[i].len < minMax)
					minMax = e[i].len;
			}
			if (numOfEdge == n - 1)
				break;
		}
		cout << "Case #" << count << ": " << minMax << endl;
	}
	return 0;
}

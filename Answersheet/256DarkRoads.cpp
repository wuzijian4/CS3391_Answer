#include <iostream>
#include <memory.h>
#include <stdlib.h>
using namespace std;

int m, n;
int parent[200002];  // 初始值为-1，数组大小为节点总数
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
	do
	{
		cin >> m >> n;
		if (m == 0 && n == 0)
			break;

		edge* e = new edge[n + 1];
		memset(parent, -1, sizeof(parent));
		int sum = 0;
		for (size_t i = 0; i < n; i++)
		{
			cin >> e[i].n1 >> e[i].n2 >> e[i].len;
			sum += e[i].len;
		}
		qsort(e, n, sizeof(edge), cmp);
		int mini = 0;
		int numOfEdge = 0;
		for (int i = 0; i < n; i++)
		{
			if (Union(e[i].n1, e[i].n2, e[i].len)) {
				mini += e[i].len;
				numOfEdge++;
			}
			if (numOfEdge == m - 1)
				break;
		}
		cout << sum - mini << endl;


	} while (true);
	return 0;
}
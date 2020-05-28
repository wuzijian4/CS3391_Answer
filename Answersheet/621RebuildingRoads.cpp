#include <iostream>
#include <stdlib.h>
#include <string>
#include <memory.h>
using namespace std;

// 如果没有路就修路， 如果生成了一个环就拆除， cost也要相应的增加
// 一共有（n-1+1)*n/2个边
int c[100][100];
int b[100][100];
int d[100][100];
int parent[100];
int n;
struct edge {
	int from, to;
	int len;
};

//increasing order
int cmp(const void* a, const void* b) {
	edge* x = (edge*)a;
	edge* y = (edge*)b;
	return x->len - y->len;
}

//decreasing order
int cmp2(const void*a, const void* b) {
	edge*x = (edge*)a;
	edge*y = (edge*)b;
	return y->len - x->len;
}

int find(int e) {
	if (parent[e] < 0)
		return e;
	else
		return parent[e] = find(parent[e]);
}

int Union(int e1, int e2, int len) {
	int root1 = find(e1);
	int root2 = find(e2);

	if (root1 == root2) {
		return 0;
	}


	if (parent[root1] < parent[root2]) {
		parent[root1] += parent[root2];
		parent[root2] = root1;
	}
	else
	{
		parent[root2] += parent[root1];
		parent[root1] = root2;
	}
	return 1;
}


int main() {
	do
	{
		cin >> n;
		if (n == 0)
			break;
		cin.ignore();
		int n1 = 0; int n2 = 0;
		//num of connected edges and unconnected edges

		for (int i = 0; i < n; i++) {
			string in; getline(cin, in);
			for (int j = 0; j < in.length(); j++) {
				c[i][j] = in[j] - 48;
				if (j > i && c[i][j] == 1)
					n1++;
				else if (j > i && c[i][j] == 0)
					n2++;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> b[i][j];
			}
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> d[i][j];


		edge *Remove = new edge[n1];
		edge *Add = new edge[n2];
		int ct1 = 0; int ct2 = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (j > i) {
					if (c[i][j] == 1) {
						Remove[ct1].from = i;
						Remove[ct1].to = j;
						Remove[ct1].len = d[i][j];
						ct1++;
					}
					else
					{
						Add[ct2].from = i;
						Add[ct2].to = j;
						Add[ct2].len = b[i][j];
						ct2++;
					}
				}
			}
		}

		memset(parent, -1, sizeof(parent));
		int cost = 0;
		qsort(Remove, n1, sizeof(edge), cmp2); // decreasing order
		for (int i = 0; i < n1; i++)
		{
			if (Union(Remove[i].from, Remove[i].to, Remove[i].len) == 0) {
				cost += Remove[i].len; // remove the existing edge that form the cycle
			}
		}

		qsort(Add, n2, sizeof(edge), cmp);
		for (int i = 0; i < n2; i++)
		{
			if (Union(Add[i].from, Add[i].to, Add[i].len) == 1) {
				cost += Add[i].len;
			}
		}
		cout << cost << endl;
	} while (true);
	return 0;
}
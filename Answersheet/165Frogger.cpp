#include <iostream>
#include <memory.h>
#include <cmath>
#include <math.h>
#include <algorithm>
#include <iomanip>
using namespace std;

#define MIN 10000000

struct node
{
	int x, y;
};
node stones[300] = {};
double matrix[300][300] = {};
int visited[300] = {};
double d[300] = {};

double distance(node m, node n)
{
	return (double)sqrt((m.x - n.x)*(m.x - n.x) + (m.y - n.y)*(m.y - n.y));
}

double shortestPath(int n) {
	//intializtion
	memset(visited, 0, sizeof(visited));
	for (int i = 1; i < n; i++)
		d[i] = MIN;
	d[0] = 0; // starting point

	// build the adjacent matrix
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			matrix[i][j] = distance(stones[i], stones[j]);

	for (int i = 0; i < n; i++)
	{	
		// traverse until all the nodes has been visited
		int u = -1;
		double minn = MIN;
		for (int j = 0; j < n; j++)
		{
			if (!visited[j] && d[j] <= minn)
			{
				u = j;
				minn = d[j];
 			}
		}
		visited[u] =1;
		for (int k = 0; k < n; k++) {
			d[k] = min(d[k], max(d[u], matrix[u][k]));
			// the minimum one of the longest edge
		}
	}


	return d[1];
}

int main() {
	int num;
	int cases = 1;
	do
	{
		cin >> num;
		if (num == 0)
			break;
		for (int i = 0; i < num; i++)
			cin >> stones[i].x >> stones[i].y;

		double result = shortestPath(num);

		cout << "Scenario #" << cases++ << endl;
		cout << "Frog Distance = " <<fixed<<setprecision(3)<<result << endl;
		cout << endl;
		
	} while (true);
	return 0;
}

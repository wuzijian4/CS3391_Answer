#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;


int INF = 1000000007;
int n, m;
int items[1000001];

//走楼梯问题的变式, 不分先后顺序的上楼梯 动态规划问题
// top-down approach


int main() {
	while (scanf("%d%d", &n, &m) != EOF)
	{
		for (int k = 0; k <= n; k++)
		{
			items[k] = 0;
			if (k == 0)
				items[k] = 1;
		}
		int i = 0;
		while (pow(m, i) <= n)
		{
			int tmp = pow(m, i);
			for (int j = 1; j <= n; j++)
			{
				if (j >= tmp)
					items[j] = (items[j] + items[j - tmp]) % INF;
			}
			i++;
		}
		cout << items[n] << endl;
	}
	return 0;
}
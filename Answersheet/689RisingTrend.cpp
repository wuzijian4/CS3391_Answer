#include <iostream>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;

int n;
int stock[1000001];
int riseQueue[1000001]; // 存储每个元素的最长子序列
//stock[i] 的最长子序列等于 store[j] + 1 stock[j] < stock[i] 且stock[j] 最大
//stock[j] = stock 二分法优化


int main() {
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
			cin >> stock[i];

		memset(riseQueue, 0, sizeof(riseQueue));
		int len = 0; riseQueue[0] = stock[0];
		for (int i = 1; i < n; i++)
		{
			//如果大于递增列表中的最大元素就直接插入
			if (stock[i] >= riseQueue[len]) {
				riseQueue[++len] = stock[i];
			}
			else
			{
				// 如果小于递增列表的最大值 就找到第一个比他大的位置插入
				int middle = 0; int s = 0; int e = len;
				while (s <= e)
				{
					middle = (s + e) / 2;
					if (stock[i] > riseQueue[middle]) {
						if (stock[i] < riseQueue[middle + 1]) {
							middle++;
							break;
						}
						s = middle + 1;
					}
					else if (stock[i] < riseQueue[middle])
					{
						e = middle - 1;
					}
					else if (stock[i] == riseQueue[middle]) {
						while (stock[i] == riseQueue[middle])
							middle++;
						break;
					}
				}
				riseQueue[middle] = stock[i];
			}
		}
		len++;
		cout << len << endl;
	}
	return 0;
}
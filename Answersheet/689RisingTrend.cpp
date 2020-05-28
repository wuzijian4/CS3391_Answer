#include <iostream>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;

int n;
int stock[1000001];
int riseQueue[1000001]; // �洢ÿ��Ԫ�ص��������
//stock[i] ��������е��� store[j] + 1 stock[j] < stock[i] ��stock[j] ���
//stock[j] = stock ���ַ��Ż�


int main() {
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
			cin >> stock[i];

		memset(riseQueue, 0, sizeof(riseQueue));
		int len = 0; riseQueue[0] = stock[0];
		for (int i = 1; i < n; i++)
		{
			//������ڵ����б��е����Ԫ�ؾ�ֱ�Ӳ���
			if (stock[i] >= riseQueue[len]) {
				riseQueue[++len] = stock[i];
			}
			else
			{
				// ���С�ڵ����б�����ֵ ���ҵ���һ���������λ�ò���
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
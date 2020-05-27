#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <stack>
#include <climits>
#include <map>
using namespace std;

#define INF 1e6

string places[200] = {};
int matrics[200][200];
int dist[200];
int path[200]; //存储上一个节点
int visited[200];
int N;
int route;
int start; int goal;

void clean() {
	for (int i = 0; i < 200; i++)
	{
		for (int j = 0; j < 200; j++)
		{
			matrics[i][j] = INF;
			if (i == j)
				matrics[i][j] = 0;
		}
	}
}


int dijkstra(int start, int goal) {
	for (int i = 1; i <= N; i++)
		dist[i] = INF;
	dist[start] = 0;

	for (int i = 1; i <= N; i++)
	{

		visited[i] = path[i] = 0;
	}

	for (int i = 0; i < N; i++)
	{
		int min = INF;
		int u = -1;
		for (int j = 1; j <= N; j++)
		{
			if (!visited[j] && dist[j] <= min) {
				min = dist[j];
				u = j;
			}
		}
		visited[u] = 1;

		for (int k = 1; k <= N; k++)
		{
			if (!visited[k] && dist[k] > dist[u] + matrics[u][k]) {
				dist[k] = dist[u] + matrics[u][k];
				path[k] = u;
			}
		}

	}
	
	return dist[goal];
}

string print(int start, int goal) {
	int j = goal;
	stack<int> st;
	while (path[j] != start) //有中间节点
	{
		st.push(path[j]);
		j = path[j];
	}
	string path1 = " -> ";
	while (!st.empty())
	{
		path1 += (places[st.top()]+" -> ");
		st.pop();
	}
	return path1;
}

int main() {
	while (scanf("%d", &N) != EOF)
	{
		clean();
		cin.ignore();  // cin 会将换行符留在输入流中。 清除换行符，避免getline读入而提前终止
		map<string, int> index;
		
		for (int i = 1; i <= N; i++)
		{
			getline(cin, places[i]);
			index[places[i]] = i;

			if (places[i] == "office")
				start = i;

			if (places[i] == "hall")
				goal = i;
		}


		
		int num;
		cin >> num;
		cin.ignore();

		for (int i = 0; i < num; i++)
		{
			string in;
			string	p1;
			string	p2;
			int n1 = 0, n2 = 0;
			map<string, int> ::iterator iter;
			getline(cin, in); 
			int flag = 0;

			for (int j = 0; j < in.length(); j++)
			{
				if (in[j] == ':') {
					flag = 1;
					continue;
				}
				if (flag == 0)
					p1 += in[j];
				else
				{
					while (true)
					{
						iter = index.find(p2);
						if (iter == index.end()) {
							p2 += in[j];
							j++;
							
						}
						else {
							break;
						}
						
					}
					
					j++; //当前j是空格 要加1跳过
					string str;
					while (j < in.length() && isdigit(in[j]))
					{
						str += in[j];
						j++;
					}
					n1 = atoi(str.c_str());
					//cout << n1 << endl;
					if (j < in.length() && in[j] == ' ') {
						// 有两个数字
						j++;//跳过空格
						string str2;
						while (j < in.length() && isdigit(in[j]))
						{
							str2 += in[j];
							j++;
						}
						n2 = atoi(str2.c_str());
						//cout << n2 << endl;
					}
				}
			}
			
			
			// 读完一行 找出string的位置
			map<string, int>::iterator it1 = index.find(p1);
			map<string, int>::iterator it2 = index.find(p2);
			matrics[it1->second][it2->second] = n1; // p1 到 p2 的距离
			if (n2 != 0)
				matrics[it2->second][it1->second] = n2;	
		}
		
		
		int r1 = dijkstra(start, goal);
		
		string p1 = print(start, goal);
		int r2 = dijkstra(goal, start);
		
		string p2 = print(goal, start);
		cout << r1 + r2 << endl;
		cout << "office" << p1 << "hall" << p2 << "office" << endl << endl;
	}
	return 0;
}

#include <iostream>
#include <stdio.h>
#include <queue>
#include <cstring>
using namespace std;

int cup[4] = { 0 };
int T;
int visited[25][25][25][25] = { 0 };

struct node
{
	int state[4];
	int step;
	node(int* state_, int step_) {
		for (int i = 0; i < 4; ++i)
			state[i] = state_[i];
		step = step_;
	}
};

queue<node> st;
int bfs() {
	int cups[4] = { 0, 0, 0, 0 };
	node q = { cups, 0 };
	visited[0][0][0][0] = 1;
	st.push(q);

	while (!st.empty())
	{
		node p = st.front();
		st.pop();

		if (p.state[0] == T || p.state[1] == T || p.state[2] == T || p.state[3] == T)
			return p.step;

		for (int i = 0; i < 4; i++)  // pour the flour from i to j
		{
			for (int j = 0; j < 4; j++)
			{
				if (i != j && p.state[i] != 0 && p.state[j] < cup[j])
				{
					int flour = cup[j] - p.state[j];
					int a[4] = { p.state[0], p.state[1], p.state[2], p.state[3] };
					node tmp = { a, p.step + 1 };

					if (tmp.state[i] >= flour) {
						tmp.state[i] -= flour;
						tmp.state[j] += flour;
					}
					else
					{
						tmp.state[j] += tmp.state[i];
						tmp.state[i] = 0;
					}

					if (!visited[tmp.state[0]][tmp.state[1]][tmp.state[2]][tmp.state[3]])
					{
						st.push(tmp);
						visited[tmp.state[0]][tmp.state[1]][tmp.state[2]][tmp.state[3]] = 1;
					}
				}

			}
		}
		//empty one cup
		for (int i = 0; i < 4; i++)
		{
			if (p.state[i] != 0) {
				int a[4] = { p.state[0], p.state[1], p.state[2], p.state[3] };
				node tmp = { a, p.step + 1 };
				tmp.state[i] = 0;
				if (!visited[tmp.state[0]][tmp.state[1]][tmp.state[2]][tmp.state[3]]) {
					st.push(tmp);
					visited[tmp.state[0]][tmp.state[1]][tmp.state[2]][tmp.state[3]] = 1;
				}
			}
		}

		for (int j = 0; j < 4; j++)  //fill one cup full of flour
		{
			if (p.state[j] < cup[j]) {
				int a[4] = { p.state[0], p.state[1], p.state[2], p.state[3] };
				node tmp = { a, p.step + 1 };
				tmp.state[j] = cup[j];
				if (!visited[tmp.state[0]][tmp.state[1]][tmp.state[2]][tmp.state[3]]) {
					st.push(tmp);
					visited[tmp.state[0]][tmp.state[1]][tmp.state[2]][tmp.state[3]] = 1;
				}
			}
		}

	}

	return -1;
}


int main() {
	while (scanf("%d%d%d%d%d", &cup[0], &cup[1], &cup[2], &cup[3], &T) != EOF)
	{
		memset(visited, 0, sizeof(visited));// ³õÊ¼»¯
		while (!st.empty())st.pop();
		int result = bfs();
		cout << result << endl;
	}
	return 0;
}
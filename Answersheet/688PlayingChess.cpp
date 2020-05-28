#include <iostream>
#include <queue>
using namespace std;

int visited[8][8] = { 0 };
char chessBoard[8][8];
int x = 0;


struct node
{
	int row;
	int col;
	int step;
};

queue<node> st;
int bfs() {
	//find the position of black knight and push the node into the queue
	while (!st.empty())
	{
		node p = st.front();
		st.pop();
		if (chessBoard[p.row][p.col] == '@')
			return p.step;
		int j = p.row - 2; int k = p.col - 1;
		if (j >= 0 && k >= 0 && !visited[j][k] && chessBoard[j][k] != '*') {
			node z = { j,k, p.step + 1 };
			st.push(z); visited[j][k] = 1;
		}

		j = p.row - 2; k = p.col + 1;
		if (j >= 0 && k < 8 && !visited[j][k] && chessBoard[j][k] != '*') {
			node z = { j,k,p.step + 1 };
			st.push(z); visited[j][k] = 1;
		}

		j = p.row + 2; k = p.col - 1;
		if (j < 8 && k >= 0 && !visited[j][k] && chessBoard[j][k] != '*') {
			node z = { j,k,p.step + 1 };
			st.push(z); visited[j][k] = 1;
		}

		j = p.row + 2; k = p.col + 1;
		if (j < 8 && k < 8 && !visited[j][k] && chessBoard[j][k] != '*') {
			node z = { j,k,p.step + 1 };
			st.push(z); visited[j][k] = 1;
		}

		j = p.row - 1; k = p.col - 2;
		if (j >= 0 && k >= 0 && !visited[j][k] && chessBoard[j][k] != '*') {
			node z = { j,k,p.step + 1 };
			st.push(z); visited[j][k] = 1;
		}

		j = p.row - 1; k = p.col + 2;
		if (j >= 0 && k < 8 && !visited[j][k] && chessBoard[j][k] != '*') {
			node z = { j,k,p.step + 1 };
			st.push(z); visited[j][k] = 1;
		}

		j = p.row + 1; k = p.col - 2;
		if (j < 8 && k >= 0 && !visited[j][k] && chessBoard[j][k] != '*') {
			node z = { j,k,p.step + 1 };
			st.push(z); visited[j][k] = 1;
		}

		j = p.row + 1; k = p.col + 2;
		if (j < 8 && k < 8 && !visited[j][k] && chessBoard[j][k] != '*') {
			node z = { j,k,p.step + 1 };
			st.push(z); visited[j][k] = 1;
		}

	}
	return -1;
}

void clean() {
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			visited[i][j] = 0;
	while (!st.empty())
		st.pop();

}

int main() {
	int cases; int j = 0;
	cin >> cases;
	while (j < cases)
	{
		clean();
		int result = 0;
		node begin;
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				char c;
				cin >> c;
				if (c == '#')
				{
					begin.row = i;
					begin.col = j;
				}
				chessBoard[i][j] = c;
			}
		}
		begin.step = 0;
		st.push(begin);
		visited[begin.row][begin.col] = 1;

		result = bfs();
		if (result == -1)
			cout << "Case " << j + 1 << ": IMPOSSIBLE" << endl;
		else
			cout << "Case " << j + 1 << ": " << result << endl;
		j++;
	}
	return 0;
}
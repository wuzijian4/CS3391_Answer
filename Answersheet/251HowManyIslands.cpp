#include <iostream>
#include <queue>
using namespace std;

int width, height;
int mesh[50][50];
int visited[50][50] = {};

struct node
{
	int row;
	int col;
};

//先找到一个没有标记的点， 然后遍历整个图，把一个图里面所有的点都标记起来；
//这样每次碰到一个未标记的点 都是一个新的图
int count() {
	int num = 0;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (mesh[i][j] == 1 && !visited[i][j])
			{
				queue<node> islands;
				node k = { i,j }; islands.push(k);
				visited[i][j] = 1;
				while (!islands.empty())
				{
					node z = islands.front();
					islands.pop();
					for (int x = z.row - 1; x <= z.row + 1; x++)
					{
						for (int y = z.col - 1; y <= z.col + 1; y++)
						{
							if (x >= 0 && x < height && y >= 0 && y < width) {
								if (!visited[x][y] && mesh[x][y] == 1) {
									node z = { x,y };
									islands.push(z);
									visited[x][y] = 1;
								}
							}
						}
					}
				}
				num++;
			}
		}
	}

	return num;
}

void clean() {
	for (int i = 0; i < 50; i++)
		for (int j = 0; j < 50; j++)
			visited[i][j] = 0;
}

int main() {
	do
	{
		cin >> width >> height;
		if (width == 0 && height == 0)
			break;
		clean();

		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				int in;
				cin >> in;
				mesh[i][j] = in;
			}
		}

		int result = count();
		cout << result << endl;

	} while (true);
	//system("pause");
	return 0;
}
#include <iostream>
#include <memory.h>
using namespace std;

#define INF 2
int N, M;
int A, B;
int matrix[200][200];

int ranks() {
	int num = N;
	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (matrix[i][k] == 1 && matrix[k][j] == 1) {
					matrix[i][j] = 1;
					matrix[j][i] = -1;
				}
				else if (matrix[i][k] == -1 && matrix[k][j] == -1) {
					matrix[i][j] = -1;
					matrix[j][i] = 1;
				}
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (i != j && matrix[i][j] == 0) {
				num -= 1;
				break;
			}
		}
	}

	return num;
}



int main() {
	while (scanf("%d%d", &N, &M) != EOF)
	{
		for (int i = 0; i <= N; i++)
			for (int j = 0; j <= N; j++)
				matrix[i][j] = 0;

		for (int i = 0; i < M; i++)
		{
			cin >> A >> B;
			// relationship
			matrix[A][B] = 1;  // A wins B
			matrix[B][A] = -1; // B loses A
		}
		int results = ranks();
		cout << results << endl;
	}

	return 0;
}

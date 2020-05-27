#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

string str1;
string str2;
int store[2000][2000];


int LCS(int n, int m) {
	int result = 0;
	if (store[n][m] != -1)
		return store[n][m];

	if (n == 0 || m == 0)
		result = 0;
	else if (str1[n - 1] == str2[m - 1]) {
		result = 1 + LCS(n - 1, m - 1);
	}
	else
		result = max(LCS(n - 1, m), LCS(n, m - 1));

	store[n][m] = result;
	return result;
}


void clean() {
	for (int i = 0; i < 2000; i++)
		for (int j = 0; j < 2000; j++)
			store[i][j] = -1;
}

int main() {
	while (getline(cin, str1))
	{
		getline(cin, str2);
		clean();
		int n = str1.length();
		int m = str2.length();

		int result = LCS(n, m);
		cout << result << endl;
	}


	return 0;
}
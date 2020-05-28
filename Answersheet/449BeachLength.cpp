#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int totalLength(string* str, int numOfelements) {
	int len = 0; int count = 0;
	for (int i = 0; i < numOfelements; i++)
	{
		for (int j = 0; j < str[i].length(); j++)
		{
			if (str[i][j] == '#') {
				if ((i & 1) == 0) //even row
				{
					if (j - 1 >= 0 && str[i][j - 1] == '.') len++; //left
					if (j + 1 < str[i].length() && str[i][j + 1] == '.') len++; //right
					if (i - 1 >= 0 && j - 1 >= 0 && str[i - 1][j - 1] == '.')len++; // left upper corner
					if (i - 1 >= 0 && str[i - 1][j] == '.')len++; //right upper corner
					if (i + 1 < numOfelements&&j - 1 >= 0 && str[i + 1][j - 1] == '.')len++; //left lower corner
					if (i + 1 < numOfelements&&str[i + 1][j] == '.')len++;
				}
				else   // odd row
				{
					if (j - 1 >= 0 && str[i][j - 1] == '.') len++; //left
					if (j + 1 < str[i].length() && str[i][j + 1] == '.') len++; //right
					if (i - 1 >= 0 && str[i - 1][j] == '.')len++;//left upper corner
					if (i - 1 >= 0 && j + 1 < str[i].length() && str[i - 1][j + 1] == '.')len++;//right upper corner
					if (i + 1 < numOfelements&&str[i + 1][j] == '.')len++;//left lower corner
					if (i + 1 < numOfelements&&str[i + 1][j + 1] == '.')len++;//right lower corner
				}
			}
		}
	}

	return len;
}

int main() {
	string st[100];
	int i = 0;
	while (getline(cin, st[i]))
	{
		if (st[i].length() == 0) {
			// test case is finished reading
			int length = totalLength(st, i);
			cout << length << endl;
			i = 0;
			continue;
		}
		i++;
	}
	if (i > 0) {
		int length = totalLength(st, i);
		cout << length;
	}
	return 0;
}
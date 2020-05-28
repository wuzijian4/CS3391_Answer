#include <iostream>
#include <string>
#include <math.h>
#include <cmath>  
#include <algorithm>
using namespace std;


string name;

int calculate(char c) {
	int index = c - 64;
	if (index <= 13)
		return index - 1;
	else
		return 26 + 1 - index;
	return 0;
}


int numOfUpDown() {
	int counter = 0;
	for (int i = 0; i < (int)name.length(); i++)
		counter += calculate(name[i]);

	return counter;
}


int main() {
	int cases;
	cin >> cases;
	while (cases--)
	{
		cin >> name;
		int mini = 1100; // the minimum steps
		int num1 = numOfUpDown();

		int i = 0; int len = (int)name.length();
		while (i < len)
		{
			if (name[i] != 'A') {
				i++;
			}
			else
			{
				int j = i;
				while (j < len && name[j] == 'A')
					j++;
				if (i == 0) {
					if (mini > len - j)
						mini = len - j;
					i = j;
				}
				else
				{
					if (j == len) {
						mini = min(mini, i - 1);
						i = j;
						//cout << mini << endl;
					}
					else
					{
						mini = min(mini, (i - 1) * 2 + len - j);
						mini = min(mini, (len - j) * 2 + i - 1);
						//cout << mini << endl;
						i = j;
					}
				}
			}
		}
		mini = min(mini, len - 1);
		//cout << mini << " " << num1 << endl;
		cout << num1 + mini << endl;
	}
	//	system("pause");
	return 0;
}
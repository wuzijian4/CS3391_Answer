#include <iostream>
#include <sstream>
#include <string>
using namespace std;
//A word is composed of only letters of the alphabet (a-z, A-Z) and may contain one hyphen (-)
//or more.


int main() {
	string longest; int max = 0;
	string input;

	do
	{
		cin >> input;
		if (input == "E-N-D")
			break;
		
		string tmp = "";
		for (int i = 0; i < input.length(); i++)
		{
			if (isalpha(input[i]) || input[i] == '-') {
				char temp = tolower(input[i]);
				tmp += temp; // 转化为小写
			}
		}
		if (tmp.length() > max) {
			longest = tmp;
			max = tmp.length();
		}

	} while (true);
	cout << longest << endl;
	//system("pause");
	return 0;
}

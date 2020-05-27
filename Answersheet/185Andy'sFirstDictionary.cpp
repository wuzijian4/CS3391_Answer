#include <iostream>
#include <string>
#include <set>
using namespace std;


int main() {
	string input;
	set<string>s; //less 函数, 默认升序, 如果使用结构体，要重载运算符
	s.clear();
	while (getline(cin, input))
	{
		string str = "";
		for (int i = 0; i <= input.length(); i++)
		{
			if (i<input.length() && isalpha(input[i])) {
				char tmp = tolower(input[i]);
				str += tmp;
			}
			else if(str.length() > 0)
			{
				s.insert(str);
				str = "";
			}
		}
	}
	// 创建一个迭代器
	set<string>::iterator it;
	for (it = s.begin(); it != s.end(); it++)
		cout << *it << endl;
	return 0;
}

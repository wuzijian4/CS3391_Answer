#include <iostream>
#include <string>
using namespace std;

//���� lexicographical order �ҳ�����Ԫ��Ȼ��ƴ��һ��
int main() {
	int cases;
	cin >> cases;
	cin.ignore();
	while (cases--)
	{
		string in;
		getline(cin, in);
		string out = "";
		char maximum = in[0];

		for (int i = 0; i < in.length(); i++)
		{
			for (int j = i + 1; j < in.length(); j++)
			{
				if (in[j] > maximum) {
					maximum = in[j];
					i = j;
				}
			}
			out += maximum;
			maximum = in[i + 1];
		}
		cout << out << endl;
	}
	//system("pause");
	return 0;
}
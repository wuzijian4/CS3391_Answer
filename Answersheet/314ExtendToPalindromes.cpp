#include <iostream> 
#include <string>   
#include <algorithm>
#include <memory.h>
using namespace std;

string in; string out;
int nextPos[100005];

void getNext() {
	//构建next list 当出现不匹配的情况时， 指针的走向
	memset(nextPos, 0, sizeof(nextPos));
	nextPos[0] = -1;
	int i = 0; int j = -1;
	while (i < out.length() - 1)
	{
		if (j == -1 || out[i] == out[j])
		{
			i++; j++;
			nextPos[i] = out[i] == out[j] ? nextPos[j] : j;
		}
		else
			j = nextPos[j];
	}
}

int kmp() {
	int i = 0; int j = 0;

	while ((i < (int)in.length()) && (j < (int)out.length()))
	{
		if (j == -1 || in[i] == out[j]) {
			i++;
			j++;
		}
		else {
			j = nextPos[j];
		}
	}
	return j;
}


int main() {
	while (getline(cin, in))
	{
		out.assign(in.begin(), in.end());
		reverse(out.begin(), out.end());
		getNext();
		int j = kmp();
		string right = out.substr(j, out.length());
		in += right;
		cout << in << endl;
	}
	return 0;
}
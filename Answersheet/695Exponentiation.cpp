#include <iostream>
#include <string>
#include <math.h>
#include <memory.h>

using namespace std;
#define N 10000

char R[N], ans[N], tmp[N];
void multiple() {
	int a[N], b[N], c[N];
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	memset(c, 0, sizeof(c));

	int R_length = strlen(R);
	int tmp_length = strlen(tmp);

	// reverse the original string and convert to the 
	for (int i = 0; i < R_length; i++)
		a[i] = R[R_length - i - 1] - 48;
	for (int i = 0; i < tmp_length; i++)
		b[i] = tmp[tmp_length - 1 - i] - 48;

	// b is longer than a, we put it at the outer loop
	for (int i = 0; i < tmp_length; i++)
	{
		for (int j = 0; j < R_length; j++)
		{
			c[i + j] += b[i] * a[j];
		}
	}

	// deal with the carry bit
	int len = R_length + tmp_length + 1;

	for (int i = 0; i < len; i++)
	{
		if (c[i] > 9) {
			c[i + 1] += c[i] / 10;
			c[i] %= 10;
		}
	}

	memset(ans, 0, sizeof(ans));
	for (; len >= 0; len--) {
		// remove the leading zero
		if (c[len] != 0) {
			for (int j = 0; j <= len; j++)
			{
				ans[j] = c[len - j] + '0';
			}
			break;
		}
	}
	ans[len + 1] = '\0';
}


int main() {
	int n;
	while (cin >> R >> n)
	{
		int len = strlen(R);
		len--;
		while (len >= 0 && R[len] == '0')
			R[len--] = '\0';

		int decimalPoint = 0;

		for (int i = len; i >= 0; i--)
		{
			if (R[i] == '.') {
				for (int j = i; j < len; j++)
					R[j] = R[j + 1];
				R[len] = '\0';
				break;
			}
			decimalPoint++;
		}

		strcpy(ans, R);

		for (int i = 1; i < n; i++)
		{
			strcpy(tmp, ans);
			multiple();
		}


		// deal with the decimal point and leading zero
		decimalPoint *= n;
		int anslen = strlen(ans);

		// decimal point is longer than the len of answer
		// means that the original R is less than 1.
		if (anslen < decimalPoint)
		{
			string leading;
			leading += ".";
			for (int i = 0; i < decimalPoint - anslen; i++)
				leading += "0";
			cout << leading << ans << endl;
		}
		else
		{
			for (int i = 0; i < anslen - decimalPoint; i++)
				cout << ans[i];
			if (ans[anslen - decimalPoint])
				cout << "." << &ans[anslen - decimalPoint];
			cout << endl;
		}

	}
	return 0;
}
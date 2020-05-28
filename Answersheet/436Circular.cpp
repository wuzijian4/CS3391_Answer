#include <iostream>
#include <memory.h>
#include <algorithm>
#include <math.h>
using namespace std;

#define N 1000000
int prime[1000009];
int circular[1000009];


void checkPrime() {
	for (int i = 0; i <= 1000000; i++)
		prime[i] = 1;
	prime[1] = 0; prime[0] = 0;

	for (int i = 2; i <= sqrt(N); i++)
	{
		if (prime[i] == 1) {
			for (int j = i; j*i <= N; j++)
				prime[j*i] = 0;
		}
	}
}

void checkCircular() {
	memset(circular, 0, sizeof(circular));

	for (int i = 100; i <= 1000000; i++)
	{
		if (prime[i] == 1) {
			// 只有i是质数， 才会检查他的circular。
			if (circular[i] == 1) {
				continue;
			}
			// 已经检查过是circular，不用重复检查

			int digit = 1;
			int tmp = i;
			bool isCircular = true;
			int tmp2 = i;

			while (tmp /= 10)
				digit++;

			int *store = new int[digit + 2];
			int index = 0;
			for (int j = 1; j <= digit; j++)
			{
				int lastDigit = tmp2 % 10;
				tmp2 /= 10;
				tmp2 += (lastDigit*pow(10, digit - 1));

				store[index++] = tmp2;

				if (prime[tmp2] == 0) {
					isCircular = false;
					break;
				}
			}

			if (isCircular) {
				circular[i] = 1;
				for (int k = 0; k < digit; k++) {
					circular[store[k]] = 1;
				}
			}
			delete store;
		}
	}
}

int main() {
	checkPrime();
	checkCircular();
	do
	{

		int in1, in2;
		cin >> in1;
		if (in1 == -1)
			break;
		cin >> in2;

		int count = 0;
		for (int i = in1; i <= in2; i++) {
			//if (circular[i] == 1)
				//cout << i << endl;
			count += circular[i];
		}

		if (count == 0)
			cout << "No Circular Primes." << endl;
		else {
			if (count == 1)
				cout << count << " Circular Prime." << endl;
			else
			{

				cout << count << " Circular Primes." << endl;
			}
		}

	} while (true);
	//system("pause");
	return 0;
}
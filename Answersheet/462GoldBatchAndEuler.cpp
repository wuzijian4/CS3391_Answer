#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;


bool isPrime(int n) {
	if (n < 4)
		return true;
	if ((n & 1) == 0)
		return false; // even number

	if (n % 6 != 1 && n % 6 != 5)
		return false;

	int i = (int)sqrt((double)n);
	for (int j = 5; j <= i; j += 6)
	{
		if (n%j == 0 || n % (j + 2) == 0)
			return false;
	}

	return true;
}

int main() {
	int num;
	while (scanf("%d", &num) != EOF)
	{
		if (num < 5)
			cout << num << " is not the sum of two primes!" << endl;
		else if ((num & 1) != 0) {
			// an odd number must be the sum of 2 and a prime number
			if (isPrime(num - 2))
				cout << num << " is the sum of " << 2 << " and " << num - 2 << "." << endl;
			else
				cout << num << " is not the sum of two primes!" << endl;
		}
		else { // even number
			int n = num / 2; bool notFound = true;
			// prime number starts from 2;
			int i;
			for (i = n - 1; i >= 2; i--) {
				if (isPrime(i) && isPrime(num - i)) {
					notFound = false;
					break;
				}
			}
			if (notFound)
				cout << num << " is not the sum of two primes!" << endl;
			else
				cout << num << " is the sum of " << i << " and " << num - i << "." << endl;
		}
	}
	return 0;
}
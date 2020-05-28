#include <iostream>
using namespace std;

//move n-1 disks from left to right through middle
//move last disk to middle
//move n-1 disks from right to left through middle
// move last disk to right
// move n-1 disks from left to right through middle

void movement(int& count) {
	count++;
}


void drive(int n, int& count) {
	if (n == 1)
	{
		movement(count);
		movement(count);
	}
	else
	{
		drive(n - 1, count);
		movement(count);
		drive(n - 1, count);
		movement(count);
		drive(n - 1, count);
	}

}

int main() {
	int numOfDisks;
	int count;

	while (cin >> numOfDisks)
	{
		if (numOfDisks == EOF)
			break;
		count = 0;
		drive(numOfDisks, count);
		cout << count << endl;
	}

	return 0;
}
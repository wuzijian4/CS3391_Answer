#include <iostream>
#include <iomanip>
using namespace std;

#define numRows 8
#define numCols 8
int row; int column;
int counter; int colIndex[8] = {};
int used[numRows] = {};

bool isSafe(int row, int col)
{
	bool safe = true;
	//row has been checked , check the diagonal
	for (int i = col - 1; i >= 0 && safe; i--)
	{
		int j = row + col - i;
		if (j < numRows && colIndex[i] == j)
			safe = false; // check upper diagonal

		j = row - (col - i);
		if (j >= 0 && colIndex[i] == j)// check lower diagonal
			safe = false;
	}
	return safe;
}

void eightQueen(int col) {
	if (col == 8 && colIndex[column - 1] == row - 1)
	{
		counter++; cout << setw(2) << counter << "     ";
		for (int i = 0; i < numCols; i++)
			cout << " " << colIndex[i] + 1;
		cout << endl;
	}
	else
	{
		for (int i = 0; i < numRows; i++)
		{
			// check whether this row has been used or not
			// chaeck whether this position is safe
			if (used[i] == 0 && isSafe(i, col))
			{
				used[i] = 1;
				colIndex[col] = i;
				eightQueen(col + 1);
				used[i] = 0;
			}
		}
	}
	return;
}

int main() {
	int cases;
	cin >> cases;
	while (cases > 0)
	{
		counter = 0;
		cin >> row >> column;
		cout << "SOLN       COLUMN" << endl;
		cout << " #      1 2 3 4 5 6 7 8" << endl << endl;
		eightQueen(0);  // iterate from column 1, index 0 
		// if row column is in the solution, print it out
		cases--;
		if (cases) {
			cout <<endl;
		}
			
	}

	return 0;
}

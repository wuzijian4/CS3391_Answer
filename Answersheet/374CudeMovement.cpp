#include <iostream>
#include <string>
using namespace std;


int main() {
	string Top, Bottom, North, South, East, West;
	string t[7];
	string tmp;
	int flag = 0;
	while (cin >> tmp)
	{
		t[0] = tmp;
		for (int j = 1; j < 7; j++)
			cin >> t[j];
		if (cin.peek() == '\n') {
			cin.ignore();
			if (cin.peek() == EOF)
				flag = 1;
		}
		//最后一组

		string rotate = t[6];
		Top = t[0]; Bottom = t[1]; North = t[2];
		South = t[3]; East = t[4]; West = t[5];

		string t, b, n, s, e, w;
		for (int i = 0; i < rotate.length(); i++) {
			if (rotate[i] == 'F') {
				t = South; b = North; n = Top;
				s = Bottom; e = East; w = West;

				Top = t; Bottom = b; North = n;
				South = s; East = e; West = w;
			}
			else if (rotate[i] == 'L') {
				t = East; b = West; n = North;
				s = South; e = Bottom; w = Top;

				Top = t; Bottom = b; North = n;
				South = s; East = e; West = w;
			}
			else if (rotate[i] == 'B') {
				t = North; b = South; n = Bottom;
				s = Top; e = East; w = West;

				Top = t; Bottom = b; North = n;
				South = s; East = e; West = w;
			}
			else if (rotate[i] == 'R') {
				t = West; b = East; n = North;
				s = South; e = Top; w = Bottom;

				Top = t; Bottom = b; North = n;
				South = s; East = e; West = w;
			}
		}
		cout << Top << endl;
		cout << Bottom << endl;
		cout << North << endl;
		cout << South << endl;
		cout << East << endl;
		cout << West << endl;
		if (flag == 0)
			cout << endl;
	}
	return 0;
}
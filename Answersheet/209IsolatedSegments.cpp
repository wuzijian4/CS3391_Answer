#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

struct coordinate
{
	long long x, y;
};

struct segment
{
	coordinate start, end;
};

long long cw(coordinate c1, coordinate c2, coordinate c3) {
	return ((c2.x - c1.x)*(c3.y - c1.y) - (c3.x - c1.x)*(c2.y - c1.y));
}


bool Online(coordinate c1, coordinate c2, coordinate c3) {
	if ((min(c1.x, c2.x) <= c3.x && max(c1.x, c2.x) >= c3.x)
		&& (min(c1.y, c2.y) <= c3.y && max(c1.y, c2.y) >= c3.y)) {
		return true;
	}
	else
		return false;
}

bool intersect(segment s1, segment s2) {
	long long d1, d2, d3, d4;
	d1 = cw(s1.start, s1.end, s2.end);
	d2 = cw(s1.start, s1.end, s2.start);
	d3 = cw(s2.start, s2.end, s1.start);
	d4 = cw(s2.start, s2.end, s1.end);
	if (d1 * d2 < 0 && d3 * d4 < 0)
		return true;

	if (d1 == 0 && Online(s1.start, s1.end, s2.end))
		return true;
	else if (d2 == 0 && Online(s1.start, s1.end, s2.start))
		return true;
	else if (d3 == 0 && Online(s2.start, s2.end, s1.start))
		return true;
	else if (d4 == 0 && Online(s2.start, s2.end, s1.end))
		return true;
	return false;
}

int main() {

	int n;
	cin >> n;
	while (n--)
	{
		int m;
		cin >> m;

		segment* segs = new segment[m + 2];
		for (int i = 1; i <= m; i++)
			cin >> segs[i].start.x >> segs[i].start.y >> segs[i].end.x >> segs[i].end.y;

		int num = 0; bool intersected;
		for (int i = 1; i <= m; i++)
		{
			intersected = false;
			for (int j = 1; j <= m; j++)
			{
				if (i != j && intersect(segs[i], segs[j]))
				{
					intersected = true;
					break;
				}
			}
			if (!intersected)
				num++;
		}
		cout << num << endl;
		delete segs;
	}

	//	system("pause");
	return 0;
}
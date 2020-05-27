#include <iostream>
#include <algorithm>

using namespace std;

struct coordinate
{
	double x, y;
};

struct segment
{
	coordinate start, end;
};

struct rectangular
{
	coordinate topLeft, topRight, bottomLeft, bottomRight;
};


bool within(coordinate c, rectangular r) {
	if (c.x <= r.topRight.x && c.x >= r.topLeft.x
		&& c.y <= r.topLeft.y && c.y >= r.bottomLeft.y)
	{
		return true;
	}
	return false;
}

bool Online(coordinate c1, coordinate c2, coordinate c3) {
	if ((min(c1.x, c2.x) <= c3.x && max(c1.x, c2.x) >= c3.x)
		&& (min(c1.y, c2.y) <= c3.y && max(c1.y, c2.y) >= c3.y)) {
		return true;
	}
	else
		return false;
}

double cw(coordinate c1, coordinate c2, coordinate c3) {
	return ((c2.x - c1.x)*(c3.y - c1.y) - (c3.x - c1.x)*(c2.y - c1.y));
}

bool intersect(segment s1, segment s2) {
	double d1, d2, d3, d4;
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

bool isIntersect(segment s, rectangular r) {
	segment* seg = new segment[5];
	seg[0].start = r.topLeft;	seg[0].end = r.topRight;
	seg[1].start = r.topLeft;   seg[1].end = r.bottomLeft;
	seg[2].start = r.topRight;  seg[2].end = r.bottomRight;
	seg[3].start = r.bottomLeft; seg[3].end = r.bottomRight;

	//cout << "this" << endl;
	if (within(s.start, r) || within(s.end, r))
		return true;
	for (int i = 0; i < 4; i++)
	{
		if (intersect(seg[i], s))
			return true;
	}

	return false;
}

int main() {
	int n;
	cin >> n;
	while (n--)
	{
		segment s;
		int xstart, ystart, xend, yend, xleft, ytop, xright, ybottom;
		cin >> xstart >> ystart >> xend >> yend >> xleft >> ytop >> xright >> ybottom;
		s.start.x = xstart;  s.start.y = ystart;
		s.end.x = xend;		 s.end.y = yend;

		rectangular rec;
		rec.topLeft.x = min(xleft, xright);       rec.topLeft.y = max(ytop, ybottom);
		rec.bottomRight.x = max(xright, xleft);  rec.bottomRight.y = min(ybottom, ytop);
		rec.bottomLeft.x = min(xleft, xright);    rec.bottomLeft.y = min(ybottom, ytop);
		rec.topRight.x = max(xright, xleft);	 rec.topRight.y = max(ytop, ybottom);


		if (isIntersect(s, rec)) {
			cout << "T" << endl;
		}
		else
		{
			cout << "F" << endl;
		}

	}
	//system("pause");
	return 0;
}
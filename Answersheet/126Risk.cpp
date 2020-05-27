#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>
#include <iomanip>
#include <algorithm>

using namespace std;

struct circle
{
	int x, y, r;
}c[300];



int main() {
	int n;
	do
	{
		cin >> n;
		if (n == 0)
			break;
		for (int i = 1; i <= n; i++)
			cin >> c[i].x >> c[i].y >> c[i].r;
		double max = 0;

		for (double i = 0; i <= 360; i += 0.25)
		{
			double u = 500 * cos(i*M_PI / 180);
			double v = 500 * sin(i*M_PI / 180);
			double total = 0;
			for (int j = 1; j <= n; j++)
			{
				double length = (u*c[j].x + v * c[j].y) / (sqrt(pow(u, 2) + pow(v, 2)));
				if (length > 0) {
					// cos(theta) must larger than 0, theta cannot be larger than 90 degree
					double perpendicular = pow(c[j].x, 2) + pow(c[j].y, 2) - pow(length, 2);
					if (perpendicular < pow(c[j].r, 2)) {
						// have intersections
						double newLength = 2 * sqrt(pow(c[j].r, 2) - perpendicular);
						total += newLength;
					}
				}
			}
			if (total > max)
				max = total;
		}
		cout << setprecision(3) << fixed << max << endl;
	} while (true);
	return 0;
}
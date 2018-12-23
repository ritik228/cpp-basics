#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	const double kEps = 1e-15;

	double a, b, c, x1, x2, dx;
	cout << "Enter a: ";
	cin >> a;
	cout << "Enter b: ";
	cin >> b;
	cout << "Enter c: ";
	cin >> c;
	cout << "Enter x1: ";
	cin >> x1;
	cout << "Enter x2: ";
	cin >> x2;
	cout << "Enter dx: ";
	cin >> dx;

	if (dx >= kEps)
	{
		cout << endl << string(37, '-') << endl;
		cout << "|" << setw(9) << "x" << setw(9);
		cout << "|" << setw(9) << "f" << setw(9) << "|";
		cout << endl << string(37, '-') << endl;

		cout << fixed;
		cout.precision(3);

		double f, x = x1;
		while (x <= x2)
		{
			cout << "|" << setw(11) << x << setw(7) << "|";

			if ((c < 0) && (abs(b) >= kEps))
			{
				f = a * pow(x, 2) + pow(b, 2) * x;
			}
			else
			{
				if ((c > 0) && (abs(b) < kEps))
				{
					if (abs(x + c) >= kEps)
					{
						f = (x + a) / (x + c);
					}
					else
					{
						cout << "  division by 0  |\n";
						x += dx;
						continue;
					}
				}
				else
				{
					if (abs(c) >= kEps)
					{
						f = x / c;
					}
					else
					{
						cout << "  division by 0  |\n";
						x += dx;
						continue;
					}
				}
			}

			if (((int(a) & int(b)) | (int(a) & int(c))) != 0)
				cout << setw(11) << f << setw(7);
			else
				cout << setw(9) << int(f) << setw(9);
			cout << "|" << endl;

			x += dx;
		}
		cout << string(37, '-') << endl;
	}
	else
		cout << "\nError dx!\n";

	return 0;
}
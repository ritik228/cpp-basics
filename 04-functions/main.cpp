#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

void PrintTableHead()
{
	cout << string(67, '-') << endl;
	cout << "|" << setw(9) << "x" << setw(9);
	cout << "|" << setw(15) << "ln(1-x) cmath" << setw(3);
	cout << "|" << setw(15) << "ln(1-x) mine" << setw(3);
	cout << "|" << setw(6) << "n" << setw(7) << "|\n";
	cout << string(67, '-') << endl;
}

double ComputeSeries(double x, double eps, int &n, const int kMaxIters)
{
	double ln = 0;
	for (n = 1; n < kMaxIters; n++)
	{
		double nth_term = -pow(x, n) / n;
		ln += nth_term;

		if (abs(nth_term) < eps) break;
	}
	return ln;
}


void PrintResult(double x, double ln, int n, const int kMaxIters)
{
	cout << "|" << setw(13) << x << setw(5) << "|";
	cout << setw(13) << log(1 - x) << setw(5) << "|";
	if (n == kMaxIters)
	{
		cout << setw(15) << "excess limit" << setw(3) << "|";
		cout << setw(7) << " " << setw(6) << "|\n";
	}
	else
	{
		cout << setw(13) << ln << setw(5) << "|";
		cout << setw(7) << n << setw(6) << "|\n";
	}
}

int main()
{
	int kMaxIters = 1000000;

	double x1, x2, dx, eps;
	cout << "ln(1-x), -1 <= x < 1\n";
check:
	cout << "Enter x1, x2, dx, eps:\n";
	cin >> x1 >> x2 >> dx >> eps;
	if (dx <= 0 || eps <= 0 || x1 < -1 || x1 > x2 || x2 >= 1)
	{
		cout << "\nInput error.\n" << endl;
		goto check;
	}

	PrintTableHead();

	cout << fixed;
	cout.precision(6);

	double x = x1;
	while (x <= x2)
	{
		int n;
		double ln = ComputeSeries(x, eps, n, kMaxIters);
		PrintResult(x, ln, n, kMaxIters);
		x += dx;
	}
	cout << string(67, '-');

	return 0;
}
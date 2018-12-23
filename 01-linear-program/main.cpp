#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double a;
	cout << "Enter a number: ";
	cin >> a;

	double z1 = cos(a) + cos(2 * a) + cos(6 * a) + cos(7 * a);
	double z2 = 4 * cos(a / 2) * cos(5 * a / 2) * cos(4 * a);

	cout << "\nz1 = " << z1 << "\nz2 = " << z2 << endl;

	return 0;
}
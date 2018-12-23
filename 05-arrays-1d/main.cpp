#include <iostream>

using namespace std;

int main()
{
	const int kArraySize = 8;
	double arr[kArraySize] = { 0.2, 0.0, 4.2, -2.0, 0.0, 3.2, 0.0, -4.2 };

	cout << "Initial array:\n";
	for (int i = 0; i < kArraySize; i++)
		cout << arr[i] << " ";
	cout << endl;

	double arr_min = arr[0];
	for (int i = 1; i < kArraySize; i++)
		if (arr[i] < arr_min)
			arr_min = arr[i];
	cout << "\nMin = " << arr_min << endl;

	int first_positive = -1, last_positive = -1;
	for (int i = 0; i < kArraySize; i++)
		if (arr[i] > 0)
		{
			first_positive = i;
			break;
		}
	for (int i = kArraySize - 1; i >= 0; i--)
		if (arr[i] > 0)
		{
			last_positive = i;
			break;
		}

	if ((first_positive > -1) && (first_positive < last_positive))
	{
		double sum = 0.0;
		for (int i = first_positive + 1; i < last_positive; i++)
			sum += arr[i];

		cout << "\nSum = " << sum << endl;
	}
	else
	{
		cout << "\nNo two positive elements were found.\n";
	}

	for (int i = 0; i < kArraySize - 1; i++)
		for (int j = 0; j < kArraySize - i - 1; j++)
			if (arr[j] != 0 && arr[j + 1] == 0)
				swap(arr[j], arr[j + 1]);

	cout << "\nNew array:\n";
	for (int i = 0; i < kArraySize; i++)
		cout << arr[i] << " ";
	cout << endl;

	return 0;
}
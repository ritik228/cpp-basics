#include "functions.h"

int main()
{
	const int kArraySize = 8;
	double arr[kArraySize] = { 0.2, 0.0, 4.2, -2.0, 0.0, 3.2, 0.0, -4.2 };

	cout << "Initial array:\n";
	PrintArray(arr, kArraySize);

	cout << "\nMin = " << FindMin(arr, kArraySize) << endl;

	Positives positives = FindPositives(arr, kArraySize);
	if ((positives.first > -1) && (positives.first < positives.last))
		cout << "\nSum = " << GetSum(arr, positives) << endl;
	else
		cout << "\nNo two positive elements were found.\n";

	cout << "\nNew array:\n";
	SortArray(arr, kArraySize);
	PrintArray(arr, kArraySize);

	return 0;
}
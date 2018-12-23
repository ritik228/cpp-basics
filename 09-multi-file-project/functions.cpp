#include "functions.h"

void PrintArray(double* arr, const int kArraySize)
{
	for (int i = 0; i < kArraySize; i++)
		cout << arr[i] << " ";
	cout << endl;
}

double FindMin(double* arr, const int kArraySize)
{
	double arr_min = arr[0];
	for (int i = 1; i < kArraySize; i++)
		if (arr[i] < arr_min)
			arr_min = arr[i];
	return arr_min;
}

Positives FindPositives(double* arr, const int kArraySize)
{
	Positives positives = { -1, -1 };

	for (int i = 0; i < kArraySize; i++)
		if (arr[i] > 0)
		{
			positives.first = i;
			break;
		}

	for (int i = kArraySize - 1; i >= 0; i--)
		if (arr[i] > 0)
		{
			positives.last = i;
			break;
		}

	return positives;
}

double GetSum(double* arr, Positives positives)
{
	double sum = 0.0;
	for (int i = positives.first + 1; i < positives.last; i++)
		sum += arr[i];
	return sum;
}

void SortArray(double* arr, const int kArraySize)
{
	for (int i = 0; i < kArraySize - 1; i++)
		for (int j = 0; j < kArraySize - i - 1; j++)
			if (arr[j] != 0 && arr[j + 1] == 0)
				swap(arr[j], arr[j + 1]);
}
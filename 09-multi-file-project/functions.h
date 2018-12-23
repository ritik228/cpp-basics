#include <iostream>

using namespace std;

struct Positives
{
	int first;
	int last;
};

void PrintArray(double* arr, const int kArraySize);
double FindMin(double* arr, const int kArraySize);
Positives FindPositives(double* arr, const int kArraySize);
double GetSum(double* arr, Positives positives);
void SortArray(double* arr, const int kArraySize);
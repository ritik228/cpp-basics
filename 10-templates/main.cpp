#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

template <class T>
void ReadData(T** matrix, ifstream& fin, int num_rows, int num_cols);

template <class T>
void PrintMatrix(T** matrix, int num_rows, int num_cols);

template <class T>
T SumRow(T* row, int num_cols);

template <class T>
void FindSaddlePoints(T** matrix, bool** saddle_points,
	int num_rows, int num_cols);

template <class T>
int Execute(string file_name);

int main()
{
	string option;
selection:
	cout << "Select the data type (0 - integer, 1 - double, 2 - float): ";
	cin >> option;
	if (option == "0")
	{
		Execute<int>("integer.txt");
	}
	else if (option == "1")
	{
		Execute<double>("double.txt");
	}
	else if (option == "2")
	{
		Execute<float>("float.txt");
	}
	else
	{
		cout << "Wrong input!\n\n";
		goto selection;
	}

	return 0;
}

template <class T>
int Execute(string file_name)
{
	ifstream fin(file_name);
	if (!fin.is_open())
	{
		cout << "Can't open file: " << file_name << "!\n";
		return 1;
	}

	int num_rows, num_cols;
	fin >> num_rows;
	fin >> num_cols;

	T** matrix = new T*[num_rows];
	for (int i = 0; i < num_rows; i++)
		matrix[i] = new T[num_cols];
	ReadData(matrix, fin, num_rows, num_cols);

	cout << "Input data:\n";
	PrintMatrix(matrix, num_rows, num_cols);
	cout << endl;

	for (int i = 0; i < num_rows; i++)
		for (int j = 0; j < num_cols; j++)
			if (matrix[i][j] < 0)
			{
				cout << "#" << i << " row: sum = ";
				cout << SumRow(matrix[i], num_cols) << endl;
				break;
			}
	cout << endl;

	bool** saddle_points = new bool*[num_rows];
	for (int i = 0; i < num_rows; i++)
		saddle_points[i] = new bool[num_cols];

	FindSaddlePoints(matrix, saddle_points, num_rows, num_cols);
	for (int i = 0; i < num_rows; i++)
		for (int j = 0; j < num_cols; j++)
			if (saddle_points[i][j])
			{
				cout << "Saddle point: ";
				cout << matrix[i][j] << " [" << i << "]" << "[" << j << "]\n";
			}

	for (int i = 0; i < num_rows; i++) delete[] matrix[i];
	delete[] matrix;

	for (int i = 0; i < num_rows; i++) delete[] saddle_points[i];
	delete[] saddle_points;

	return 0;
}

template <class T>
void ReadData(T** matrix, ifstream& fin, int num_rows, int num_cols)
{
	for (int i = 0; i < num_rows; i++)
	{
		for (int j = 0; j < num_cols; j++)
		{
			fin >> matrix[i][j];
		}
	}

	fin.close();
}

template <class T>
void PrintMatrix(T** matrix, int num_rows, int num_cols)
{
	streamsize print_precision = cout.precision();
	cout.precision(3);

	for (int i = 0; i < num_rows; i++)
	{
		for (int j = 0; j < num_cols; j++)
		{
			cout << "|" << setw(6) << matrix[i][j] << setw(4);
		}
		cout << "|" << endl;
	}

	cout.precision(print_precision);
}

template <class T>
T SumRow(T* row, int num_cols)
{
	T sum = 0;
	for (int j = 0; j < num_cols; j++)
		sum += row[j];
	return sum;
}

template <class T>
void FindSaddlePoints(T** matrix, bool** saddle_points,
	int num_rows, int num_cols)
{
	for (int i = 0; i < num_rows; i++)
		for (int j = 0; j < num_cols; j++)
			saddle_points[i][j] = 0;

	for (int i = 0; i < num_rows; i++)
	{
		// Find min in i-th row.
		T row_min = matrix[i][0];
		int row_min_i = i;
		int row_min_j = 0;
		for (int j = 1; j < num_cols; j++)
			if (matrix[i][j] < row_min)
			{
				row_min = matrix[i][j];
				row_min_i = i;
				row_min_j = j;
			}

		// Find max in row_min_j-th column.
		T col_max = row_min;
		int col_max_i = row_min_i;
	check:
		for (int k = 0; k < num_rows; k++)
			if (matrix[k][row_min_j] > col_max)
			{
				col_max = matrix[k][row_min_j];
				col_max_i = k;
			}

		// If saddle point.
		if (row_min_i == col_max_i)
			saddle_points[row_min_i][row_min_j] = 1;

		// If there are more mins in the current row.
		for (int j = row_min_j + 1; j < num_cols; j++)
			if (matrix[row_min_i][j] == row_min)
			{
				row_min_j = j;
				goto check;
			}
	}
}
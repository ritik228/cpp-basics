#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void ReadData(int** matrix, ifstream& fin, int num_rows, int num_cols);
void PrintMatrix(int** matrix, int num_rows, int num_cols);
int SumRow(int* row, int num_cols);
void FindSaddlePoints(int** matrix, bool** saddle_points,
	int num_rows, int num_cols);

int main()
{
	ifstream fin("matrix.txt");
	if (!fin.is_open())
	{
		cout << "Can't open file: matrix.txt!\n";
		return 1;
	}

	int num_rows, num_cols;
	fin >> num_rows;
	fin >> num_cols;

	int** matrix = new int*[num_rows];
	for (int i = 0; i < num_rows; i++)
		matrix[i] = new int[num_cols];
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

void ReadData(int** matrix, ifstream& fin, int num_rows, int num_cols)
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

void PrintMatrix(int** matrix, int num_rows, int num_cols)
{
	for (int i = 0; i < num_rows; i++)
	{
		for (int j = 0; j < num_cols; j++)
		{
			cout << "|" << setw(4) << matrix[i][j] << setw(4);
		}
		cout << "|" << endl;
	}
}

int SumRow(int* row, int num_cols)
{
	int sum = 0;
	for (int j = 0; j < num_cols; j++)
		sum += row[j];
	return sum;
}

void FindSaddlePoints(int** matrix, bool** saddle_points,
	int num_rows, int num_cols)
{
	for (int i = 0; i < num_rows; i++)
		for (int j = 0; j < num_cols; j++)
			saddle_points[i][j] = 0;

	for (int i = 0; i < num_rows; i++)
	{
		// Find min in i-th row.
		int row_min = matrix[i][0];
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
		int col_max = row_min;
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
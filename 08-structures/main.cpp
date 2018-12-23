#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>

using namespace std;

struct Worker
{
	string name, position;
	int employment_year;
};

void InputData(Worker* workers, const int kNumWorkers);
void SortWorkers(Worker* workers, const int kNumWorkers);
void PrintWorkers(Worker* workers, const int kNumWorkers);
int GetCurrentYear();
void FindExperiencedPeople(Worker* workers, const int kNumWorkers);

int main()
{
	const int kNumWorkers = 10;
	Worker workers[kNumWorkers];
	InputData(workers, kNumWorkers);

	SortWorkers(workers, kNumWorkers);
	PrintWorkers(workers, kNumWorkers);
	FindExperiencedPeople(workers, kNumWorkers);

	return 0;
}

void InputData(Worker* workers, const int kNumWorkers)
{
	for (int i = 0; i < kNumWorkers; i++)
	{
		cout << "Enter the name of the employee (e.g., Ivanov I.I.) ";
		cout << i + 1 << ": ";
		getline(cin, workers[i].name);
		cout << "Enter the job title of the employee (e.g., software developer) ";
		cout << workers[i].name << ": ";
		getline(cin, workers[i].position);
		cout << "Enter the year of employment (e.g., 2015): ";
		cin >> workers[i].employment_year;
		cout << endl;
		cin.get();
	}
}

void SortWorkers(Worker * workers, const int kNumWorkers)
{
	for (int i = 0; i < kNumWorkers - 1; i++)
		for (int j = 0; j < kNumWorkers - i - 1; j++)
			if (workers[j].name.compare(workers[j + 1].name) > 0)
				swap(workers[j], workers[j + 1]);
}

void PrintWorkers(Worker* workers, const int kNumWorkers)
{
	cout << "Name-position-Year\n";
	for (int i = 0; i < kNumWorkers; i++)
	{
		cout << workers[i].name << " - ";
		cout << workers[i].position << " - ";
		cout << workers[i].employment_year << "\n";
	}
	cout << endl;
}

int GetCurrentYear()
{
	struct tm buf;
	time_t t = time(NULL);
	localtime_s(&buf, &t);
	return buf.tm_year + 1900;
}

void FindExperiencedPeople(Worker* workers, const int kNumWorkers)
{
	int experience;
	cout << "Enter the work experience (e.g., 5): ";
	cin >> experience;

	cout << "Works more than " << experience << " years: " << endl;
	bool no_experienced_people = true;
	for (int i = 0; i < kNumWorkers; i++)
	{
		if ((GetCurrentYear() - workers[i].employment_year) > experience)
		{
			cout << workers[i].name << endl;
			no_experienced_people = false;
		}
	}
	if (no_experienced_people)
		cout << "No employees were found.\n";
}
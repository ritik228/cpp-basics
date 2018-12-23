#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream fin("text.txt");
	if (!fin.is_open())
	{
		cout << "Can't open file: text.txt!\n";
		return 1;
	}

	bool no_commas = true;
	string line, sentence = "";
	while (getline(fin, line)) // read the next line from the file
	{
		for (size_t i = 0; i < line.length(); i++) // for the current line
		{
			sentence += line[i];

			if (line[i] == ',')
				no_commas = false;

			if (line[i] == '.' || line[i] == '!' || line[i] == '?')
			{
				if (no_commas) // print the sentence without commas
				{
					// don't print ' ' character before the sentence
					if (sentence[0] == ' ')
						sentence = sentence.substr(1, sentence.length());

					cout << sentence << endl;
				}

				// prepare for the next sentence
				sentence = "";
				no_commas = true;
			}
		}

		// if a sentence is written on more than one line
		if (sentence != "")
			sentence += " ";
	}

	return 0;
}
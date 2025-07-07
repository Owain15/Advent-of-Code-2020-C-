
#include <iostream>

#include <string>
#include <array>
#include <vector>
#include <deque>
#include <fstream>

#include "Aoc2020.H"

using namespace std;

int D1::RunPartOne(void)
{
	//ifstream file("D1-Test.txt");
	ifstream file("D1-Data.txt");

	deque<string> data;

	string line;
	while( file >> line )
	{
		data.push_back(line);
	}

	file.close();
	
	//  print Title
	//cout << "TestData\n\n" << endl;
	cout << "Data\n\n" << endl;

	// print data
	for (int i = 0; i < data.size(); i++)
	{
		cout << data[i] << endl;
	}

	cout << "\n" << endl;

	vector<int> numericData;

	for (int i = 0; i < data.size(); i++)
	{
		numericData.push_back(std::stoi(data[i]));
	}

	bool dataCheck = false;
	int a;
	int b;

	for (int i = 0; i < numericData.size(); i++)
	{
		for (int j = 0; j < numericData.size(); j++)
		{
			if (i != j && numericData[i] + numericData[j] == 2020)
			{
				a = i;
				b = j;

				dataCheck = true;
			}

			if (dataCheck) { break; }
		}

		if (dataCheck) { break; }
	}

	// data not found. return error
	if (!dataCheck) { return 1; }

	cout << data[a] << " + " << data[b] << " = " << numericData[a] + numericData[b] << endl;

	cout << "Result\n" << numericData[a] * numericData[b] << endl;


	return 0;
}

int D1::RunPartTwo(void)
{
	vector<int> data;

	//ifstream file("D1-Test.txt");
	ifstream file("D1-Data.txt");

	std::string line;

	while (file >> line)
	{
		data.push_back(std::stoi(line));
	}

	file.close();
	
	bool dataFound = false;

	int a;
	int b;
	int c;

	for(int A = 0; A < data.size(); A++)
	{
		for (int B = 0; B < data.size(); B++)
		{
			for (int C = 0; C < data.size(); C++)
			{
				if (A != B != C && data[A] + data[B] + data[C] == 2020)
				{
					dataFound = true;

					a = data[A];
					b = data[B];
					c = data[C];

					
				}
				
				if (dataFound) { break; }
			}

			if (dataFound) { break; }
		}

		if (dataFound) { break; }
	}

	// data not found, return error.
	if(!dataFound)
	{
		return 1;
	}

	cout << "Day 1 (part 2)\n\nResult\n " << a * b * c << endl;






	

	return 0;
}


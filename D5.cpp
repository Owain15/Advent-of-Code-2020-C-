
#include <iostream>

#include <string>
#include <deque>
#include <fstream>

#include <algorithm>

#include "Aoc2020.H"

using namespace std;

int D5::RunPartOne(void)
{
	cout << "Day 5 (Part 1)\n" << endl;

	//ifstream file("D5-Test.txt");
	ifstream file("D5-Data.txt");

	string line;
	deque<int> idList;

	while (file >> line)
	{
	//split raw data
		string rowData = line.substr(0,7);
		string columnData = line.substr(7,3);
		
	//convert rowdata to binary
		for (int i = 0; i < rowData.length(); i++)
		{
			if(rowData[i] == 'F')
			{rowData[i] = '0'; }
			else { rowData[i] = '1'; }
		}

	//convert columndata to binary
		for (int i = 0;i < columnData.length(); i++)
		{
			if(columnData[i] == 'R')
			{columnData[i] = '1'; }
			else { columnData[i] = '0'; }
		}

	//convert binery data to int
		int row = stoi(rowData, nullptr, 2);
		int column = stoi(columnData, nullptr, 2);
		
	//caluculate seatId and store

		idList.push_back(row * 8 + column);
	}

	cout << "Result " << *(max_element(idList.begin(), idList.end())) << endl;

	return 0;
}

int D5::RunPartTwo(void)
{
	cout << "Day 5 (Part 2)" << endl;

	ifstream file("D5-Data.txt");

	string line;
	deque<int> idList;

	while (file >> line)
	{
		//split raw data
		string rowData = line.substr(0, 7);
		string columnData = line.substr(7, 3);

		//convert rowdata to binary
		for (int i = 0; i < rowData.length(); i++)
		{
			if (rowData[i] == 'F')
			{
				rowData[i] = '0';
			}
			else { rowData[i] = '1'; }
		}

		//convert columndata to binary
		for (int i = 0;i < columnData.length(); i++)
		{
			if (columnData[i] == 'R')
			{
				columnData[i] = '1';
			}
			else { columnData[i] = '0'; }
		}

		//convert binery data to int
		int row = stoi(rowData, nullptr, 2);
		int column = stoi(columnData, nullptr, 2);

		//caluculate seatId and store

		idList.push_back(row * 8 + column);
	}

	sort(idList.begin(), idList.end());
	
	deque<int> myId;

	for (int i = 1; i < idList.size() - 1; i ++)
	{
		if(idList[i] + 2 == idList[i+1])
		{
			myId.push_back(idList[i] + 1);
		}
	}

	if (myId.size() == 1)
	{
		cout << "Result " << myId[0] << endl;
	}
	else
	{
		cout << "Result  not found" << endl;
	}


	return 0;
}


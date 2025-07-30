
#include "Aoc2020.h"

#include <iostream>

#include <string>
#include <array>
#include <vector>
//#include <deque>
#include <fstream>

using namespace std;

int D3::RunPartOne(void)
{
	cout << "Day 3 . Part One\n" << endl;

	ifstream file("D3-Test.txt");
	//ifstream file("D3-Data.txt");

	vector<string> fileData;

	for (string line; getline(file, line); )
	{
		fileData.push_back(line);
	}

	file.close();

	const int xRule = 3;
	const int yRule = 1;

	int x = 0;
	int y = 0;

	int result = 0;

	int gX = fileData[0].size();
	int gY = fileData.size();

	while (y < fileData.size())
	{
		x += xRule;
		if (x > fileData[0].size()) 
		{
			x = x - fileData[0].size();
		}
		
		y += yRule;
		if (y > fileData.size()-1)
		{ 
			break;
		}

		if( fileData[y][x] == '#')
		{                               
			result++; // 264 = wrong answer  // 1,3,4,5,7,10,11,12,13,14,16,17,19,20,21,22,23 
		}                                    // 25,27,28,29,30,32,33,35,36,37,38,40
	}

	cout << "Result\n" << result << endl;

	return 0;
}

int D3::RunPartOne_Two(void)
{
	cout << "Day 3 . Part One\n" << endl;

	//ifstream file("D3-Test.txt");
	ifstream file("D3-Data.txt");

	vector<string> fileData;

	for (string line; getline(file, line); )
	{
		fileData.push_back(line);
	}

	file.close();

	int x = 0;
	int count = 0;

	for (int i = 0; i < fileData.size(); i++)
	{
		if (fileData[i][x] == '#')
		{
			count ++ ;
		}

		x += 3;

		if (x > fileData[i].size())
		{
			x = x - fileData[i].size();
		}

	}

	cout << "result\n" << count << endl;

	return 0;
}

int D3::RunPartTwo(void)
{
	return 0;
}
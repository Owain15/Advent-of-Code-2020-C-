#include "Aoc2020.h"

#include <iostream>

#include <string>
//#include <array>
//#include <vector>
#include <deque>
#include <fstream>

using namespace std;

int D6::RunPartOne(void)
{
	cout << "Day 6 . Part One\n" << endl;

	//string inputSource = "D6-Test.txt";
	string inputSource = "D6-Data.txt";

	auto groupData = GetGroupDataFromFile(inputSource);
	groupData = RemoveDupicutArnsersFromGoup(groupData);

	int result = 0;

	for(auto group : groupData)
	{
		result += group.length();
	}

	cout << "Result\n" << result << endl;

	return 0;
}

int D6::RunPartTwo(void)
{
	cout << "Day 6 . Part Two\n" << endl;

	//ifstream file("D6-Test.txt");
	ifstream file("D6-Data.txt");

	deque<deque<string>> groupData;

	deque<string> group;
	string person;

	while (!file.eof())
	{
		getline(file, person);

		if (person == "")
		{
			groupData.push_back(group);
			group.clear();
		}
		else
		{
			group.push_back(person);
		}
	}

	groupData.push_back(group);

	deque<int> groupResults;

	for (auto group : groupData)
	{
		string ansers;

		int count = 0;

		for (auto person : group)
		{
			for (auto question : person)
			{
				if(ansers.find(question) == string::npos)
				{
					ansers += question;
				}
			}
		}

		for (auto question : ansers)
		{
			bool isInclusiveAnser = true;

			for (auto person : group)
			{
				if(person.find(question) == string::npos)
				{
					isInclusiveAnser = false;
					break;
				}
			}

			if (isInclusiveAnser)
			{
				count++;
			}

		}

		groupResults.push_back(count);

	}

	int result = 0;

	for (auto group : groupResults)
	{
		result += group;
	}


	cout << "Result\n" << result << endl;

	return 0;
}

deque<string> D6::GetGroupDataFromFile(string fileLocation)
{
	deque<string> groupData;

	ifstream file(fileLocation);

	string group;
	string line;

	while (!file.eof())
	{
		getline(file, line);

		if(line == "")
		{
			groupData.push_back(group);
			group.clear();
		}
		else
		{
			group += line;
		}
	}

	groupData.push_back(group);
	group.clear();

	return groupData;
}

deque<string> D6::RemoveDupicutArnsersFromGoup(std::deque<std::string> groupData)
{
	deque<string> returnData;

	for (auto group : groupData)
	{
		string newData = "";

		for (auto anser : group)
		{
			if (newData.find(anser) == std::string::npos)
			{
				newData.push_back(anser);
			}
		}

		returnData.push_back(newData);

	};

	return returnData;
}

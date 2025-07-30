
#include <iostream>

#include <string>
//#include <array>
//#include <vector>
#include <deque>
#include <fstream>

#include "Aoc2020.H"

using namespace std;
using namespace D7;

//struct ElfBag
//{
//	string Colour;
//
//	deque<string> Contents;
//};

int D7::RunPartOne(void)
{
	string fileLocation = "D7-Test.txt";
	//string fileLocation = "D7-Data.txt";

	deque<ElfBag> bagRules = UnpackFileData(fileLocation);

	int result = 0;

	for (auto rule : bagRules)
	{
		//bool bagFound = false;

		for (auto bag : rule.Contents)
		{
			if(bag == "shiny gold")
			{
				result++;
				break;
			}
		}
		
	}

	cout << "Day 7 (part 1)\n\nResult\n" << result << endl;

	return 0;
}

int D7::RunPartTwo(void)
{

	//ifstream file("D7-Test.txt");
	ifstream file("D7-Data.txt");


	cout << "Day 7 (part 2)\n\nResult\n " << endl;

	return 0;
}

deque<ElfBag> D7::UnpackFileData(std::string fileLocation)
{
	ifstream file(fileLocation);

	deque<ElfBag> returnData;

	string line;
	
	//light red bags contain 1 bright white bag, 2 muted yellow bags.
	
	while (!file.eof())
	{
		
		getline(file,line);

		string lineColour = line.substr(0, line.find(" bags"));

		for (auto bags : returnData)
		{
			if(bags.Colour == lineColour)
			{
				break;
			}
		}
		
		ElfBag bag;
		
		bag.Colour = lineColour;

		bool allDataFound = false;

		while (!allDataFound)
		{
			//light red bags contain 1 bright white bag, 2 muted yellow bags.

			if (line.find("contain") != string::npos)
			{
				line = line.substr(line.find("contain") + 8);
			}
		
			//1 bright white bag, 2 muted yellow bags.

			if(isdigit(line[0]))
			{
				string bagCount = line.substr(0, line.find(" "));
				
				string bagColour = line.substr(bagCount.length()+1,line.find("bag")-3);

				for (int i = 0; i < std::stoi(bagCount); i++)
				{
					bag.Contents.push_back(bagColour);
				} 

			}
			else
			{
				allDataFound = true;
				break;
			}

			if (line.find(",") != string::npos)
			{
				line = line.substr(line.find(",") + 2);
			}
			else
			{
				allDataFound = true;
				break;
			}
			

		}
		
		
		returnData.push_back(bag);


	}
	
	file.close();

	return returnData;
}






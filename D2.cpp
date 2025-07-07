
#include <iostream>

#include <string>
#include <vector>
#include <fstream>

#include "Aoc2020.H"

namespace D2
{
	struct DataStruct
	{
		int min;
		int max;
	
		char rule;
		std::string password;
	};

	int D2::RunPartOne(void)
	{
			
		std::cout << "Day 2 . Part One\n" << std::endl;

		//std::ifstream file("D2-Test.txt");
		std::ifstream file("D2-Data.txt");

		std::vector<DataStruct> data;

		for (std::string line; std::getline(file, line); )
		{
			DataStruct lineData;


			lineData.min = std::stoi(line.substr(0, line.find('-')));
			lineData.max = std::stoi(line.substr(line.find('-')+1,(line.find(' ') - line.find('-'))));
			lineData.rule = line[line.substr(0,line.find(':')).size()-1];
			lineData.password = line.substr(line.find(':')+2, line.size());

			data.push_back(lineData);
		}

		file.close();

		int result = 0;

		for (int i = 0; i < data.size(); i++)
		{
			int kCount = 0;

			for (int j = 0; j < data[i].password.size(); j++)
			{
				if(data[i].password[j] == data[i].rule)
				{
					kCount++;
				}
			}

			if(kCount >= data[i].min && kCount <= data[i].max)
			{
				result++;
			}

		}

		std::cout << "Result\n" << result << std::endl;

		return 0;
	}

	int D2::RunPartTwo(void)
	{

		std::cout << "Day 2 . Part Two\n" << std::endl;

		//std::ifstream file("D2-Test.txt");
		std::ifstream file("D2-Data.txt");

		std::vector<DataStruct> data;

		for (std::string line; std::getline(file, line); )
		{
			DataStruct lineData;

			lineData.min = std::stoi(line.substr(0, line.find('-')));
			lineData.max = std::stoi(line.substr(line.find('-') + 1, (line.find(' ') - line.find('-'))));
			lineData.rule = line[line.substr(0, line.find(':')).size() - 1];
			lineData.password = line.substr(line.find(':') + 2, line.size());

			data.push_back(lineData);
		}

		file.close();

		int result = 0;

		for (int i = 0; i < data.size(); i++)
		{
			char d1 = data[i].password[data[i].min-1];
			char d2 = data[i].password[data[i].max-1];

			bool a = d1 == data[i].rule;
			bool b = d2 == data[i].rule;
			
			if (a != b )
			{
				
				 result++; 
			}
		}


		std::cout << "Result\n" << result << std::endl;
		
		return 0;
	}


}
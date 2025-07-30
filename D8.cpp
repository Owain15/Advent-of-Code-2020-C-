
#include <iostream>

#include <string>
#include <deque>
#include <fstream>

#include "Aoc2020.H"

using namespace std;

enum class LineCommand
{
	acc,
	jmp,
	nop,
	NotFound
};

struct CommandData
{
	LineCommand Command;
	int Value;
	bool hasBeenRun;
};

int D8::RunPartOne()
{
	deque<CommandData> commandList;

	//ifstream file("D8-Test.txt");
	ifstream file("D8-Data.txt");

	while (!file.eof())
	{
		CommandData newData;

		string line;

		getline(file, line);

		string newCommand = line.substr(0, 3);
		
		if (newCommand == "acc")
		{ 
			newData.Command = LineCommand::acc; 
		}
		else if (newCommand == "jmp")
		{
			newData.Command = LineCommand::jmp;
		}
		else if (newCommand == "nop")
		{
			newData.Command = LineCommand::nop;
		}
		else
		{
			newData.Command = LineCommand::NotFound;
		}
		
		newData.Value = std::stoi(line.substr(line.find(" ") + 1));
		newData.hasBeenRun = false;

		commandList.push_back(newData);

	}

	file.close();

	int result = 0;
	bool loopFound = false;

	int accumulator = 0;
	int lineIndex = 0;

	while (!loopFound)
	{
		if(commandList[lineIndex].hasBeenRun)
		{
			result = accumulator;
			loopFound = true;
			break;
		}

		commandList[lineIndex].hasBeenRun = true;
		
		switch (commandList[lineIndex].Command)
		{
			case LineCommand::acc :
			{ 
				accumulator += commandList[lineIndex].Value;
				lineIndex++;
				break;
			}

			case LineCommand::jmp:
			{
				lineIndex += commandList[lineIndex].Value;
				break;
			}

			case LineCommand::nop:
			{
				lineIndex++;
				break;
			}

			case LineCommand::NotFound:
			{
				std::cout << "Processing Error" << endl;
				loopFound = true;
				break;
			}
		}

	}

	

	std::cout << "Day 8 , part 1\nResult " << result << endl;

	return 0;
}

int D8::RunPartTwo()
{
	deque<CommandData> commandList;

	//ifstream file("D8-Test.txt");
	ifstream file("D8-Data.txt");

	while (!file.eof())
	{
		CommandData newData;

		string line;

		getline(file, line);

		string newCommand = line.substr(0, 3);

		if (newCommand == "acc")
		{
			newData.Command = LineCommand::acc;
		}
		else if (newCommand == "jmp")
		{
			newData.Command = LineCommand::jmp;
		}
		else if (newCommand == "nop")
		{
			newData.Command = LineCommand::nop;
		}
		else
		{
			newData.Command = LineCommand::NotFound;
		}

		newData.Value = std::stoi(line.substr(line.find(" ") + 1));
		newData.hasBeenRun = false;

		commandList.push_back(newData);

	}

	file.close();

	int result = 0;
	
	bool endFound = false;

	
	int endIndex = commandList.size();
	

	for (int i = 0; i < commandList.size(); i++)
	{
		deque<CommandData> testData = commandList;
		
		bool loopFound = false;
		int accumulator = 0;
		int lineIndex = 0;
		
		if(testData[i].Command == LineCommand::jmp || testData[i].Command == LineCommand::nop)
		{
			if(testData[i].Command == LineCommand::jmp)
			{testData[i].Command = LineCommand::nop; }
			else{ testData[i].Command = LineCommand::jmp; }

			while(!loopFound)
			{
				if(testData[lineIndex].hasBeenRun)
				{
					loopFound = true;
					break;
				}

				testData[lineIndex].hasBeenRun = true;

				switch (testData[lineIndex].Command)
				{
				case LineCommand::acc:
				{
					accumulator += commandList[lineIndex].Value;
					lineIndex++;
					break;
				}

				case LineCommand::jmp:
				{
					lineIndex += commandList[lineIndex].Value;
					break;
				}

				case LineCommand::nop:
				{
					lineIndex++;
					break;
				}

				case LineCommand::NotFound:
				{
					cout << "Processing Error" << endl;
					loopFound = true;
					break;
				}
				}

				if (lineIndex == endIndex)
				{
					endFound = true;
					result = accumulator;
					break;
				}

			}

		}
	}

	std::cout << "Day 8 , part 2\nResult " << result << endl;

	return 0;
}

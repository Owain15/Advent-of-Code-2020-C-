
#include <iostream>

#include <string>
#include <deque>


#pragma once

namespace D1
{
	int RunPartOne(void);
	int RunPartTwo(void);
}

namespace D2
{
	int RunPartOne(void);
	int RunPartTwo(void);
}

namespace D3
{
	int RunPartOne(void);
	int RunPartOne_Two(void);
	int RunPartTwo(void);
}

namespace D4
{
	int RunPartOne(void);
	int RunPartTwo(void);
}

namespace D5
{
	int RunPartOne(void);
	int RunPartTwo(void);
}

namespace D6
{
	int RunPartOne(void);
	int RunPartTwo(void);

	std::deque<std::string> GetGroupDataFromFile(std::string fileLocation);
	std::deque<std::string> RemoveDupicutArnsersFromGoup(std::deque<std::string> groupData);
}

namespace D7
{
	struct ElfBag
	{
		std::string Colour;

		std::deque<std::string> Contents;
	};

	int RunPartOne(void);
	int RunPartTwo(void);

	std::deque<D7::ElfBag> UnpackFileData(std::string fileLocation);
}

namespace D8
{
	int RunPartOne(void);
	int RunPartTwo(void);
}

namespace D9
{
	int RunPartOne(void);
	int RunPartTwo(void);
}

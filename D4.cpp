

#include <iostream>

#include <string>
#include <deque>
#include <fstream>

#include "Aoc2020.H"

using namespace std;

//byr(Birth Year)
//iyr(Issue Year)
//eyr(Expiration Year)
//hgt(Height)
//hcl(Hair Color)
//ecl(Eye Color)
//pid(Passport ID)
//cid(Country ID)

struct Passport
{
	string BirthYear = "";
	string IssueYear = "";
	string ExpirationYear = "";
	string Height = "";
	string HairColor = "";
	string EyeColor = "";
	string PassportId = "";
	string CountryId = "";
};

int D4::RunPartOne(void)
{
	cout << "Day 4 . Part One\n" << endl;

	//ifstream file("D4-Test.txt");
	ifstream file("D4-Data.txt");

	deque<string> fileData;
	string line;
	string newLine;

	while (!file.eof())
	{
		getline(file, newLine);
		
		if (newLine == "")
		{
			fileData.push_back(line);
			line.clear();
		}
		else
		{
			line += newLine + " ";
		}
		
	}

	fileData.push_back(line);

	file.close();

	deque<Passport> passportData;
	//string data;

	for (auto person : fileData)
	{
		Passport p;


		if (person.find("byr:") != std::string::npos)
		{
			int start = person.find("byr:")+4;
			int length = (person.find(" ", start)) - start;
			string data = person.substr(start,length);
			p.BirthYear = data;
		}
		
		if (person.find("iyr:") != std::string::npos)
		{
			int start = person.find("iyr:") + 4;
			int length = (person.find(" ", start)) - start;
			string data = person.substr(start, length);
			p.IssueYear = data;
		}

		if (person.find("eyr:") != std::string::npos)
		{
			int start = person.find("eyr:") + 4;
			int length = (person.find(" ", start)) - start;
			string data = person.substr(start, length);
			p.ExpirationYear = data;
		}

		if (person.find("hgt:") != std::string::npos)
		{
			int start = (person.find("hgt:") + 4);
			int length = ((person.find("cm", start)) - start);
			string data = person.substr((person.find("hgt:") + 4), length);
			p.Height = data;
		}
		
		if (person.find("hcl:") != std::string::npos)
		{
			int start = person.find("hcl:") + 4;
			int length = (person.find(" ", start)) - start;
			string data = person.substr(start, length);
			p.HairColor = data;
		}
		
		if (person.find("ecl:") != std::string::npos)
		{
			int start = person.find("ecl:") + 4;
			int length = (person.find(" ", start)) - start;
			string data = person.substr(start, length);
			p.EyeColor = data;
		}
		
		if (person.find("pid:") != std::string::npos)
		{
			int start = person.find("pid:") + 4;
			int length = (person.find(" ", start)) - start;
			string data = person.substr(start, length);
			p.PassportId = data;
		}
		
		if (person.find("cid:") != std::string::npos)
		{
			int start = person.find("cid:") + 4;
			int length = (person.find(" ", start)) - start;
			string data = person.substr(start, length);
			p.CountryId = data;
		}


		passportData.push_back(p);
	
	}

	int result = 0;

	for (auto passport : passportData)
	{
		if (
			passport.BirthYear != "" &&
			passport.ExpirationYear != ""&&
			passport.EyeColor != ""&&
			passport.HairColor != ""&&
			passport.Height != ""&&
			passport.IssueYear != ""&&
			passport.PassportId != ""
		   )
		{
			result++;
		}
	}

	cout << "Valid input count = " << result << endl;

	return 0;
}

int D4::RunPartTwo(void)
{
	cout << "Day 4 . Part Two\n" << endl;

	//ifstream file("D4-Test.txt");
	ifstream file("D4-Data.txt");

	deque<string> rawStringData;
	string line;
	string newLine;

	while (!file.eof())
	{
		getline(file, newLine);

		if (newLine == "")
		{
			rawStringData.push_back(line);
			line.clear();
		}
		else
		{
			line += newLine + " ";
		}

	}

	rawStringData.push_back(line);

	file.close();

	deque<Passport> passportData;

	for (auto person : rawStringData)
	{

		Passport p;


		if (person.find("byr:") != std::string::npos)
		{
			int start = person.find("byr:") + 4;
			int length = (person.find(" ", start)) - start;
			string data = person.substr(start, length);
			
			if (std::stoi(data) >= 1920 && std::stoi(data) <= 2002)
			{
				p.BirthYear = data;
			}
		}

		if (person.find("iyr:") != std::string::npos)
		{
			int start = person.find("iyr:") + 4;
			int length = (person.find(" ", start)) - start;
			string data = person.substr(start, length);
			
			if (std::stoi(data) >= 2010 && std::stoi(data) <= 2020)
			{ 
				p.IssueYear = data;
			}
		}

		if (person.find("eyr:") != std::string::npos)
		{
			int start = person.find("eyr:") + 4;
			int length = (person.find(" ", start)) - start;
			string data = person.substr(start, length);

			if (std::stoi(data) >= 2020 && std::stoi(data) <= 2030)
			{
				p.ExpirationYear = data;
			}
		}

		if (person.find("hgt:") != std::string::npos)
		{
			int start = (person.find("hgt:") + 4);
			int length = ((person.find(" ", start)) - start);

			string data = person.substr((person.find("hgt:") + 4), length);

			if(data.find("cm") != string::npos || data.find("in") != string::npos)
			{
				string unit;

				if (data.find("cm") != string::npos)
				{
					unit = "cm";
				
				}
				else
				{
					unit = "in";
				}

				data = data.substr(0, data.find(unit));
			
				if(unit == "cm" && std::stoi(data) >= 150 && std::stoi(data) <= 193 || unit == "in" && std::stoi(data) >= 59 && std::stoi(data) <= 76)
				{ 
					p.Height = data;
				}

				
			}


		}

		if (person.find("hcl:") != std::string::npos)
		{
			int start = person.find("hcl:") + 4;
			int length = (person.find(" ", start)) - start;
			string data = person.substr(start, length);
			
			if(data[0] == '#')
			{	
				data = data.substr(1);
			
				if(data.length() == 6)
				{
					bool isValid = true;

					for (auto c : data)
					{
						if(!isxdigit(c))
						{
							isValid = false;
							break;
						}
					}

					if(isValid)
					{ p.HairColor = data; }
				}

			}
	
		}

		if (person.find("ecl:") != std::string::npos)
		{
			int start = person.find("ecl:") + 4;
			int length = (person.find(" ", start)) - start;
			string data = person.substr(start, length);
			
			if(data == "amb" || data == "blu" || data == "brn" || data == "gry" || data == "grn" || data == "hzl" || data == "oth")
			{ 
				p.EyeColor = data;
			}

			
		}

		if (person.find("pid:") != std::string::npos)
		{
			int start = person.find("pid:") + 4;
			int length = (person.find(" ", start)) - start;
			string data = person.substr(start, length);

			if(data.length() == 9)
			{
				bool isValid = true;

				for (auto c : data)
				{
					if(!isdigit(c))
					{
						isValid = false;
						break;
					}
				}

				if (isValid)
				{
					p.PassportId = data;
				}
			}

	
		}

		if (person.find("cid:") != std::string::npos)
		{
			int start = person.find("cid:") + 4;
			int length = (person.find(" ", start)) - start;
			string data = person.substr(start, length);
			p.CountryId = data;
		}


		passportData.push_back(p);

	}

	int result = 0;

	for (auto passport : passportData)
	{
		if (
			passport.BirthYear != "" &&
			passport.ExpirationYear != "" &&
			passport.EyeColor != "" &&
			passport.HairColor != "" &&
			passport.Height != "" &&
			passport.IssueYear != "" &&
			passport.PassportId != ""
			)
		{
			result++;
		}
	}

	cout << "Valid input count = " << result << endl;


	return 0;
}
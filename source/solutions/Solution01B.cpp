#include "Solutions.h"
#include "../../packages/utilities/Utilities.h"

namespace Solutions01B
{
	void PrintSolution(const std::filesystem::path &inputFile)
	{
		int result = 0;
		std::vector<int> calibrationValues;

		for (const std::string &line : Utilities::file_into_string_vector(inputFile))
		{
			std::vector<char> digitVector;
			std::string str = "";
			for (char character : line)
			{
				if (isdigit(character))
				{
					digitVector.push_back(character);
					str = character;
				}
				else
				{
					str += character;
				}

				if (str.find("one") != std::string::npos)
				{
					digitVector.push_back('1');
					str = character;
				}
				if (str.find("two") != std::string::npos)
				{
					digitVector.push_back('2');
					str = character;
				}
				if (str.find("three") != std::string::npos)
				{
					digitVector.push_back('3');
					str = character;
				}
				if (str.find("four") != std::string::npos)
				{
					digitVector.push_back('4');
					str = character;
				}
				if (str.find("five") != std::string::npos)
				{
					digitVector.push_back('5');
					str = character;
				}
				if (str.find("six") != std::string::npos)
				{
					digitVector.push_back('6');
					str = character;
				}
				if (str.find("seven") != std::string::npos)
				{
					digitVector.push_back('7');
					str = character;
				}
				if (str.find("eight") != std::string::npos)
				{
					digitVector.push_back('8');
					str = character;
				}
				if (str.find("nine") != std::string::npos)
				{
					digitVector.push_back('9');
					str = character;
				}
			}

			char firstNumber = digitVector[0];
			char lastNumber = digitVector[digitVector.size() - 1];
			digitVector = {};

			std::string value;
			value += firstNumber;
			value += lastNumber;

			calibrationValues.push_back(stoi(value));
		}

		for (int i : calibrationValues)
		{
			result += i;
		}

		std::cout << "\t\t" << GREEN_TEXT << "\t\t" << result << std::endl;
	}
} // namespace Solutions01B

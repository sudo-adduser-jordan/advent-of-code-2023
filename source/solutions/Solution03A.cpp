#include "Solutions.h"
#include "../../packages/utilities/Utilities.h"

namespace Solutions03A
{
	static bool isNumber(const char c)
	{
		return c >= 48 and c <= 57;
	}

	static bool isSymbol(const char c)
	{
		return !isNumber(c) and c != '.';
	}

	static void SumParts(int *sum, const std::vector<std::string> &vec, const auto lines, const auto lineLen)
	{
		for (int row = 0; row < lines; row++)
		{
			int index = 0;
			int number = 0;
			bool isPart = false;

			while (index < lineLen)
			{
				char character = vec[row][index];

				if (!isNumber(character))
				{
					if (isPart)
					{
						*sum += number;
					}
					number = 0;
					isPart = false;
				}

				if (isNumber(character))
				{
					number *= 10;
					number += character - '0'; // concat char to int

					if (index < lineLen - 1)
					{
						isPart = isPart or isSymbol(vec[row][index + 1]);
					}

					if (index > 0)
					{
						isPart = isPart or isSymbol(vec[row][index - 1]);
					}

					if (row < lines - 1)
					{
						isPart = isPart or isSymbol(vec[row + 1][index]);
					}

					if (row < lines - 1 and index > 0)
					{
						isPart = isPart or isSymbol(vec[row + 1][index - 1]);
					}

					if (row < lines - 1 and index < lineLen - 1)
					{
						isPart = isPart or isSymbol(vec[row + 1][index + 1]);
					}

					if (row > 0)
					{
						isPart = isPart or isSymbol(vec[row - 1][index]);
					}

					if (row > 0 and index > 0)
					{
						isPart = isPart or isSymbol(vec[row - 1][index - 1]);
					}

					if (row > 0 and index < lineLen - 1)
					{
						isPart = isPart or isSymbol(vec[row - 1][index + 1]);
					}
				}
				index++;
			}
			if (isPart)
			{
				*sum += number;
			}
		}
	}

	void PrintSolution(const std::filesystem::path &inputFile)
	{
		auto input = Utilities::file_into_string_vector(inputFile);
		int sum = 0;
		auto lines = input.size();
		auto lineLen = input[0].size();
		SumParts(&sum, input, lines, lineLen);

		std::cout << "\t\t" << GREEN_TEXT << "\t\t" << sum << std::endl;
	}
} // namespace Solutions03A

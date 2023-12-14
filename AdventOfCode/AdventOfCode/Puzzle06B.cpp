#include "pch.h"

#include "../Utilities/Utilities.h"
#include "Colors.h"
#include "PuzzleSolvers.h"

using namespace Utilities;

namespace Puzzle06B
{
	using ulint = unsigned long long int;

	struct Race
	{
		ulint time = 0;
		ulint record = 0;
		ulint wins = 0;
	};

	void PrintSolution(const std::filesystem::path& inputFile, bool shouldRender)
	{
		// Sample input.
		// Time: 71530
		// Distance:  940200
		// Race race = { 71530, 940200 };

		Race race = { 48938595, 296192812361391 };

		for (int index = 0; index <= race.time; index++)
		{
			if (race.record < ((race.time - index) * index))
			{
				race.wins++;
			}
		}

		std::cout << "\t\t" << GREEN_TEXT << race.wins << RESET_COLOR;
	}
} // namespace Puzzle06B
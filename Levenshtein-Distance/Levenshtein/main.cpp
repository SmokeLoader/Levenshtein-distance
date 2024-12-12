#include "main.h"

int main()
{
	std::string str1 = "levenshtein";
	std::string str2 = "evenshtein";

	int distance = Levenshtein::computeDistance(str1, str2);

	printf("Levenshtein Distance: %i\n", distance);

	return 0;
}

void Levenshtein::initializeTable(const std::string& str1, const std::string& str2, std::vector<std::vector<int>>& dp)
{
	dp.resize(str1.size() + 1, std::vector<int>(str2.size() + 1));

	for (size_t i = 0; i <= str1.size(); ++i)
	{
		dp[i][0] = i;
	}

	for (size_t j = 0; j <= str2.size(); ++j)
	{
		dp[0][j] = j;
	}
}

int Levenshtein::computeDistance(const std::string& str1, const std::string& str2)
{
	std::vector<std::vector<int>> dp;
	initializeTable(str1, str2, dp);

	for (size_t i = 1; i <= str1.size(); ++i)
	{
		for (size_t j = 1; j <= str2.size(); ++j)
		{
			int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;

			dp[i][j] = std::min(
				{
					dp[i - 1][j] + 1,
					dp[i][j - 1] + 1,
					dp[i - 1][j - 1] + cost
				});
		}
	}
	return dp[str1.size()][str2.size()];
}
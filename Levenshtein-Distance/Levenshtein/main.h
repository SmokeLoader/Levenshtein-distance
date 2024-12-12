#ifndef MAIN_H
#define MAIN_H

#include <string>
#include <vector>
#include <iostream>

class Levenshtein
{
public:
    static int computeDistance(const std::string& str1, const std::string& str2);

private:
    static void initializeTable(const std::string& str1, const std::string& str2, std::vector<std::vector<int>>& dp);
};

#endif // MAIN_H

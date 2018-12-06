#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

pair<bool, bool> ProcessString(string str);

int main()
{
    string fileName = "input.txt";
    ifstream file(fileName);
    string line;

    int numberOfTwo = 0, numberOfThree = 0;

    while (std::getline(file, line))
    {
        auto result = ProcessString(line);

        cout << result.first << " | " << result.second << "\n";

        numberOfTwo = result.first ? numberOfTwo + 1 : numberOfTwo;
        numberOfThree = result.second ? numberOfThree + 1 : numberOfThree;
    }

    cout << numberOfTwo << " * " << numberOfThree << " = " << numberOfTwo * numberOfThree;
    cin.get();
}

// returns a pair that indicates if the string has a char that repeats twice and a char that repeats 3 times
pair<bool, bool> ProcessString(string str)
{
    unordered_map<char, int> charCount;
    bool hasTwoRepeating = false;
    bool hasThreeRepeating = false;

    for (int i = 0; i < str.size(); i++)
    {
        auto chr = str[i];
        auto result = charCount.insert({chr, 1}); // try to add the char the hashmap as a new entry.

        if (!result.second) // if insersion failed
        {
            auto currentAmount = charCount[chr];

            charCount[chr] = currentAmount + 1; // forget adding a new char, just increase the count of the existing one
        }
    }

    for (auto elem : charCount)
    {
        if (hasThreeRepeating && hasTwoRepeating)
            break;

        if (elem.second == 3)
        {
            hasThreeRepeating = true;
            continue;
        }

        if (elem.second == 2)
        {
            hasTwoRepeating = true;
            continue;
        }
    }

    return pair<bool, bool>(hasTwoRepeating, hasThreeRepeating);
}
#include <iostream>
#include <stdlib.h> 
#include <fstream>
#include <sstream> 
#include <string>
#include <unordered_set>

using namespace std;

int lookForRecurringFrequecy(ifstream& file, unordered_set<int>& frequeciesEncountered, int frequency) {
   string line;

   while(std::getline(file, line)) 
   {
      int num = 0;
      num = stoi(line);

      frequency += num;
      auto result = frequeciesEncountered.insert(frequency);

      
      if (result.second != 1) {
         cout << "First duplicate found: " << frequency << "\n";
         return -1;
      }
      
      cout << frequency << "\n";
   }

   file.clear();
   file.seekg(0, std::ios::beg);

   return frequency;
}

int main() {
   string fileName = "input.txt";

   ifstream file(fileName);
   string line;
   int frequency = 0;
   unordered_set<int> frequeciesEncountered;

   frequeciesEncountered.insert(0);
   
   int count = 0;

   while(frequency > -1)
   {
      count++;
      frequency = lookForRecurringFrequecy(file, frequeciesEncountered, frequency);
      
      cout << "iteration: " << count << "\n";
   }

   cin.get();
   return 0;
}

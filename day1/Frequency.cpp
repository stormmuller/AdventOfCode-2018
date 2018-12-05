#include <iostream>
#include <stdlib.h> 
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main() {

   ifstream file("input.txt");
   string line;
   int total = 0;

   while(std::getline(file, line)) 
   {
      int num = 0;
      num = stoi(line);

      total += num;

      cout << total << "\n";
   }

   cin.get();
   return 0;
}
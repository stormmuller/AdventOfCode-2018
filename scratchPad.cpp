#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>

using namespace std;

int main() 
{
    unordered_set<int> test;

    auto x = test.insert(1);
    cout << x.second;

    x = test.insert(2);
    cout << x.second;
    
    x = test.insert(2);
    cout << x.second;

    cin.get();
}
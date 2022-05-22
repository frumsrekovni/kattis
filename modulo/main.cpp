#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int inputNum(0);
    vector<int> moduloResults;
    while(cin >> inputNum){
        moduloResults.push_back(inputNum%42);
    }
    sort(moduloResults.begin(), moduloResults.end());
    moduloResults.erase(unique(moduloResults.begin(), moduloResults.end()), moduloResults.end());
    cout << moduloResults.size();
    return 0;
}
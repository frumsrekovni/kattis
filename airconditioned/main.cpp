#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int total_minions = 0;
    int min_temp = 0;
    int max_temp = 0;
    int min_tot_rooms = 0;
    vector<pair<int,int>> minion_preferred_temperatures;

    cin >> total_minions;
    for (int i = 0; i < total_minions; i++)
    {
        cin >> min_temp >> max_temp;
        minion_preferred_temperatures.push_back(pair<int, int>(min_temp,max_temp));
    }
    // If they all get input in descending order i dont need to order the container
    // The max temp of the initial lowest temp should be the temp of the first room
    // and then just continuously squeeze in minions until a new room has to be created.
    // but later tests will not input it in this order so it has to be sorted.
    // what matters is that the upper limit of preferred temperatures are in descending order,
    // therefore with a lambda expression the minion vector is sorted
    sort(minion_preferred_temperatures.begin(),minion_preferred_temperatures.end(),
    [] (const pair<int,int> &x, const pair<int,int> &y) { return x.second < y.second; });
    
    int upper_limit = 0;
    for (int i = 0; i < minion_preferred_temperatures.size(); i++)
    {
        //Whenever the upper limit of allowed temperature is broken by another minions lower limit a new room is needed.
        if(minion_preferred_temperatures.at(i).first > upper_limit){
            upper_limit = minion_preferred_temperatures.at(i).second;
            min_tot_rooms++;
        }
    }
    
    cout << min_tot_rooms;
    
    return 0;
}
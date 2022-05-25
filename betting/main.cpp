#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int a(0);
    cin >> a; // This is the percentage of points bet on option 1
    cout << setprecision(11) << 100.0 / a <<"\n" << 100 / (100.0 - a);
    return 0;
}
#include <iostream>
using namespace std;
int main(){
    int MBPerMonth(0), monthsUse(0), MBTotLeft(0), monthlyUse(0);
    cin >> MBPerMonth >> monthsUse;
    for (int i = 0; i < monthsUse; i++)
    {
        cin >> monthlyUse;
        MBTotLeft += MBPerMonth - monthlyUse;
    }
    MBTotLeft += MBPerMonth;
    cout << MBTotLeft;
    return 0;
}
#include <iostream>
using namespace std;

/* It takes the same amount of time to print a printer as printing a statue wtf?
 Ok, well, then printing a printer is always the better option 
 as long as the amount of printers is not more than the 
 amount of statues that needs printing */ 
int main(){
    int totStatues(0), totPrinters(1), minDays(1);
    cin >> totStatues;
    while(totPrinters < totStatues){
        totPrinters += totPrinters;
        minDays++;
    }
    cout << minDays;
    return 0;
}
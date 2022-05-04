#include<iostream>
using namespace std;
// Gunnar throws 4 dice. A side on the dice can have a number between 1 to 100. Every dice has at least 4 sides.

// The input is always 4 ints per person
const int amount_of_inputs = 4;

int main(){
    int sumEmma = 0;
    int sumGunnar = 0;
    int input = 0;
    for(int i=0;i<amount_of_inputs;i++){
        cin >> input;
        sumGunnar += input;
    }
    for(int i=0;i<amount_of_inputs;i++){
        cin >> input;
        sumEmma += input;
    }
    if(sumEmma > sumGunnar){
        cout << "Emma" << endl;
    }
    else if(sumEmma < sumGunnar){
        cout << "Gunnar" << endl;
    }
    else{
        cout << "Tie" << endl;
    }
    return 0;
}

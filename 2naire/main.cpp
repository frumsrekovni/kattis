#include <iostream>
using namespace std;

int main(){
    int amount_of_questions = 0;
    float correct_prob = 0.0;
    float tot_prize = 1.0; // Player starts with a dollar
    do
    {
        cin >> amount_of_questions >> correct_prob;
        for (int i = 1; i < amount_of_questions; i++)
        {
            tot_prize *= 2;
            //caught myself halfway through that im literally just typing out pow() manually
            // Will keep it as is for posterity's sake
        }
        cout << tot_prize; // This is the total prize pool after inserted amount of questions

    } while ((amount_of_questions != 0) && (correct_prob != 0) );
    
    return 0;
}
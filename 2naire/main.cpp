#include <iostream>
using namespace std;

int main(){
    int amount_of_questions = 0;
    double correct_prob = 0.0;
    double current_tot_prize = 1.0; // Player starts with a dollar
    double potential_tot_prize = 1.0;

    do
    {
        cin >> amount_of_questions >> correct_prob;
        // This calcs the prize money for the question that he is on
        for (int i = 0; i < amount_of_questions; i++)
        {
            potential_tot_prize *= 2;
            //caught myself halfway through that im literally just typing out pow() manually
            // Will keep it as is for posterity's sake
        }
        current_tot_prize = potential_tot_prize/2;
        
        cout << "Current prize: "<< current_tot_prize<< endl; // This is the total prize pool after inserted amount of questions
        cout << "Potential prize: "<<potential_tot_prize << endl;
        
    } while ((amount_of_questions != 0) && (correct_prob != 0) );
    
    return 0;
}
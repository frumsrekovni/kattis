#include <iostream>
#include <string>
using namespace std;
// 3g 10g 10% 0g 0g
// FAT PROTEIN SUGAR STARCH ALCOHOL
// Each number could end with 'g', '%' or 'C'
// 1g 15% 20% 30% 1C
/*
    1g = 9C
    15% Protein
    20% Sugar
    30% Starch
    1C Alcohol
    So, 10C is 100-(15+20+30) = 35% of all calories
    Meaning, that 35/10 = 3,5 is how large of a % 1C is.
    9 * 3.5 = 31.5 rounded to 32
    Answer: 32% of Calories is from fat
*/
int main(){
    string input = "";
    int totCalories(0);
    while(getline(cin, input)){
        // Every new line is a food/test
        char a;
        int individualCalories(0);
        int step(0);
        for (int i = 0; i < input.length(); i++)
        {
            // Really should separate the whole input string into its individual 5 elements and after that do the conversions and calculations
            a = input.at(i);
            if(a == 'g')
            {

            }
            else
            {

            }

        }
    }
    return 0;
}
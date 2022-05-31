#include <iostream>
#include <string>
#include <sstream>
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
    string inputline = "";
    int totCalories(0);
    int fatPercentage = 0;
    while(getline(cin, inputline)){
        if(inputline != "-"){
            // Every new line is a food/test
            int individualValue(0);
            istringstream ss(inputline);
            string nutrition = "";
            char unit;
            int percentageLeft = 0;
            for (int i = 0; i < 5; i++)
            {
                ss >> nutrition;
                unit = nutrition.back();
                nutrition.pop_back();
                individualValue = stoi(nutrition);
                if(unit == 'g'){
                    if(i == 0){ // Fat
                        individualValue *= 9;
                    }
                    else if(i > 0 && i < 4){ // Protein, sugar and starch
                        individualValue *= 4;
                    }
                    else if(i == 4){ // Alcohol
                        individualValue *= 7;
                    }
                    totCalories += individualValue;
                }
                else if(unit == '%'){
                    if(i == 0){
                        fatPercentage = individualValue;
                    }
                    else{
                        percentageLeft = individualValue;
                    }
                }
                else if(unit == 'C'){
                    totCalories += individualValue;
                }
            }
            // Here one food is done
            
        }
        else{
            cout << fatPercentage << "%\n";
        }
        
    }
    return 0;
}
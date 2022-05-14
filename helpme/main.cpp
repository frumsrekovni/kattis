#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    /*
    White player UPPERCASE. Black player lowercase.
    The chess board is 8x8. So a nested for loop sounds reasonable.
    */
    ifstream myfile ("1.in");
    string in;
    char firstchar;
    while(myfile >>firstchar){
        if(firstchar == '+'){ // "+" indicates that the entire line is useless
            getline(myfile, in);
            continue;
        }
        else{
            // If not "+" but in this case actually always the "|" char we have coming useful info

            for (int i = 0; i < 8; i++)
            {
                // i value here represent the 1 in "Ke1". aka what row the piece is in
                /* There are 8 squares */
                for (int y = 0; y < 4; y++)
                {
                    /* There are 4 chars per square */
                    char read_char;
                    myfile >> read_char;
                    if(isupper(read_char)){
                        cout << "This is a White piece";
                    }
                    else if(islower(read_char)){
                        cout << "This is a Black piece";
                    }
                    cout << read_char;
                }
                // A row has 2 lines of chars.
            }
        }
        cout <<endl;
    }
    
    
    // cout << "White: \n" << "Black: ";

    return 0;
}
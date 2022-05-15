#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main(){
    /*
    White player UPPERCASE. Black player lowercase.
    The chess board is 8x8. So a nested for loop sounds reasonable.
    */
    ifstream myfile ("1.in");
    string in;
    char firstchar;
    char columns[] = {'a','b','c','d','e','f','g','h'};
    vector<string> wPieces;
    vector<string> bPieces;
    while(myfile >>firstchar){
        if(firstchar == '+'){ // "+" indicates that the entire line is useless
            getline(myfile, in);
            continue;
        }
        else{
            // If not "+" but in this case actually always the "|" char we have coming useful info
            for (int u = 0; u < 8; u++)
            {
                // u value is the 1 in "Ke1". aka what row the piece is in
                for (int i = 0; i < 8; i++)
                {
                    // i value here represent the e in "Ke1". aka what column the piece is in
                    /* There are 8 squares */
                    for (int y = 0; y < 4; y++)
                    {
                        /* There are 4 chars per square */
                        char read_char;
                        int curr_row;
                        myfile >> read_char;
                        if(isupper(read_char)){
                            curr_row = abs(u - 8);
                            //cout << read_char << columns[i] << curr_row << endl;
                            string chesspiece = "";
                            
                            chesspiece = chesspiece + read_char + columns[i] + char(curr_row);
                            
                        }
                        else if(islower(read_char)){
                            curr_row = abs(u - 8);
                            read_char = toupper(read_char);
                            cout << read_char << columns[i] << curr_row << endl; 
                        }
                    }
                    // A row has 2 lines of chars.
                }
            }
        }
    }
    
    
    // cout << "White: \n" << "Black: ";

    return 0;
}
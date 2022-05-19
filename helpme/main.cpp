#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

bool chessPieceSort(string piece1, string piece2){
    // Print order: K > Q > R > B > N > P
    // If same type and white piece: smaller row > larger row
    // If same type and black piece: larger row > smaller row
    // If same type and same row smaller column > larger column
    // I cant directly compare lets say K to Q. Their char value doesnt line up with what should come first.
    // Need to have a tangible hierarchy of chars. Lets assign each char a value.
    map<char, int> char_hierarchy { {'K', 10}, {'Q', 9}, {'R', 5}, {'B', 3}, {'N', 2}}; // Bishop and knight actually has the same value
    
    //All pieces are represented with 3 chars, except for the pawns. Every non-pawn should be printed before.
    if(piece1.size() > piece2.size()){
        return true;
    }
    else if(piece1.size() < piece2.size()){
        return false; 
    }

    if(piece1.size() == 2){
        return piece1.at(1) < piece2.at(1);
    }
    
    return char_hierarchy.at(piece1.at(0)) > char_hierarchy.at(piece2.at(0));
    // cout << piece1.at(0);
    return true;
}
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
    int currentline = 1;
    int currentRow = 8;
    while(myfile >>firstchar){
        // if(currentline > 2){
        //     currentline = 1;
        //     currentRow--;
        // }
        // cout << currentRow;
        // if(firstchar == '+'){
        //     getline(myfile, in);
        // }
        // else if (firstchar == '|')
        // {
        //     getline(myfile, in);
        // }
        // currentline++;
        if(currentline > 2){
            currentline = 1;
            currentRow--;
        }
        if(firstchar == '+'){ // "+" indicates that the entire line is useless
            getline(myfile, in);
            currentline++;
        }
        else if(firstchar == '|'){
            // If not "+" but in this case actually always the "|" char we have coming useful info
            for (int i = 0; i < 8; i++)
            {
                // i value here represent the e in "Ke1". aka what column the piece is in
                /* There are 8 squares */
                for (int y = 0; y < 4; y++)
                {
                    /* There are 4 chars per square */
                    char read_char;
                    int curr_row;
                    int curr_col;
                    string chesspiece = "";
                    myfile >> read_char;
                    if(isupper(read_char)){
                        if(read_char == 'P'){
                            // In here it's a pawn. Meaning dont add the readchar to the chesspiece output
                            chesspiece = chesspiece + columns[i] + static_cast<char>('0'+currentRow);
                        }
                        else{
                            chesspiece = chesspiece + read_char + columns[i] + static_cast<char>('0'+currentRow);
                        }
                        wPieces.push_back(chesspiece);
                    }
                    else if(islower(read_char)){
                        cout << read_char << endl;
                        //read_char = toupper(read_char);
                        if(read_char == 'p'){
                            // In here it's a pawn. Meaning dont add the readchar to the chesspiece output
                            chesspiece = chesspiece + columns[i] + static_cast<char>('0'+currentRow);
                        }
                        else{
                            chesspiece = chesspiece + read_char + columns[i] + static_cast<char>('0'+currentRow);
                        }
                        bPieces.push_back(chesspiece);                        
                    }
                }
                // A row has 2 lines of chars.
            }
            currentline++;
        }
    }
    
    sort(wPieces.begin(),wPieces.end(), chessPieceSort);
     cout << "White: ";
     for (int i = 0; i < wPieces.size(); i++)
     {
         cout << wPieces.at(i) << ",";
     }
     sort(bPieces.begin(),bPieces.end(), chessPieceSort);
     cout << "\nBlack: ";
     for (int i = 0; i < bPieces.size(); i++)
     {
         cout << bPieces.at(i) << ",";
     }
    return 0;
}
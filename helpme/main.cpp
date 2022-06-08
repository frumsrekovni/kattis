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
    // cout << "piece1 first char: " << piece1.at(0) << endl;
    // cout << "1: " << char_hierarchy.at(piece1.at(0)) <<endl;
    // cout << "2: " <<  char_hierarchy.at(piece2.at(0))<<endl;
    return char_hierarchy.at(piece1.at(0)) > char_hierarchy.at(piece2.at(0));
    // cout << piece1.at(0);
}
bool chessPieceSort2(string piece1, string piece2){
    map<char, int> char_hierarchy { {'K', 10}, {'Q', 9}, {'R', 5}, {'B', 3}, {'N', 2}};
    if(piece1.size() > piece2.size()){
        return true;
    }
    else if(piece1.size() < piece2.size()){
        return false; 
    }

    if(piece1.size() == 2){
        return piece1.at(1) > piece2.at(1); // This is the only thing that needs to be flipped for black sort
    }
    return char_hierarchy.at(piece1.at(0)) > char_hierarchy.at(piece2.at(0));
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
    while(currentRow > 0){
        cin >>firstchar;
        if(currentline > 2){
            currentline = 1;
            currentRow--;
        }
        if(firstchar == '+'){ // "+" indicates that the entire line is useless
            getline(cin, in);
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
                    cin >> read_char;
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
                        read_char = toupper(read_char);
                        if(read_char == 'P'){
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
    for (size_t i = 0; i < wPieces.size(); i++)
    {
        cout << wPieces.at(i);
        if(i+1 != wPieces.size()){ // last element should not print a comma
        cout << ",";
        }
    }
    sort(bPieces.begin(),bPieces.end(), chessPieceSort2);
    cout << "\nBlack: ";
    for (size_t i = 0; i < bPieces.size(); i++)
    {
        cout << bPieces.at(i);
        if(i+1 != bPieces.size()){ // last element should not print a comma
        cout << ",";
        }
    }
    return 0;
}
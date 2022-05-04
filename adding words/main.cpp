#include <iostream>
#include <map>
#include <string>
#include <regex>
using namespace std;
// Words = Numbers
// Input is until end of file. eof()
// Each command is separated by ' '
// Three commands def calc clear
// def sets a numeric value to a word
// calc adds or subtracts words with a numeric value
// the resulting value from calc could equal another word with numeric value else just unknown
// clear removes all definitions
map<string, int>value_of_word;
map<int, string>word_of_value;
map<string,int>::iterator it;
map<int,string>::iterator it_word_of_value;
int main(){
    string inputWord = "";
    string operatorString = "";
    int sumOfWords = 0;
    bool noValueWord = false;
    bool wordfound = false;
    while(cin >> inputWord){
        if(inputWord == "def"){
            /*
            After finding the string "def" you need to input 2 more variables.
            First variable is the word. Second is the int value for that word.
            Connect them by saving them in a map.
            If word is already defined then overwrite its value with the new value
            */
            string word;
            int wordValue;
            cin >> word >> wordValue;
            if( wordValue <= 1000 &&
                wordValue >= -1000 &&
                word.length() <= 30 &&
                regex_match(word, regex("^[a-z]+$"))){

                it = value_of_word.find(word);
                it_word_of_value = word_of_value.find(wordValue);

                if(it_word_of_value != word_of_value.end()){
                    // The same numeric value is not allowed
                    word_of_value.erase(it_word_of_value);
                }
                if (it != value_of_word.end()){
                    // The same word is not allowed
                    value_of_word.erase(it);
                    word_of_value.erase(it->second);
                }
                value_of_word.insert(pair<string,int>(word,wordValue));
                word_of_value.insert(pair<int,string>(wordValue,word));
                // for (it = value_of_word.begin(); it != value_of_word.end(); it++)
                // {
                //     cout <<"Word: " <<it->first << " Value: " << it->second << endl;
                // }   
            }
         
            

        }
        else if(inputWord == "calc"){
            /*
            After finding the string "calc" you need to input more variables until
            you find the "=" character.
            Just search up the word in the map and use its numeric value
            to do the calculations. If the resulting value is not in map just print "unknown"
            */
            noValueWord = false;
            wordfound = false;
            sumOfWords = 0;
            cin >> inputWord;
            it = value_of_word.find(inputWord);
            if(it != value_of_word.end()){
                sumOfWords += it->second;
            }
            else{
                noValueWord = true;
            }

            do
            {
                cout << inputWord << " ";
                cin >> operatorString;
                cout << operatorString << " ";
                if(operatorString == "="){
                    break;
                }
                cin >> inputWord;
                it = value_of_word.find(inputWord);
                if(it == value_of_word.end()){
                    noValueWord = true;
                }
                else if(operatorString == "+"){
                    sumOfWords += it->second;
                }
                else if(operatorString == "-"){
                    sumOfWords -= it->second;
                }

            } while (operatorString != "=");
            if(!noValueWord){
                it_word_of_value = word_of_value.find(sumOfWords);
                if(it_word_of_value != word_of_value.end()){
                    cout << it_word_of_value->second;
                    wordfound = true;
                }

                // map<string, int>::iterator it2;
                // for (it2 = value_of_word.begin(); it2 != value_of_word.end(); it2++)
                // {
                //     if (it2->second == sumOfWords) {
                //         cout << it2->first;
                //         wordfound = true;
                //         break;
                //     }
                // }
            }
            if(!wordfound || noValueWord){
                cout << "unknown";   
            }
            cout << "\n";
        }
        else if(inputWord == "clear"){
           value_of_word.clear();
           word_of_value.clear();
        }
    }
    
    return 0;
}
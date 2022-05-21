#include <iostream>

int main(){
    int listlength = 0;
    std::cin >> listlength;
    int* list = new int [listlength];
    for (int i = 0; i < listlength; i++)
    {
        std::cin >> list[i];
    }
    for (int i = listlength-1; i >= 0; i--)
    {
        std::cout << list[i] << '\n';
    }
    return 0;
}
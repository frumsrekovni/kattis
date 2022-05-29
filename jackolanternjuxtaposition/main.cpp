#include <iostream>
int main(){
    int n(0),s(1);
    while(std::cin >> n){
        s *= n;
    }
    std::cout << s;
    return 0;
}
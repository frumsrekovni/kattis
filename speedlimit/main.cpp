#include <iostream>
using namespace std;


int main(){
    int n(0);
    cin >> n;
    while(n != -1){
        int result(0), speed(0), elapsedTime(0), prevElapsedTime(0);
        for (int i = 0; i < n; i++)
        {
            cin >> speed >> elapsedTime;
            result += (elapsedTime - prevElapsedTime) * speed;
            prevElapsedTime = elapsedTime;
            
        }
        cout << result << " miles\n";
        cin >> n;
    }
    return 0;
}
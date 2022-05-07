#include <iostream>
#include <iomanip>
using namespace std;
int testcases = 0;
int people_in_class = 0;

int main()
{
    cin >> testcases;
    for (int i = 0; i < testcases; i++)
    {
        float average = 0.0;
        cin >> people_in_class;
        int grades[people_in_class] = {};
        int grade = 0;
        int sum = 0;
        for (int y = 0; y < people_in_class; y++)
        {
            cin >> grade;
            sum += grade;
            grades[y] = grade;
        }
        average = sum / people_in_class;
        float above_average = 0.0;
        for (int y = 0; y < people_in_class; y++)
        {
            if(grades[y] > average){
                above_average++;
            }
        }
        float output = (above_average / people_in_class)*100;
        
        cout << setprecision(3) << output << "%\n";
        
    }
    return 0;
}
#include <iostream>
int sum = 0;
int nmb = 0;
int givenN = 0;
int main()
{
    std::cin >> givenN;
    for (size_t i = 0; i < givenN; i++)
    {
        std::cin >> nmb;
        sum += nmb;
    }
    std::cout << sum;
    return 0;
}
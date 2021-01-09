#include <iostream>
#include <string>
#include "chapter6.h"

int Fact(const int &nNumber)
{
    return nNumber > 1 ? nNumber * Fact(nNumber - 1) : 1;
}

void input_fact()
{
    const std::string str_enter = "please enter a number within [1, 13):";
    const std::string str_outrange = "out of range,please enter again!:";

    std::cout << str_enter;
    int nNumber = 0;
    while (std::cin >> nNumber)
    {
        if (1 > nNumber || nNumber > 12)
        {
            std::cout << str_outrange << std::endl;
            continue;
        }

        std::cout << Fact(nNumber) << std::endl;
        std::cout << str_enter << std::endl;
    }
}

int main()
{
    input_fact();

    return 0;
}
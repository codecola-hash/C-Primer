#include <iostream>

int Fact(const int &nNumber)
{
    return nNumber > 1 ? nNumber * Fact(nNumber - 1) : 1;
}

int main()
{
    std::cout << Fact(5) << std::endl;

    return 0;
}
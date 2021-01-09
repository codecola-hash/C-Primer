#include <iostream>

void Print(const int &i)
{
    std::cout << i << std::endl;
}

void Print(const int (&arr)[2])
{
    for (auto i : arr)
    {
        std::cout << i << std::endl;
    }
}

void Print(const int *p, const int &nSize)
{
    for (const int *pi = p; pi < p + nSize; ++pi)
    {
        std::cout << *pi << std::endl;
    }
}

void Print(const int *begin, const int *end)
{
    while (begin != end)
    {
        std::cout << *begin++ << std::endl;
    }
}

int main()
{
    int i = 0, j[2] = { 0, 1 };

    Print(i);
    Print(std::begin(j), std::end(j));
    Print(j, std::end(j) - std::begin(j));
    Print(j);
}
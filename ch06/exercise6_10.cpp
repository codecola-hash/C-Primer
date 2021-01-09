#include <iostream>

void swap(int *pnFirst, int *pnSecond)
{
    int nTemp = 0;
    nTemp = *pnFirst;
    *pnFirst = *pnSecond;
    *pnSecond = nTemp;
}

void swap(int &nFirst, int &nSecond)
{
    int nTemp = 0;
    nTemp = nFirst;
    nFirst = nSecond;
    nSecond = nTemp;
}

int main()
{
    int nFirst = 1;
    int nSecond = 2;

    swap(&nFirst, &nSecond);
    swap(nFirst, nSecond);

    std::cout << nFirst << std::endl << nSecond << std::endl;
}
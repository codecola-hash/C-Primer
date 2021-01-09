#include "chapter6.h"

int Fact(const int &nNumber)
{
    return nNumber > 1 ? nNumber * Fact(nNumber - 1) : 1;
}
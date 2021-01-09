#include <iostream>
#include <vector>

using vec_iter = std::vector<int>::iterator;

void output_vec(vec_iter iterFirst, vec_iter iterLast)
{
    if (iterFirst == iterLast)
    {
        std::cout << "±éÀúÍê³É" << std::endl;

        return;
    }

    std::cout << *iterFirst << std::endl;
    output_vec(++iterFirst, iterLast);
}

int main()
{
    std::vector<int> vec = { 1, 2, 3, 4, 5, 6 };

    output_vec(vec.begin(), vec.end());

    return 0;
}
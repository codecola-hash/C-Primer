#include <iostream>
#include <vector>
#include <cassert>

using vec_iter = std::vector<int>::iterator;

void output_vec(vec_iter iterFirst, vec_iter iterLast)
{
#ifndef NDEBUG
    // 执行调试信息
        std::cout << "vector size: " << iterLast - iterFirst << std::endl;
#endif

    assert(0 != iterLast - iterFirst);

    if (iterFirst == iterLast)
    {
        std::cout << "遍历完成" << std::endl;

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
#include <iostream>
#include <initializer_list>

int sum(std::initializer_list<int> const &init_int)
{
    int ret = 0;
    for (auto begin = init_int.begin(); begin != init_int.end(); ++begin)
    {
        ret += *begin;
    }

    return ret;
}

int main(int argc, char **argv)
{
    auto init_list = { 1, 2, 3, 4, 5 };

    std::cout << sum(init_list) << std::endl;
}
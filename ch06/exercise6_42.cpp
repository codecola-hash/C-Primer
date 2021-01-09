#include <iostream>
#include <string>

std::string make_plural(size_t ctr, const std::string &ending, const std::string &word = "s")
{
    return (ctr > 1) ? word + ending : word;
}

int main()
{
    std::cout << "singal: " << make_plural(1, "success", "failure") << std::endl;
    std::cout << "singal: " << make_plural(1, "failure", "success") << std::endl;
    std::cout << "plural: " << make_plural(2, "failure", "success") << std::endl;
    return 0;
}
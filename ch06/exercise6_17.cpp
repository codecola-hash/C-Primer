#include <iostream>
#include <string>

// 不需要改变，但因数据类型可能很大，使用常量引用传递
bool isHasBig(const std::string &str)
{
    for (auto character : str)
    {
        if (isupper(character))
        {
            return true;
        }
    }
    return false;
}

// 需要改变，使用引用传递
void toLower(std::string &str)
{
    for (auto &character : str)
    {
        character = tolower(character);
    }
}

int main()
{
    std::cout << isHasBig("Hello World") << std::endl;

    std::string str = "Hello World";
    toLower(str);
    std::cout << str << std::endl;

    return 0;
}
#include <iostream>
#include <string>

// ����Ҫ�ı䣬�����������Ϳ��ܴܺ�ʹ�ó������ô���
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

// ��Ҫ�ı䣬ʹ�����ô���
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
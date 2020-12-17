// 第一章.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

int main()
{
    /*int sum = 0;
    int condition = 50;

    while (condition <= 100)
    {
        sum += condition;
        condition++;
    }

    std::cout << sum << std::endl;*/

    // 使用 -- 打印 10-0
    /*int nNumber = 10;
    while (nNumber >= 0)
    {
        std::cout << nNumber << std::endl;

        --nNumber;
    }*/

    // 输入两个整数，打印整数之间的所有数字
    /*int nLeft = 0;
    int nRight = 0;

    std::cout << "请输入两个整数:" << std::endl;

    std::cin >> nLeft >> nRight;

    int max = nLeft > nRight ? nLeft : nRight;
    int min = nLeft > nRight ? nRight : nLeft;

    while (min <= max)
    {
        std::cout << min << std::endl;

        min++;
    }*/

    //1.16 从cin输入一组数，求和
    int sum = 0;
    int value = 0;
    while (std::cin >> value)
    {
        sum += value;
    }

    std::cout << sum << std::endl;
}

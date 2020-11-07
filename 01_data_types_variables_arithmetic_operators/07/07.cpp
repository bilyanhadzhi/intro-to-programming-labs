#include <iostream>

int main(void)
{
    int a, b, c;
    std::cin >> a >> b >> c;

    std::cout << (a * a + b * b == c * c) << std::endl;
    std::cout << (a % 10 + b % 10 == c) << std::endl;   // вземаме последната цифра с % 10
}

#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    do {
        std::cout << n % 10;
        n = n / 10;
    } while (n != 0);
    
    std::cout << std::endl;
}

#include <iostream>
#include <iomanip>

int main()
{
    int k;
    std::cin >> k;

    int num = 1;
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            std::cout << std::setw(2) << num << " ";
            num++;
        }
        std::cout << std::endl;
    }
}

#include <iostream>

bool is_power_of(int x, int n)
{
    if (n > x)
    {
        return false;
    }

    int initial_n = n;

    while (n < x)
    {
        n *= initial_n;
    }

    return n == x;
}

int main()
{
    std::cout << is_power_of(9, 3) << std::endl;
}

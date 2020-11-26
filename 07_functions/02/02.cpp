#include <iostream>

int max(int a, int b)
{
    if (a >= b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int main()
{
    std::cout << max(4, 5) << std::endl;
}

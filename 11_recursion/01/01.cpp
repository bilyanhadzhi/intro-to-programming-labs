#include <iostream>

int sum(int a, int b)
{
    if (b <= 0)
    {
        return a;
    }

    return sum(a + 1, b - 1);
}

int main()
{
    std::cout << sum(1, 6) << "\n";
}

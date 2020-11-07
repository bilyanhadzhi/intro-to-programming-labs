#include <iostream>

int main()
{
    double x, y;
    std::cin >> x >> y;

    if (x == 0 || y == 0)
    {
        std::cout << "The point is on the border between two or more quadrants" << std::endl;
        return 0;
    }

    if (x > 0 && y > 0)
    {
        std::cout << "I" << std::endl;
    }
    else if (x < 0 && y > 0)
    {
        std::cout << "II" << std::endl;
    }
    else if (x < 0 && y < 0)
    {
        std::cout << "III" << std::endl;
    }
    else
    {
        std::cout << "IV" << std::endl;
    }
}

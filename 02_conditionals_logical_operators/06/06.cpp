#include <iostream>

int main(void)
{
    int day1, month1;
    int	day2, month2;

    std::cin >> day1 >> month1 >> day2 >> month2;

    bool result = false;

    if (month1 > month2)
    {
        result = false;
    }
    else
    {
        if (day1 >= day2)
        {
            result = false;
        }
        else {
            result = true;
        }
    }

    std::cout << result << std::endl;
}

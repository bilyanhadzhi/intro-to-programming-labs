#include <iostream>

int main()
{
    int num;
    std::cin >> num;

    int num_initial = num;
    int digits = 0, position = -1;

    while (num != 0)
    {
        int curr_digit = num % 10;

        if (curr_digit == 5)
        {
            position = digits;
        }

        digits++;
        num /= 10;
    }

    if (position == -1)
    {
        std::cout << num_initial << std::endl;
        return 0;
    }

    int to_add = 2;
    for (int i = 0; i < position; i++)
    {
        to_add *= 10;
    }

    int result = num_initial + to_add;
    std::cout << result << std::endl;
}

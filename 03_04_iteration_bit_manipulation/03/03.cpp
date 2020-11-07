#include <iostream>

int main()
{
    int a, b;
    std::cin >> a >> b;

    int num_count = 0;
    if (a <= b)
    {
        for (int i = a; i < b; i++)
        {
            std::cout << i << ", ";

            num_count++;
            if (num_count % 10 == 0)
            {
                std::cout << "\n";
            }
        }

        std::cout << b;
    }
    else
    {
        for (int i = a; i > b; i--)
        {
            std::cout << i << ", ";

            num_count++;
            if (num_count % 10 == 0)
            {
                std::cout << "\n";
            }
        }

        std::cout << b;
    }
}

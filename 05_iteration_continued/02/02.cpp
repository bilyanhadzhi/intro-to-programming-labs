#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    int steps = 0;
    while (n != 0)
    {
        //if (n % 2 == 1 && n != 1)
        //{
        //    steps++;
        //}

        //n = n >> 1;

        if (n % 2 == 0)
        {
            n = n / 2;
        }
        else
        {
            n = n - 1;
        }

        steps++;
    }

    std::cout << steps << "\n";
}

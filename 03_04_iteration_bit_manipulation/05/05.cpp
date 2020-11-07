#include <iostream>
#include <cmath>

int main()
{
    int n;
    std::cin >> n;

    if (n < 0)
    {
        return 1;
    }

    int fib_n = -1;
    if (n == 0)
    {
        fib_n = 0;
    }
    else if (n == 1)
    {
        fib_n = 1;
    }
    else
    {
        int fib_n_2 = 0;
        int fib_n_1 = 1;

        for (int i = 2; i <= n; i++)
        {
            fib_n = fib_n_2 + fib_n_1;
            fib_n_2 = fib_n_1;
            fib_n_1 = fib_n;
        }
    }

    std::cout << fib_n << std::endl;
}

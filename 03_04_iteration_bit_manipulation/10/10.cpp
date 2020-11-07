#include <iostream>
#include <cmath>

int main()
{
    int n;
    std::cin >> n;

    int sqrt_n = sqrt(n);

    //simpler, but slower solution
    //for (int i = 2; i <= n; ++i)
    //{
    //    while (n % i == 0)
    //    {
    //        std::cout << i << " ";
    //        n = n / i;
    //    }
    //}

    // 2 is a special case becuase it is the only even prime
    while (n % 2 == 0)
    {
        std::cout << 2 << " ";
        n /= 2;
    }

    // we can skip all even numbers
    for (int i = 3; i <= sqrt_n; i += 2)
    {
        while (n % i == 0)
        {
            std::cout << i << " ";
            n /= i;
        }
    }

    // at the end, we're left with 1 or a prime number as the last factor
    if (n > 2) {
        std::cout << n << " ";
    }

    std::cout << std::endl;
}

#include <iostream>
#include <cmath>

int main()
{
    int n;
    std::cin >> n;

    bool is_prime = true;

    if (n <= 1)
    {
        is_prime = false;
    }

    const int sqrt_n = sqrt(n);
    // we'd loop until sqrt(n), but we can't use functions yet
    for (int i = 2; i <= sqrt_n && is_prime; i++)
    {
        if (n % i == 0)
        {
            is_prime = false;
        }
    }

    std::cout << (is_prime ? "prime" : "not prime") << std::endl;
}

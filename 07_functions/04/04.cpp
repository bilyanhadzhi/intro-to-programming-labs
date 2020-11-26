#include <iostream>
#include <cmath>

bool is_prime(int x)
{
    int sqrt_x = sqrt(x);

    for (int i = 2; i <= sqrt_x; i++)
    {
        if (x % i == 0)
        {
            return false;
        }
    }

    return true;
}

void print_all_primes_in_range(int a, int b)
{
    if (a > b)
    {
        return;
    }

    for (int i = a; i <= b; i++)
    {
        if (is_prime(i))
        {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
}

int main()
{
    print_all_primes_in_range(90, 6);
}

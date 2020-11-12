#include <iostream>
#include <cmath>

int main()
{
    int n;
    std::cin >> n;

    int first_num = 2;
    int second_num = n - 2;

    const int half_n = n / 2;

    while (first_num <= half_n)
    {
        const int sqrt_first_num = sqrt(first_num);
        bool first_num_prime = true;

        for (int i = 2; i <= sqrt_first_num && first_num_prime; i++)
        {
            if (first_num % i == 0)
            {
                first_num_prime = false;
            }
        }

        const int sqrt_second_num = sqrt(second_num);
        bool second_num_prime = true;

        for (int i = 2; i <= sqrt_second_num && first_num_prime && second_num_prime; i++)
        {
            if (second_num % i == 0)
            {
                second_num_prime = false;
            }
        }

        if (first_num_prime && second_num_prime)
        {
            std::cout << first_num << " " << second_num << "\n";
        }

        first_num++;
        second_num--;
    }
}

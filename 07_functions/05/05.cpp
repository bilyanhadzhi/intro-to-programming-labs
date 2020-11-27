#include <iostream>

const int SIZE = 1024;

bool is_power_of(int n, int x)
{
    if (n > x)
    {
        return false;
    }

    int initial_n = n;

    while (n < x)
    {
        n *= initial_n;
    }

    return n == x;
}

bool contains_k_numbers_power(int k, int n, int a[], int len)
{
    int num_count = 0;

    for (int i = 0; i < len; i++)
    {
        if (is_power_of(n, a[i]))
        {
            num_count++;
        }
    }

    return num_count == k;
}

int main()
{
    int arr[SIZE] = { 3, 3, 7, 9, 27, 81, 15 };
    int el_count = 7;

    std::cout << (contains_k_numbers_power(5, 3, arr, el_count)) << std::endl;
}

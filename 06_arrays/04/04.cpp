#include <iostream>

const int MAX_ELEMENTS = 1024;

int main()
{
    int n;
    std::cin >> n;

    // инициализация с нули
    int arr[10] = {};

    if (n == 0)
    {
        arr[0]++;
    }

    // Ако n == 0, не влизаме тук
    while (n != 0)
    {
        int curr_digit = n % 10;
        arr[curr_digit]++;

        n /= 10;
    }

    for (int i = 0; i < 10; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << "\n";
}

#include <iostream>

const int MAX_ELEMENTS = 1024;

int main()
{
    int n;
    std::cin >> n;

    int arr[MAX_ELEMENTS];

    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    int min_el = arr[0];
    int max_el = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min_el)
        {
            min_el = arr[i];
        }
        if (arr[i] > max_el)
        {
            max_el = arr[i];
        }
    }

    std::cout << min_el << " " << max_el << "\n";
}

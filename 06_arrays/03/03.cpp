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

    for (int i = 0; i < n; i++)
    {
        int curr_sum = 0;
        for (int j = i + 1; j < n; j++)
        {
            curr_sum += arr[j];
        }

        if (arr[i] > curr_sum)
        {
            std::cout << arr[i] << " ";
        }
    }
}

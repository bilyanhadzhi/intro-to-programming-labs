#include <iostream>

const int MAX_SIZE = 1024;

int main()
{
    int n;
    std::cin >> n;

    int arr[MAX_SIZE];

    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    int k;
    std::cin >> k;

    int begin_index = -1;
    int end_index = -1;

    int curr_sum = 0;
    bool found = false;

    for (int i = 0; i < n && !found; i++)
    {
        curr_sum = 0;

        for (int j = i; j < n && !found; j++)
        {
            curr_sum += arr[j];

            std::cout << curr_sum << "\n";

            if (curr_sum == k)
            {
                begin_index = i;
                end_index = j;
                found = true;
            }
            else if (curr_sum > k)
            {
                curr_sum = 0;
                break;
            }
        }
    }

    if (begin_index == -1)
    {
        std::cout << "Not found" << std::endl;
    }
    else
    {
        std::cout << begin_index << " " << end_index << std::endl;
    }
}

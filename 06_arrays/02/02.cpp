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

    int curr_begin_index = 0;
    int curr_len = 1;

    int begin_index = curr_begin_index;
    int max_len = curr_len;

    for (int i = 1; i < n; i++)
    {
        // сегашната подредица приключва;
        if (arr[i - 1] > arr[i])
        {
            if (curr_len > max_len)
            {
                begin_index = curr_begin_index;
                max_len = curr_len;
            }

            // започваме нова
            curr_begin_index = i;
            curr_len = 1;
        }
        else
        {
            curr_len++;
        }
    }

    // Последна проверка дали в края на масива стои най-дългата редица
    if (curr_len > max_len)
    {
        begin_index = curr_begin_index;
        max_len = curr_len;
    }

    int end_index = begin_index + max_len - 1;
    for (int i = begin_index; i <= end_index; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << "\n";
}

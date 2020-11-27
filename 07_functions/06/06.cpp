#include <iostream>

const int MAX_SIZE = 1024;

int get_lucky_number(int arr[], int len)
{
    int times_seen[101] = {};

    for (int i = 0; i < len; i++)
    {
        int curr_num = arr[i];
        times_seen[curr_num]++;
    }

    int lucky_number = -1;
    for (int i = 100; i > 0 && lucky_number == -1; i--)
    {
        if (times_seen[i] == i)
        {
            lucky_number = i;
        }
    }

    return lucky_number;
}

int main()
{
    int arr[MAX_SIZE] = { 4,4,4,4 };
    int arr_len = 4;

    std::cout << get_lucky_number(arr, arr_len) << std::endl;
}

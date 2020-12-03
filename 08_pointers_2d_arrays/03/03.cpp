#include <iostream>

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void order(int* arr, const int n)
{
    bool looking_for_max = true;

    for (int i = 0; i < n; i++)
    {
        int* to_swap = &arr[i];

        for (int j = i; j < n; j++)
        {
            if (looking_for_max && arr[j] > * to_swap)
            {
                to_swap = &arr[j];
            }
            else if (!looking_for_max && arr[j] < *to_swap)
            {
                to_swap = &arr[j];
            }
        }

        swap(&arr[i], to_swap);
        looking_for_max = !looking_for_max;
    }
}

int main()
{
    int arr[6] = { 5, 2, 1, 6, 7, 4 };

    order(arr, 6);

    for (int i = 0; i < 6; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

#include <iostream>

const int SIZE = 4;

void print_array(int* arr, const int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << *(arr + i) << " ";
    }
}

int main()
{
    int arr[SIZE] = { 1, 2, 3, 4 };

    print_array(arr, SIZE);
}

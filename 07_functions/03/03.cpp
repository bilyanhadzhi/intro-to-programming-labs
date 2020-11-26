#include <iostream>

const int MAX_SIZE = 1024;

void input_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
}

void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << "\n";
}

int main()
{
    int test_arr[1024];

    int n;
    std::cin >> n;

    input_array(test_arr, n);
    print_array(test_arr, n);
}

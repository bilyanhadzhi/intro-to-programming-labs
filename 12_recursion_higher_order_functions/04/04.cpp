#include <iostream>

// Зад. 4:
// Даден е масив от 2n елемента, като елементите a(0)..a(n-1) са сортирани
// възходящо, а елементите a(n)..a(2n-1) - в намаляващ ред.
// Да се напише програмен фрагмент, който обединява половинките в нов сортиран масив.

void merge(int* arr, const int n, int* destination)
{
    int left = 0, right = n - 1;
    int destination_index = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[left] <= arr[right])
        {
            destination[destination_index++] = arr[left++];
        }
        else
        {
            destination[destination_index++] = arr[right--];
        }
    }
}

int main()
{
    int arr[] = { 1, 3, 4, 6, 7, 12, 10, 9, 8, 5, 2, 0 };
    int* destination = new int[12];

    merge(arr, 12, destination);
    for (int i = 0; i < 12; i++)
    {
        std::cout << destination[i] << " ";
    }
    std::cout << "\n";

    delete[] destination;
}

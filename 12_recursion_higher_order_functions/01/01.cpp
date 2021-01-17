#include <iostream>

// Зад.1:
// Напишете рекурсивна функция, която намира елемент в сортиран масив.

// Зад. 1
int binary_search(int* arr, const int beg, const int end, int el)
{
    if (beg > end)
    {
        return -1;
    }

    int mid = (beg + end) / 2;

    // to avoid overflow:
    // int mid = beg + (end - beg) / 2;

    if (el > arr[mid])
    {
        return binary_search(arr, mid + 1, end, el);
    }
    else if (el < arr[mid])
    {
        return binary_search(arr, beg, mid - 1, el);
    }
    else
    {
        return mid;
    }
}

int main()
{
    int elements[] = { 1, 2, 5, 6, 7, 9, 10, 12, 15, 17 };

    std::cout << binary_search(elements, 0, 9, 6) << "\n";
}

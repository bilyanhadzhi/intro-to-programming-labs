#include <iostream>

const int MAX_SIZE = 1024;

int main()
{
    int n, m;
    std::cin >> n >> m;

    int arr1[MAX_SIZE];
    int arr2[MAX_SIZE];

    // input
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr1[i];
    }

    for (int i = 0; i < m; i++)
    {
        std::cin >> arr2[i];
    }

    // sort
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr1[j] > arr1[j + 1])
            {
                int tmp = arr1[j];
                arr1[j] = arr1[j + 1];
                arr1[j + 1] = tmp;
            }
        }
    }

    for (int i = 0; i < m - 1; i++)
    {
        for (int j = 0; j < m - i - 1; j++)
        {
            if (arr2[j] > arr2[j + 1])
            {
                int tmp = arr2[j];
                arr2[j] = arr2[j + 1];
                arr2[j + 1] = tmp;
            }
        }
    }

    //for (int i = 0; i < n; i++)
    //{
    //    std::cout << arr1[i] << " ";
    //}
    //std::cout << "\n";

    //for (int i = 0; i < m; i++)
    //{
    //    std::cout << arr2[i] << " ";
    //}

    int arr1_unique[MAX_SIZE];
    int arr2_unique[MAX_SIZE];

    int unique1_cursor = 0;
    int unique2_cursor = 0;

    arr1_unique[unique1_cursor++] = arr1[0];

    // make arrays of unique elements
    for (int i = 0; i < n - 1; i++)
    {
        if (arr1[i] != arr1[i + 1])
        {
            arr1_unique[unique1_cursor++] = arr1[i + 1];
        }
    }

    arr2_unique[unique2_cursor++] = arr2[0];
    for (int i = 0; i < m - 1; i++)
    {
        if (arr2[i] != arr2[i + 1])
        {
            arr2_unique[unique2_cursor++] = arr2[i + 1];
        }
    }

    //for (int i = 0; i < unique1_cursor; i++)
    //{
    //    std::cout << arr1_unique[i] << " ";
    //}
    //std::cout << "\n";

    //for (int i = 0; i < unique2_cursor; i++)
    //{
    //    std::cout << arr2_unique[i] << " ";
    //}

    bool are_same_set = true;

    if (unique1_cursor != unique2_cursor)
    {
        are_same_set = false;
    }
    else
    {
        for (int i = 0; i < unique1_cursor && are_same_set; i++)
        {
            if (arr1_unique[i] != arr2_unique[i])
            {
                are_same_set = false;
            }
        }
    }

    std::cout << (are_same_set ? "Yes" : "No") << std::endl;
}

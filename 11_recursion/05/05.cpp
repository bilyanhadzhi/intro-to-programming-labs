#include <iostream>

bool can_jump_to_zero_rec(const int* arr, const int n, int curr_index, bool* visited)
{
    if (curr_index < 0 || curr_index >= n || visited[curr_index])
    {
        return false;
    }

    if (arr[curr_index] == 0)
    {
        return true;
    }

    visited[curr_index] = 1;

    return can_jump_to_zero_rec(arr, n, curr_index - arr[curr_index], visited)
        || can_jump_to_zero_rec(arr, n, curr_index + arr[curr_index], visited);
}

bool can_jump_to_zero(const int* arr, const int n, int start)
{
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    bool result = can_jump_to_zero_rec(arr, n, 0, visited);

    // free memory
    delete[] visited;

    return result;
}

int main()
{
    const int n = 7;
    int arr[n] = { 4, 2, 3, 0, 3, 1, 2 };

    std::cout << can_jump_to_zero(arr, n, 6) << "\n";
}

#include <iostream>
#include <algorithm>

const int SIZE = 1024;

int steps(int x_values[SIZE], int y_values[SIZE], int n)
{
    int steps = 0;

    for (int i = 1; i < n; i++)
    {
        int dist_y = std::abs(y_values[i] - y_values[i - 1]);
        int dist_x = std::abs(x_values[i] - x_values[i - 1]);

        steps += std::max(dist_y, dist_x);
    }

    return steps;
}

int main()
{
    int x_values[] = { -2, 2, -1 };
    int y_values[] = { 1, 3, -2 };

    int n = 3;

    std::cout << steps(x_values, y_values, n) << std::endl;
}

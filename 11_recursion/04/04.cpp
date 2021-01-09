#include <iostream>

int tribonacci_helper(int n, int* values)
{
    if (values[n] != -1)
    {
        return values[n];
    }

    values[n] = tribonacci_helper(n - 3, values)
        + tribonacci_helper(n - 2, values)
        + tribonacci_helper(n - 1, values);

    return values[n];
}

int tribonacci(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1 || n == 2)
    {
        return 1;
    }

    int* values = new int[n + 1];

    for (int i = 0; i <= n; i++)
    {
        values[i] = -1;
    }

    values[0] = 0;
    values[1] = 1;
    values[2] = 1;

    int value = tribonacci_helper(n, values);

    delete[] values;

    return value;
}

int main()
{
    int n;
    std::cin >> n;

    std::cout << tribonacci(n) << "\n";
}

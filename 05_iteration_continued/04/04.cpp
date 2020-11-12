#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    int left_side = 0;
    int right_side = 0;

    //left_side = ((n * (n + 1)) / 2) * ((n * (n + 1)) / 2);
    //right_side = (n * (n + 1) * (2*n + 1)) / 6;

    for (int i = 1; i <= n; i++)
    {
        left_side += i;
        right_side += (i * i);
    }

    left_side = left_side * left_side;

    int result = left_side - right_side;

    std::cout << result << "\n";
}

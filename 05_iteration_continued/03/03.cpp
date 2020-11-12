#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        int curr_num;
        std::cin >> curr_num;

        sum += (curr_num * curr_num);
    }

    std::cout << sum << "\n";
}

#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    int n_opp_sign = ~n + 1;

    std::cout << n_opp_sign << "\n";
}

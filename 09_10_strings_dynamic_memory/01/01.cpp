#include <iostream>

const int MAX_LEN = 129;

int main()
{
    char first_name[MAX_LEN];
    char last_name[MAX_LEN];

    std::cin >> first_name;
    std::cin >> last_name;

    std::cout << last_name << ", " << first_name << "\n";
}

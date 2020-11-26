#include <iostream>

const int MAX_ELEMENTS = 1024;

int main()
{
    int n;
    std::cin >> n;

    int begin_times[MAX_ELEMENTS];
    int end_times[MAX_ELEMENTS];

    for (int i = 0; i < n; i++)
    {
        std::cin >> begin_times[i];
        std::cin >> end_times[i];
    }

    int given_point;
    std::cin >> given_point;

    int counter = 0;
    for (int i = 0; i < n; i++)
    {
        if (given_point >= begin_times[i] && given_point < end_times[i])
        {
            counter++;
        }
    }

    std::cout << counter << "\n";
}

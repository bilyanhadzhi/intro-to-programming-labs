#include <iostream>
#include <cstring>

int first_capital_rec(const char* str, int curr_index)
{
    if (str[curr_index] >= 'A' && str[curr_index] <= 'Z')
    {
        return curr_index;
    }

    if (str[curr_index] == '\0') // curr_index >= strlen(str)
    {
        return -1;
    }

    return first_capital_rec(str, curr_index + 1);
}

int first_capital(const char* str)
{
    return first_capital_rec(str, 0);
}

int main()
{
    const int len = strlen("longWord");
    char* str = new char[len + 1]; // '\0'

    strcpy(str, "longword");

    std::cout << first_capital(str) << "\n";

    delete[] str;
}

#include <iostream>
#include <cstring>

bool is_palindrome_rec(const char* str, int beg, int end)
{
    if (str[beg] != str[end])
    {
        return false;
    }

    if (beg >= end)
    {
        return true;
    }

    return is_palindrome_rec(str, beg + 1, end - 1);
}

bool is_palindrome(const char* str)
{
    is_palindrome_rec(str, 0, strlen(str) - 1);
}

int main()
{
    std::cout << is_palindrome("v") << "\n";
}

#include <iostream>

void print_string(char* str)
{
    while (*str != '\0')
    {
        std::cout << *str;
        str++;
    }
    std::cout << "\n";
}

int main()
{
    char str[] = "hello";

    print_string(str);
}

#include <iostream>
#include <cstring>

const int MAX_LEN = 257;

bool is_whitespace(char ch)
{
    return ch == ' ' || ch == '\n' || ch == '\t' || ch == '\r';
}

void trim(char* str)
{
    const int len = strlen(str);
    int begin_index = 0;
    int end_index = len - 1;

    while (begin_index < len && is_whitespace(str[begin_index]))
    {
        begin_index++;
    }

    if (begin_index == len)
    {
        return;
    }

    while (end_index > begin_index && is_whitespace(str[end_index]))
    {
        end_index--;
    }

    int trimmed_len = end_index - begin_index + 1;
    for (int i = 0; i < trimmed_len; i++)
    {
        str[i] = str[begin_index + i];
    }

    str[trimmed_len] = '\0';
}

int main()
{
    char input[MAX_LEN] = "  this is a string\n\n";

    std::cout << input << "\n";
    trim(input);
    std::cout << input << "\n";
}

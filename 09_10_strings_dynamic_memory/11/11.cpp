#include <iostream>
#include <cstring>

const int MAX_LEN = 257;

int find_closing_brace(const char* str, int opening_brace_index)
{
    const int len = strlen(str);

    if (opening_brace_index < 0 || opening_brace_index >= len
        || str[opening_brace_index] != '(')
    {
        return -1;
    }

    int closing_brace_index = -1;
    int level = 1;

    for (int i = opening_brace_index + 1; i < len; i++)
    {
        if (str[i] == '(')
        {
            level++;
        }
        else if (str[i] == ')')
        {
            level--;

            if (level == 0)
            {
                closing_brace_index = i;
                break;
            }
        }
    }

    return closing_brace_index;
}

int main()
{
    char input[MAX_LEN] = "() ";

    std::cout << find_closing_brace(input, 0) << "\n";
}

#include <iostream>
#include <cstring>

const int MAX_LEN = 129;

int longest_substr_one_char(char* str)
{
    const int len = strlen(str);

    if (len == 0)
    {
        return 0;
    }
    if (len == 1)
    {
        return 1;
    }

    int curr_count = 1, longest_count = 1;
    for (int i = 0; i < len - 1; i++)
    {
        if (str[i] != str[i + 1])
        {
            if (curr_count > longest_count)
            {
                longest_count = curr_count;
            }

            curr_count = 1;
        }
        else
        {
            curr_count++;
        }
    }

    if (curr_count > longest_count)
    {
        longest_count = curr_count;
    }

    return longest_count;
}

int main()
{
    char input[] = "helo";

    std::cout << longest_substr_one_char(input) << "\n";
}

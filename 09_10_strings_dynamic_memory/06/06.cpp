#include <iostream>

bool is_uppercase(char ch)
{
    return ch >= 'A' && ch <= 'Z';
}

char to_lowercase_ch(char ch)
{
    if (!is_uppercase(ch))
    {
        return 0;
    }

    int diff = 'a' - 'A';   // 32

    return ch + diff;
}

void to_lowercase(char* str)
{
    const int len = strlen(str);

    for (int i = 0; i < len; i++)
    {
        char curr = str[i];
        if (is_uppercase(curr))
        {
            str[i] = to_lowercase_ch(curr);
        }
    }
}

int main()
{
}

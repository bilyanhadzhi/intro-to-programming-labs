#include <iostream>
#include <cstring>

const int MAX_LEN = 129;

void ceasar(char* text, int key, char* result)
{
    const int text_len = strlen(text);

    for (int i = 0; i < text_len; i++)
    {
        int new_ch = text[i] - 'a';
        new_ch = (new_ch + key) % 26;

        result[i] = new_ch + 'a';
    }
    result[text_len] = '\0';
}

int main()
{
    char str[MAX_LEN] = "xyz";
    char result[MAX_LEN];

    ceasar(str, 13, result);

    std::cout << result << "\n";
}

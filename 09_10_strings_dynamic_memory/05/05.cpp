#include <iostream>
#include <cstring>

const int MAX_LEN = 257;

void vigenere(const char* text, const char* key, char* result)
{
    const int text_len = strlen(text);
    const int key_len = strlen(key);

    for (int i = 0; i < text_len; i++)
    {
        int new_pos = text[i] - 'a';
        int to_shift = key[i % key_len] - 'a';

        new_pos = (new_pos + to_shift) % 26;

        result[i] = new_pos + 'a';
    }

    result[text_len] = '\0';
}

int main()
{
    char text[MAX_LEN] = "xyz";
    char key[] = "bc";

    char result[MAX_LEN];

    vigenere(text, key, result);

    std::cout << result << "\n";
}

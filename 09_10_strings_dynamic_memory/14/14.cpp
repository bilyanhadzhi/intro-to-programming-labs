#include <iostream>
#include <cstring>

const int MAX_LEN = 257;
const int CHAR_COUNT = 255;

bool anagram(const char* str1, const char* str2)
{
    const int len1 = strlen(str1);
    const int len2 = strlen(str2);

    if (len1 != len2)
    {
        return false;
    }

    int str1_chars[CHAR_COUNT] = {};
    int str2_chars[CHAR_COUNT] = {};

    for (int i = 0; i < len1; i++)
    {
        str1_chars[str1[i]]++;
    }
    for (int i = 0; i < len2; i++)
    {
        str2_chars[str2[i]]++;
    }

    bool anagrams = true;
    for (int i = 0; i < CHAR_COUNT && anagrams; i++)
    {
        if (str1_chars[i] != str2_chars[i])
        {
            anagrams = false;
        }
    }

    return anagrams;
}

int main()
{
    char input1[MAX_LEN] = "polarr";
    char input2[MAX_LEN] = "paroll";

    std::cout << anagram(input1, input2) << "\n";
}

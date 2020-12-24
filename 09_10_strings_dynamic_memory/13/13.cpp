#include <iostream>
#include <cstring>

const int MAX_LEN = 257;

char* concat(const char* str1, const char* str2)
{
    const int len1 = strlen(str1);
    const int len2 = strlen(str2);

    char* result = new char[len1 + len2 + 1];

    int result_len = 0;
    for (int i = 0; i < len1; i++)
    {
        result[result_len++] = str1[i];
    }
    for (int i = 0; i < len2; i++)
    {
        result[result_len++] = str2[i];
    }

    result[len1 + len2] = '\0';

    return result;
}

int main()
{
    char input1[MAX_LEN] = "this is ";
    char input2[MAX_LEN] = "Sparta!";

    char* concatted = concat(input1, input2);

    std::cout << concatted << "\n";

    delete[] concatted;
}

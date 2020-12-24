#include <iostream>
#include <cstring>

const int MAX_LEN = 129;

void swap(char* a, char* b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

void reverse(char* arr)
{
    const int len = strlen(arr);
    const int half_len = len / 2;

    for (int i = 0; i < half_len; i++)
    {
        swap(&arr[i], &arr[len - i - 1]);
    }
}

int main()
{
    char str[MAX_LEN] = "helolo";

    reverse(&str[0]);

    std::cout << str << "\n";
}

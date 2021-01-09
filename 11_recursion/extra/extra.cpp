#include <iostream>
#include <cstring>

// Задача 1: Да се напише рекурсивна функция, която връща
// броя на цифрите в даден низ

// Задача 2: Да се напише рекурсивна функция, която по даден масив извежда сумите
// на всичките му подмножества.

// [5, 1, 4, 7]
//             0
//        0         5
//    0       1     5       6
//  0   4    1  5  5   9   6    10
// 0,7 4,11 1,8 ...

// Задача 3: Да се напише рекурсивна функция, която извежда всички пермутации
// на даден низ.

bool is_digit(char ch)
{
    return ch >= '0' && ch <= '9';
}

int count_digits(const char* str, int i, int n)
{
    if (i >= n)
    {
        return 0;
    }

    if (is_digit(str[i]))
    {
        return 1 + count_digits(str, i + 1, n);
    }
    else
    {
        return count_digits(str, i + 1, n);
    }
}

void sum_all_subsets(int* arr, const int n, int i, int curr_sum)
{
    if (i >= n)
    {
        std::cout << curr_sum << "\n";
        return;
    }

    sum_all_subsets(arr, n, i + 1, curr_sum);
    sum_all_subsets(arr, n, i + 1, curr_sum + arr[i]);
}

void swap(char* a, char* b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

void permutations(char* str, int i, const int len)
{
    if (i + 1 == len)
    {
        std::cout << str << "\n";
        return;
    }

    for (int curr = i; curr < len; curr++)
    {
        swap(&str[i], &str[curr]);

        permutations(str, i + 1, len);

        swap(&str[i], &str[curr]);
    }

}

int main()
{
    int arr[4] = {5,1,4,7};

    // const char* str = "test123str";

    // std::cout << count_digits(str, 0, strlen(str)) << std::endl;

    // sum_all_subsets(arr, 4, 0, 0);

    const char* const_str = "abcd";

    char* str = new char[strlen(const_str) + 1];
    strcpy(str, const_str);

    permutations(str, 0, strlen(str));

    delete[] str;
}

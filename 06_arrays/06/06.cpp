#include <iostream>

const int MAX_ELEMENTS = 1024;

int main()
{
    int n;
    std::cin >> n;

    int arr[MAX_ELEMENTS];

    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    int i = 0;

    // пропускаме първите елементи, които не са нули
    // (защото не трябва да ги презаписваме)
    while (arr[i] != 0)
    {
        i++;
    }

    int j = i;

    // пропускаме нули и записваме не-нули на j-та позиция
    while (i < n)
    {
        if (arr[i] != 0)
        {
            arr[j] = arr[i];
            j++;
        }

        i++;
    }

    // записваме нули на оставащите места
    while (j < n)
    {
        arr[j] = 0;
        j++;
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << "\n";
}

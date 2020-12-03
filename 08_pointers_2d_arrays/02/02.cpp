#include <iostream>

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main()
{
    int a = 5;
    int b = 4;

    std::cout << a << " " << b << "\n";

    swap(&a, &b);

    std::cout << a << " " << b << "\n";
}

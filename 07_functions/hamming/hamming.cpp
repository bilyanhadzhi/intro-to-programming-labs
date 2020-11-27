#include <iostream>

int dist(unsigned int A, unsigned int B)
{
    int xor_a_b = A ^ B;

    int ones_count = 0;
    while (xor_a_b != 0)
    {
        ones_count += xor_a_b & 1;
        xor_a_b = xor_a_b >> 1;
    }

    return ones_count;
}

int main()
{
    std::cout << dist(9, 6) << std::endl;
}

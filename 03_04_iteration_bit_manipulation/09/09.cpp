#include <iostream>

int main()
{
    int n_initial;
    std::cin >> n_initial;

    int zeros_count = 0;
    int ones_count = 0;

    int n = n_initial;
    while (n != 0)
    {
        // last bit was a one
        if ((n & 1) == 1)
        {
            ones_count++;
        }
        else
        {
            zeros_count++;
        }

        n = n >> 1;
    }

    // A power of two is: 1000...0000
    // subtracting one:   0111...1111
    bool is_power_of_two = (n_initial & (n_initial - 1)) == 0;

    // Alternating bits:
    // simpler solution:
    //    bool has_alternating_bits = true;
    //    while (n >> 1 != 0)
    //    {
    //        if ((n & 1) == ((n >> 1) & 1)) // we've seen the same bits next to each other
    //        {
    //            has_alternating_bits = false;
    //        }
    //        n >>= 1;
    //    }

    // alternating bits with shifting twice to the right:
    // (1010 1010) ^ (0010 1010) =
    // (1000 0000) (aka a power of two)
    // we'll just need to check if the result of this xor is a power of two
    int result_of_xor = n_initial ^ (n_initial >> 2);
    bool has_alternating_bits = (result_of_xor & (result_of_xor - 1)) == 0;

    // For complement number
    // first, we flip all bits but then all the leading zeros become ones

    int negated_n = ~n_initial;

    // we need to keep only the bits we need
    // we get a 1 with a (ones_count + zeros_zount) zeros after it
    // subtract 1 -> we get (ones_count + zeros_count) ones
    int complement_mask = (1 << (ones_count + zeros_count)) - 1;

    // AND with those ones is what keeps only the bits we need
    int complement_number = negated_n & complement_mask;

    std::cout << "Number of ones: " << ones_count << std::endl;

    std::cout << "Number of zeros: " << zeros_count << std::endl;

    //std::cout << "Is power of two: " << (ones_count == 1 ? "true" : "false") << std::endl;
    std::cout << "Is power of two: " << is_power_of_two ? "true" : "false")
    << std::endl;

    std::cout << "Has alternating bits: " << has_alternating_bits ? "true" : "false")
    << std::endl;

    std::cout << "Complement: " << (negated_n & complement_mask) << std::endl;
}

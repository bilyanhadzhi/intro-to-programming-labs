#include <iostream>

int main()
{
	// 101 &
	// 001 -> 001

	// 100 &
	// 001 -> 000

	int n;
	std::cin >> n;

	int zeros_count = 0;
	int ones_count = 0;

	while (n != 0) {
		// last bit was a one
		if ((n & 1) == 1) {
			ones_count++;
		}
		else {
			zeros_count++;
		}
		
		n = n >> 1;
	}

	std::cout << "Number of ones: " << ones_count << std::endl;
	std::cout << "Number of zeros: " << zeros_count << std::endl;
}
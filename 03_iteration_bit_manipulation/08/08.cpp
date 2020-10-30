#include <iostream>

int main()
{
	int n;
	std::cin >> n;

	bool is_prime = true;

	if (n <= 1) {
		is_prime = false;
	}

	// we'd loop until sqrt(n), but we can't use functions yet
	for (int i = 2; i <= (n / 2) && is_prime; i++) {
		if (n % i == 0) {
			is_prime = false;
		}
	}

	std::cout << (is_prime ? "prime" : "not prime") << std::endl;
}

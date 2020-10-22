#include <iostream>

int main(void)
{
	int points;
	std::cin >> points;

	if (points < 0) {
		std::cout << "Impossible!" << std::endl;
	}
	else if (points <= 59) {
		std::cout << 2 << std::endl;
	}
	else if (points <= 69) {
		std::cout << 3 << std::endl;
	}
	else if (points <= 79) {
		std::cout << 4 << std::endl;
	}
	else if (points <= 89) {
		std::cout << 5 << std::endl;
	}
	else if (points <= 100) {
		std::cout << 6 << std::endl;
	}
	else {
		std::cout << "Incredible!" << std::endl;
	}
}
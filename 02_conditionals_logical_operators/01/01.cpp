#include <iostream>

int main(void)
{
	int x;
	int y;

	std::cin >> x >> y;

	int diff = x - y;
	if (diff < 0) {
		std::cout << -diff << std::endl;
	}
	else {
		std::cout << diff << std::endl;
	}
}

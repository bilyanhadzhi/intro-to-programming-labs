#include <iostream>

int main(void)
{
	int a, b, c;
	std::cin >> a >> b >> c;

	
	if (a + b <= c || a + c <= b || b + c <= a) {
		std::cout << "Invalid sides" << std::endl;
		return 1;
	}

	if (a == b && b == c) {
		std::cout << "equilateral" << std::endl;
	}
	else if (a == b || b == c || c == a) {
		std::cout << "isosceles" << std::endl;
	}
	else {
		std::cout << "scalene" << std::endl;
	}
}
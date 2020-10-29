#include <iostream>

int main(void)
{
	int num1, num2, num3;
	std::cin >> num1 >> num2 >> num3;

	if (num1 > num2) {
		if (num1 > num3) {
			std::cout << num1 << std::endl;
		}
		else {
			std::cout << num3 << std::endl;
		}
	}
	else {
		if (num2 > num3) {
			std::cout << num2 << std::endl;
		}
		else {
			std::cout << num3 << std::endl;
		}
	}
}

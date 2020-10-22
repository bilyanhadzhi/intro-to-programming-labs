#include <iostream>

int main(void)
{
	int n;
	std::cin >> n;

	bool result = true;

	// Остатък при деление на 10 винаги връща последната цифра
	int curr_digit = n % 10;
	if (n % curr_digit != 0) {
		result = false;
	}

	// Целочислено деление на 10 винаги премахва последната цифра
	n /= 10; // n = n / 10;
	curr_digit = n % 10;

	if (n % curr_digit != 0) {
		result = false;
	}

	n /= 10;
	curr_digit = n % 10;

	if (n % curr_digit != 0) {
		result = false;
	}

	std::cout << result << std::endl;
}
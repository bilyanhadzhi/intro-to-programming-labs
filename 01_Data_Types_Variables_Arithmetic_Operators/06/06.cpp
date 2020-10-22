#include <iostream>

int main(void)
{
	int num1;
	int num2;

	std::cin >> num1 >> num2;

	double avg = (num1 + num2) / 2.0; // for the result of a division to be a floating-point number,
									  // at least one of the operands needs to be a floating-point number

	std::cout << avg << std::endl;
}
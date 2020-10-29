#include <iostream>

int main(void)
{
	char lowercase;
	std::cin >> lowercase;

	int difference = 'a' - 'A';
	char result = lowercase - difference;

	std::cout << result << std::endl;
}

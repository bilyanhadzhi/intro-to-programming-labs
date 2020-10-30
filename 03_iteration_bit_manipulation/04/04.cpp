#include <iostream>

int main(void)
{
	int n;
	std::cin >> n;

	int prev_num, curr_num;
	bool consecutive_exist = false;

	std::cin >> curr_num;
		
	for (int i = 1; i < n; i++) {
		prev_num = curr_num;
		std::cin >> curr_num;

		if (prev_num == curr_num) {
			consecutive_exist = true;
		}
	}

	std::cout << (consecutive_exist ? "yes" : "no") << std::endl;
}
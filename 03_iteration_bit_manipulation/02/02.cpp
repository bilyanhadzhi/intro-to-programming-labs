#include <iostream>

int main()
{
	int curr_num;
	int max_even = -1, max_odd = -1;
	int num_count = 0;
	int num_sum = 0;

	std::cin >> curr_num;

	while (curr_num != 0) {

		if (curr_num % 2 == 0 && curr_num > max_even) {
			max_even = curr_num;
		}
		else if (curr_num > max_odd) {
			max_odd = curr_num;
		}

		num_sum += curr_num; // num_sum = num_sum + curr_num
		num_count++; // num_count = num_count + 1

		std::cin >> curr_num;
	}


	if (max_even == -1) {
		std::cout << "No even numbers" << std::endl;
	}
	else {
		std::cout << "Max even: " << max_even << std::endl;
	}
	

	if (max_odd == -1) {
		std::cout << "No odd numbers" << std::endl;
	}
	else {
		std::cout << "Max odd: " << max_odd << std::endl;
	}
	
	std::cout << "Sum: " << num_sum << std::endl;

	if (num_count == 0) {
		std::cout << "No average of 0 numbers" << std::endl;
	}
	else {
		double avg = num_sum / num_count;
		std::cout << "Average: " << avg << std::endl;
	}
	
}
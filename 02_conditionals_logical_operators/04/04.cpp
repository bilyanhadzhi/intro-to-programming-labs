#include <iostream>

/*Една година е високосна, ако:
- се дели на 4, но не се дели на 100
- се дели на 400
*/

int main(void)
{
	int year;
	std::cin >> year;

	if (!std::cin) {	// пример за проверяване за вход на невалидни данни
		std::cout << "Invalid input" << std::endl;
	}

	bool is_leap_year = false;

	// 1-ви вариант
	// is_leap_year = (year % 400 == 0) || (year % 4 == 0 && !(year % 100 == 0));

	// 2-ри вариант
	if (year % 400 == 0) {
		is_leap_year = true;
	}
	else {
		if (year % 4 == 0) {
			if (year % 100 != 0) {
				is_leap_year = true;
			}
			else {
				is_leap_year = false;
			}
		}
		else {
			is_leap_year = false;
		}
	}

	std::cout << is_leap_year << std::endl;
}

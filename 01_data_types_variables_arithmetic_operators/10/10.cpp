#include <iostream>

int main(void)
{
	int a;
	int b;

	std::cin >> a >> b;

	// 1st way
	int tmp = a;
	a = b;
	b = tmp; // tmp still holds a copy of a's original value

	std::cout << "After 1st swap: " << a << " " << b << std::endl;

	// 2nd way
	a += b;		    // a is now (a + b)
	b = a - b;  	// (a + b) - b, i.e. b is now what a was
	a -= b;		    // and we just remove b's new value from (a + b)

	std::cout << "After 2nd swap: " << a << " " << b << std::endl;
}

#include <iostream>

int main(void)
{
	int x1, y1;
	int x2, y2;
	int x3, y3;

	std::cin >> x1 >> y1
		>> x2 >> y2
		>> x3 >> y3;

	// Разглеждаме ъгловите коефициенти на т. 1 и 2 и т. 1 и 3 съответно
	// !Умножавайки числителя по 1.0, осигуряваме, че резултатът ще е от тип double
	double slope1 = 1.0 * (y2 - y1) / (x2 - x1);
	double slope2 = 1.0 * (y3 - y1) / (x3 - x1);

	std::cout << slope1 << " " << slope2 << std::endl;
	std::cout << (slope1 == slope2) << std::endl;
}
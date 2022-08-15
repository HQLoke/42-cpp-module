#include "Point.hpp"

bool	test(float x1, float y1, float x2, float y2, float x3, float y3, float px, float py)
{
	Point A(x1, y1);
	Point B(x2, y2);
	Point C(x3, y3);
	Point random(px, py);

	return (bsp(A, B, C, random));
}

int		main(void)
{
	std::cout << test(0, 0, 20, 0, 10, 30, 10, 15) << std::endl; // 1
	std::cout << test(0, 0, 20, 0, 10, 30, 20, 0) << std::endl; // 0
	std::cout << test(3.15, 6.1, 20.5, 12.7, 11.3, -10.6, 6.2, 4.2) << std::endl; // 1
	std::cout << test(3.15, 6.1, 20.5, 12.7, 11.3, -10.6, -50, 4.2) << std::endl; // 0
	std::cout << test(3.15, 6.1, 20.5, 12.7, 11.3, -10.6, 4.1, 4.2) << std::endl; // 1
	return (0);
}

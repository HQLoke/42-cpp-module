#include "Point.hpp"

float	sign	( Point p1, Point p2, Point p3 )
{
	return ((p1.getXFloat() - p3.getXFloat()) * (p2.getYFloat() - p3.getYFloat()) -
			(p2.getXFloat() - p3.getXFloat()) * (p1.getYFloat() - p3.getYFloat()));
}

bool	bsp		( Point const a, Point const b, Point const c, Point const point )
{
	float	d1, d2, d3;
	bool	has_neg, has_pos;

	d1 = sign(point, a, b);
	d2 = sign(point, b, c);
	d3 = sign(point, c, a);

	has_neg = (d1 <= 0) || (d2 <= 0) || (d3 <= 0);
	has_pos = (d1 >= 0) || (d2 >= 0) || (d3 >= 0);

	return !(has_neg && has_pos);
}

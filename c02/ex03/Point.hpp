#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include <string>
# include "Fixed.hpp"

class Point
{

	public:

		Point();
		Point( float const x, float const y );
		Point( Point const & src );
		~Point();

		Point			&	operator=	( Point const & rhs );
		
		float				getXFloat();
		float				getYFloat();

	private:

		Fixed	const	_x;
		Fixed	const	_y;

};

bool	bsp		( Point const a, Point const b, Point const c, Point const point );

#endif /* *********************************************************** POINT_H */

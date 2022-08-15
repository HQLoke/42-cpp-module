#include "Point.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Point::Point() : _x(0), _y(0)
{
}

Point::Point( float const x, float const y ) : _x(x), _y(y)
{
}

Point::Point( const Point & src ) : _x(src._x), _y(src._y)
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Point::~Point()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Point &				Point::operator=( Point const & rhs )
{
	if ( this != &rhs )
	{
		*this = rhs;
	}
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

float	Point::getXFloat()
{
	return (this->_x.toFloat());
}

float	Point::getYFloat()
{
	return (this->_y.toFloat());
}

/* ************************************************************************** */

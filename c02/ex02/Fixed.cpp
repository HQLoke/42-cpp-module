#include "Fixed.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Fixed::Fixed	() : _fixedPointVal(0)
{}

Fixed::Fixed	( int const int_val )
{
	_fixedPointVal = int_val << _sFracBits;
}

Fixed::Fixed	( float const f_val )
{
	float	shifted_f_val;

	shifted_f_val = f_val * pow(2, _sFracBits);
	_fixedPointVal = roundf(shifted_f_val);
}

Fixed::Fixed	( const Fixed & src )
{
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Fixed::~Fixed()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Fixed &				Fixed::operator=	( Fixed const & rhs )
{
	if ( this != &rhs )
	{
		this->_fixedPointVal = rhs.getRawBits();
	}
	return *this;
}

bool				Fixed::operator>	( Fixed const & rhs )
{
	if (_fixedPointVal > rhs._fixedPointVal)
		return (true);
	return (false);
}

bool				Fixed::operator<	( Fixed const & rhs )
{
	if (_fixedPointVal < rhs._fixedPointVal)
		return (true);
	return (false);
}

bool				Fixed::operator>=	( Fixed const & rhs )
{
	if (_fixedPointVal >= rhs._fixedPointVal)
		return (true);
	return (false);
}

bool				Fixed::operator<=	( Fixed const & rhs )
{
	if (_fixedPointVal <= rhs._fixedPointVal)
		return (true);
	return (false);
}

bool				Fixed::operator==	( Fixed const & rhs )
{
	if (_fixedPointVal == rhs._fixedPointVal)
		return (true);
	return (false);
}

bool				Fixed::operator!=	( Fixed const & rhs )
{
	if (_fixedPointVal != rhs._fixedPointVal)
		return (true);
	return (false);
}

Fixed &				Fixed::operator+	( Fixed const & rhs )
{
	(*this)._fixedPointVal += rhs._fixedPointVal;
	return (*this);
}

Fixed &				Fixed::operator-	( Fixed const & rhs )
{
	(*this)._fixedPointVal -= rhs._fixedPointVal;
	return (*this);
}

Fixed &				Fixed::operator*	( Fixed const & rhs )
{
	long	tmp;
	
	tmp = (this->_fixedPointVal * rhs._fixedPointVal) >> _sFracBits;
	this->_fixedPointVal = (int)tmp;
	return (*this);
}

Fixed &				Fixed::operator/	( Fixed const & rhs )
{
	this->_fixedPointVal = (this->_fixedPointVal << _sFracBits) / rhs._fixedPointVal;
	return (*this);
}

Fixed &				Fixed::operator++	()
{
	_fixedPointVal++;
	return *this;
}

Fixed				Fixed::operator++	( int )
{
	Fixed temp;

	temp = *this;
	++*this;
	return temp;	
}

Fixed &				Fixed::operator--	()
{
	_fixedPointVal--;
	return *this;
}

Fixed				Fixed::operator--	( int )
{
	Fixed temp;

	temp = *this;
	--*this;
	return temp;
}

std::ostream &			operator<<( std::ostream & o, Fixed const & i )
{
	o << i.toFloat();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

float				Fixed::toFloat		( void ) const
{
	float f_val;
	
	f_val = getRawBits() / pow(2, _sFracBits);
	return (f_val);	
}

int					Fixed::toInt		( void ) const
{
	int	int_val;

	int_val = getRawBits() >> _sFracBits;
	return (int_val);
}

Fixed &				Fixed::min			( Fixed & lhs, Fixed & rhs )
{
	if (lhs._fixedPointVal < rhs._fixedPointVal)
		return (lhs);
	return (rhs);
}

Fixed &				Fixed::max			( Fixed & lhs, Fixed & rhs )
{
	if (lhs._fixedPointVal > rhs._fixedPointVal)
		return (lhs);
	return (rhs);
}

Fixed const &		Fixed::min			( Fixed const & lhs, Fixed const & rhs )
{
	if (lhs._fixedPointVal < rhs._fixedPointVal)
		return (lhs);
	return (rhs);
}

Fixed const &		Fixed::max			( Fixed const & lhs, Fixed const & rhs )
{
	if (lhs._fixedPointVal > rhs._fixedPointVal)
		return (lhs);
	return (rhs);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

int					Fixed::getRawBits	( void ) const
{
	return (this->_fixedPointVal);
}

void				Fixed::setRawBits	( int const raw )
{
	this->_fixedPointVal = raw;
}

/* ************************************************************************** */

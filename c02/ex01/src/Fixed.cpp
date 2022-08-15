#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(int const int_val)
{
	std::cout << "Int constructor called\n";
	this->_fixedPointVal = int_val << _sFracBits;
}

/*
 * 42.5 (float) = 101010.10000000 (fixed-point with 8 fractional bits)
 * Bitwise left shift N times = multiplying by 2^N	(42.5 * 2^8 = 10880)
 * Bitwise right shift N times = dividing by 2^N
 * Since precision is 8 fractional bits only, we need to round off to the nearest int.
 */ 
Fixed::Fixed(float const f_val)
{
	std::cout << "Float constructor called\n";
	float	shift_val;

	shift_val = f_val * pow(2, _sFracBits);
	this->_fixedPointVal = roundf(shift_val);
}

Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy constructor called\n";
	this->_fixedPointVal = src.getRawBits();
}

Fixed& Fixed::operator= (const Fixed & rhs)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &rhs)
		this->_fixedPointVal = rhs.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int		Fixed::getRawBits(void) const
{
	return (this->_fixedPointVal);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixedPointVal = raw;
}

float	Fixed::toFloat(void) const
{
	float	ret;
	
	ret = Fixed::getRawBits() / pow(2, this->_sFracBits);
	return (ret);	
}

int		Fixed::toInt(void) const
{
	int		ret;

	ret = Fixed::getRawBits() >> this->_sFracBits;
	return (ret);
}

/*
 * These operators must be overloaded as a global function.
 */
std::ostream & operator<< (std::ostream & o, Fixed const & fixed)
{
	o << fixed.toFloat();
	return (o);
}

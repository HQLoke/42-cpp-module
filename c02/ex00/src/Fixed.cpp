#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	this->_fixedPointVal = 0;
}

Fixed::Fixed(const Fixed & src)
{
	std::cout << "Copy constructor called\n";
	this->_fixedPointVal = src.getRawBits();
}

Fixed &		Fixed::operator= (const Fixed & rhs)
{
	std::cout << "Copy assignment operator called\n";
	if ( this != &rhs )
	{
		this->_fixedPointVal = rhs.getRawBits();
	}
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return (this->_fixedPointVal);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixedPointVal = raw;
}

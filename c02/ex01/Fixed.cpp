/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 21:03:43 by hloke             #+#    #+#             */
/*   Updated: 2022/07/13 14:04:10 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//? Default constructor, copy constructor, copy assignment operator & destructor

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int int_val)
{
	std::cout << "Int constructor called\n";
	_fixedPointVal = int_val << _sFracBits;
}

/*
 * 42.5 (float) = 101010.10000000 (fixed-point with 8 fractional bits)
 * Bitwise left shift N times = multiplying by 2^N	(42.5 * 2^8 = 10880)
 * Bitwise right shift N times = dividing by 2^N
 * Since precision is 8 fractional bits only, we need to round off to the nearest int.
 */ 
Fixed::Fixed(const float f_val)
{
	std::cout << "Float constructor called\n";
	float	shift_val;

	shift_val = f_val * pow(2, _sFracBits);
	_fixedPointVal = roundf(shift_val);
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called\n";
	this->_fixedPointVal = fixed.getRawBits();
}

Fixed& Fixed::operator= (const Fixed &fixed)
{
	std::cout << "Copy assignment operator called\n";
	if (this == &fixed)
		return (*this);
	this->_fixedPointVal = fixed.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

//? Public methods

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
	float ret;
	
	ret = getRawBits() / pow(2, _sFracBits);
	return (ret);	
}

int		Fixed::toInt(void) const
{
	int	ret;

	ret = getRawBits() >> _sFracBits;
	return (ret);
}

//? Private methods


//? External functions

/*
 * These operators must be overloaded as a global function.
 * And must make them friend to access private data members of the class.
 */
std::ostream& operator<< (std::ostream &out, const Fixed &fixed)
{
	float ret;

	ret = fixed._fixedPointVal / pow(2, fixed._sFracBits);
	out << ret;
	return (out);
}

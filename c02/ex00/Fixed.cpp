/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 14:06:30 by hloke             #+#    #+#             */
/*   Updated: 2022/07/13 09:36:42 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//? Default constructor, copy constructor, copy assignment operator & destructor

Fixed::Fixed() : _fixedPointVal(0)
{
	std::cout << "Default constructor called\n";
}

/*
 * Prevent from using *this = src as it causes stack overflow.
 */
Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called\n";
	this->_fixedPointVal = fixed.getRawBits();
}

Fixed& Fixed::operator= (const Fixed &fixed)
{
	std::cout << "Copy assignment operator called\n";
	if (this == &fixed)
		return *this;
	this->_fixedPointVal = fixed.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}
		
//? Public methods

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return _fixedPointVal;
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixedPointVal = raw;
}

//? Private methods


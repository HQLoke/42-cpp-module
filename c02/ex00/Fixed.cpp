/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 14:06:30 by hloke             #+#    #+#             */
/*   Updated: 2022/07/12 20:57:17 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//? Default constructor, copy constructor, copy assignment operator & destructor

Fixed::Fixed() : _numValue(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &f)
{
	std::cout << "Copy constructor called\n";
	this->_numValue = f.getRawBits();
}

Fixed& Fixed::operator= (const Fixed &f)
{
	std::cout << "Copy assignment operator called\n";
	if (this == &f)
		return *this;
	this->_numValue = f.getRawBits();
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
	return _numValue;
}

void	Fixed::setRawBits(int const raw)
{
	this->_numValue = raw;
}

//? Private methods


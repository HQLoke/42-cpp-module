/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 21:04:50 by hloke             #+#    #+#             */
/*   Updated: 2022/07/13 14:03:50 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <cmath>
# include <iostream>

/*
 * Friend is a function that can access private, protected and public members
 * of a class.
 */
class Fixed
{
	public:
		Fixed();
		Fixed(const int int_val);
		Fixed(const float f_val);
		Fixed(const Fixed &fixed);
		Fixed& operator= (const Fixed &fixed);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		friend std::ostream& operator<< (std::ostream &out, const Fixed &fixed);

	private:
		int					_fixedPointVal;
		static const int	_sFracBits = 8;
};

std::ostream& operator<< (std::ostream &out, const Fixed &fixed);

# endif

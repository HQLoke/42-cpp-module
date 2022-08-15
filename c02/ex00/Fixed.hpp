/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 14:06:59 by hloke             #+#    #+#             */
/*   Updated: 2022/07/13 09:35:48 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &fixed);
		Fixed& operator= (const Fixed &fixed);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private:
		int					_fixedPointVal;
		static const int	_sFracBits = 8;
};

# endif
#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed
{
	public:
		Fixed();
		Fixed(const Fixed & src);
		Fixed &		operator= (const Fixed & rhs);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private:
		int					_fixedPointVal;
		static int const	_sFracBits = 8;
};

# endif

#ifndef FIXED_HPP
# define FIXED_HPP

# include <cmath>
# include <iostream>

class	Fixed
{
	public:
		Fixed();
		Fixed(int const int_val);
		Fixed(float const f_val);
		Fixed(Fixed const & src);
		Fixed & operator= (Fixed const & rhs);
		~Fixed();
		float	toFloat(void) const;
		int		toInt(void) const;
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private:
		int					_fixedPointVal;
		static const int	_sFracBits = 8;
};

std::ostream &	operator<< (std::ostream & o, Fixed const & fixed);

# endif

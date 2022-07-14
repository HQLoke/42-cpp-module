#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed
{

	public:

		Fixed();
		Fixed( int const int_val );
		Fixed( float const f_val );
		Fixed( Fixed const & src );
		~Fixed();

		Fixed &		operator=	( Fixed const & rhs );
		bool		operator>	( Fixed const & rhs );
		bool		operator<	( Fixed const & rhs );
		bool		operator>=	( Fixed const & rhs );
		bool		operator<=	( Fixed const & rhs );
		bool		operator==	( Fixed const & rhs );
		bool		operator!=	( Fixed const & rhs );
		Fixed 		operator+	( Fixed const & rhs );
		Fixed 		operator-	( Fixed const & rhs );
		Fixed 		operator*	( Fixed const & rhs );
		Fixed 		operator/	( Fixed const & rhs );
		Fixed &		operator++	();
		Fixed		operator++	( int );
		Fixed &		operator--	();
		Fixed		operator--	( int );

		float					toFloat	( void ) const;
		int						toInt	( void ) const;
		static Fixed &			min		( Fixed & lhs, Fixed & rhs );
		static Fixed &			max		( Fixed & lhs, Fixed & rhs );
		static Fixed const & 	min		( const Fixed & lhs, const Fixed & rhs );
		static Fixed const & 	max		( const Fixed & lhs, const Fixed & rhs );

		int			getRawBits	( void ) const;
		void		setRawBits	( int const raw );

	private:

		int					_fixedPointVal;
		static const int	_sFracBits = 8;

};

std::ostream &			operator<<( std::ostream & o, Fixed const & i );

#endif /* *********************************************************** FIXED_H */

#ifndef A_HPP
# define A_HPP

# include <iostream>
# include <string>
# include "Base.hpp"

class A : public Base
{
	public:
		A();
		A( A const & src );
		~A();

		A &		operator=( A const & rhs );

	private:

};

std::ostream &			operator<<( std::ostream & o, A const & i );

#endif /* *************************************************************** A_H */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{

	public:

		FragTrap();
		FragTrap(std::string const name);
		FragTrap( FragTrap const & src );
		~FragTrap();

		FragTrap &		operator=		( FragTrap const & rhs );

		void			attack			( const std::string & target );
		void			highFivesGuys	(void);

	private:

};

// std::ostream &			operator<<( std::ostream & o, FragTrap const & i );

#endif /* ******************************************************** FragTrap_H */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include <string>
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	public:
		DiamondTrap();
		DiamondTrap( std::string const name );
		DiamondTrap( DiamondTrap const & src );
		~DiamondTrap();
		DiamondTrap &		operator=( DiamondTrap const & rhs );
		void				attack( const std::string & target );
		void				whoAmI();
		std::string			getName() const;

	private:
		std::string			_name;
};

#endif /* ***************************************************** DIAMONDTRAP_H */

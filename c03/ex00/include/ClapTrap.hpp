#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap( std::string const name );
		ClapTrap( ClapTrap const & src );
		~ClapTrap();

		ClapTrap &		operator=( ClapTrap const & rhs );

		void			attack( std::string const & target );
		void			takeDamage( unsigned int amount );
		void			beRepaired( unsigned int amount );

		std::string 	getName			() const;
		int				getHitPoints	() const;
		int				getEnergyPoints	() const;
		int				getAttackDamage	() const;

	private:
		std::string		_name;
		int				_hitPoints;
		int				_energyPoints;
		int				_attackDamage;
};

std::ostream &			operator<<( std::ostream & o, ClapTrap const & i );

#endif /* ******************************************************** CLAPTRAP_H */

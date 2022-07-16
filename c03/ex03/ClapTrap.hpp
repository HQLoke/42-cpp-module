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

		ClapTrap &		operator=		( ClapTrap const & rhs );

		void			attack			( const std::string & target );
		void			takeDamage		( unsigned int amount );
		void			beRepaired		( unsigned int amount );

		std::string 	getName			()	const;
		int				getHitPoints	()	const;
		int				getEnergyPoints	()	const;
		int				getAttackDamage	()	const;
		void			setName			( std::string const name );
		void			setHitPoints	( int hitPoints );
		void			setEnergyPoints	( int energyPoints );
		void			setAttackDamage	( int attackDamage );

	/*
	 * Protected access specifier is used here, because without it FragTrap and ScavTrap
	 * are manipulating the same set of variables at initialization.
	 * This makes sure that both FragTrap and ScavTrap have their own unique stats values.
	 */
	protected:

		std::string		_name;
		int				_hitPoints;
		int				_energyPoints;
		int				_attackDamage;

};

// std::ostream &			operator<<( std::ostream & o, ClapTrap const & i );

#endif /* ******************************************************** CLAPTRAP_H */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"

class AMateria;

class ICharacter
{

	public:

		ICharacter();
		ICharacter( ICharacter const & src );
		virtual ~ICharacter();

		ICharacter &		operator=( ICharacter const & rhs );

		virtual void				equip	( AMateria *m ) = 0;
		virtual void				unequip	( int idx ) = 0;
		virtual void				use		( int idx, ICharacter & target ) = 0;
		virtual	std::string	const & getName	() const = 0;

	private:
		std::string	_name;

};

std::ostream &			operator<<( std::ostream & o, ICharacter const & i );

#endif /* ****************************************************** ICHARACTER_H */

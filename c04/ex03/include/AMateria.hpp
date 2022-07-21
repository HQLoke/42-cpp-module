#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{

	public:

		AMateria();
		AMateria( std::string const & type );
		AMateria( AMateria const & src );
		virtual ~AMateria() = 0;

		AMateria &			operator=( AMateria const & rhs );

		virtual AMateria	*clone	() const = 0;
		virtual void		use		( ICharacter & target ) = 0;
		std::string const &	getType	() const;

	protected:
		std::string			_type;

	private:

};

std::ostream &			operator<<( std::ostream & o, AMateria const & i );

#endif /* ******************************************************** AMATERIA_H */

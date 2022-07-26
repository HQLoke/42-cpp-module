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
		void				setType ( std::string type );
				
	private:
	
		std::string			_type;

};

#endif /* ******************************************************** AMATERIA_H */

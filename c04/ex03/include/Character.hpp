#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Character : public ICharacter
{

	public:

		Character();
		Character( std::string const & name );
		Character( Character const & src );
		~Character();

		Character &		operator=( Character const & rhs );

		void				equip	( AMateria *m );
		void				unequip	( int idx );
		void				use		( int idx, ICharacter & target );
		std::string	const &	getName	() const;
		void				setName ( std::string name );

	private:
		
		AMateria		*_materias[4];
		std::string		_name;
		int				_numEquip;

};

#endif /* ******************************************************* CHARACTER_H */

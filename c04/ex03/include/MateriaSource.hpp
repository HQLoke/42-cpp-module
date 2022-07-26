#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include <string>
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{

	public:

		MateriaSource();
		MateriaSource( MateriaSource const & src );
		~MateriaSource();

		MateriaSource &		operator=( MateriaSource const & rhs );

		AMateria	*createMateria( std::string const & mat );
		void		learnMateria( AMateria *mat );

	private:

		AMateria	*_learnedMateria[4];
		int			_numMateria;

};


#endif /* *************************************************** MATERIASOURCE_H */

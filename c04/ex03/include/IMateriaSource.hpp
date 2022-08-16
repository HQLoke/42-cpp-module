#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"

class IMateriaSource
{
	public:
		virtual ~IMateriaSource(){};

		virtual	AMateria	*createMateria	( std::string const & type ) = 0;
		virtual void		learnMateria	( AMateria *m ) = 0;

	private:

};

#endif /* ************************************************** IMATERIASOURCE_H */

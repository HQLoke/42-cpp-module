#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{

	public:

		Animal();
		Animal( Animal const & src );
		~Animal();

		Animal &		operator=( Animal const & rhs );
		
		virtual void	makeSound()	const;
		std::string		getType()	const;
		void			setType( std::string type );

	protected:
		std::string		_type;

	private:

};

std::ostream &			operator<<( std::ostream & o, Animal const & i );

#endif /* ********************************************************** ANIMAL_H */

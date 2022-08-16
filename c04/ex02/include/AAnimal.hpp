#ifndef AAnimal_HPP
# define AAnimal_HPP

# include <iostream>
# include <string>

class AAnimal
{
	public:
		AAnimal();
		AAnimal( AAnimal const & src );
		virtual ~AAnimal();

		AAnimal &		operator=( AAnimal const & rhs );
		virtual void	makeSound()	const = 0;
		std::string		getType()	const;
		void			setType( std::string type );

	protected:
		std::string		_type;

	private:

};

std::ostream &			operator<<( std::ostream & o, AAnimal const & i );

#endif /* ********************************************************** AAnimal_H */

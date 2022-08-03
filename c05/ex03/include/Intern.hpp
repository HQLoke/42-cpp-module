#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{

	public:

		Intern();
		~Intern();

		Form	*makeForm( std::string formName, std::string target );

	private:

};

#endif /* ********************************************************** INTERN_H */

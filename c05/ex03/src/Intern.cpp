#include "Intern.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern()
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/


/*
** --------------------------------- METHODS ----------------------------------
*/

Form *		Intern::makeForm( std::string formName, std::string target )
{
	std::string	form[] = {"presidential pardon", "robotomy request", 
						  "shrubbery creation"};
	const int	size = sizeof(form) / sizeof(form[0]);
	Form		*newForm;
	int			i;

	newForm = NULL;
	i = -1;
	while (++i < size)
	{
		if (formName == form[i])
			break ;
	}
	switch (i)
	{
		case 0:
			newForm = new PresidentialPardonForm(target);
			break ;
	
		case 1:
			newForm = new RobotomyRequestForm(target);
			break ;

		case 2:
			newForm = new ShrubberyCreationForm(target);
			break ;
	}
	if (i < size)
		std::cout << "Intern has created <" << form[i] << "> form\n";
	else
		std::cout << "Intern does not know which form to create\n";
	return (newForm);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */

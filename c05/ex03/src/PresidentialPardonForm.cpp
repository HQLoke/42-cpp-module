#include "PresidentialPardonForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PresidentialPardonForm::PresidentialPardonForm()
: Form("PresidentialPardonForm", false, 25, 5)
{
	this->_target = "DEFAULT_TARGET";
}

PresidentialPardonForm::PresidentialPardonForm( std::string target )
: Form("PresidentialPardonForm", false, 25, 5)
{
	this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PresidentialPardonForm::~PresidentialPardonForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/



/*
** --------------------------------- METHODS ----------------------------------
*/

bool	PresidentialPardonForm::execute( Bureaucrat const & executor ) const
{
	bool ret;

	ret = Form::checkRequirements(executor);
	if (ret == true)
	{
		std::cout << "All hail the mighty king of Babylon!\n"
		<< "A new decree has been issued today:\n"
		<< this->_target << " has been pardoned by Zaphod Beeblebrox\n"
		<< "Now get up and GTFO of the king's palace\n";
	}
	return (ret);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */

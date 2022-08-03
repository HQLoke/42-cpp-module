#include "RobotomyRequestForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm()
: Form("RobotomyRequestForm", false, 72, 45)
{
	this->_target = "DEFAULT_TARGET";
}

RobotomyRequestForm::RobotomyRequestForm( std::string target )
: Form("RobotomyRequestForm", false, 72, 45)
{
	this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/



/*
** --------------------------------- METHODS ----------------------------------
*/

bool	RobotomyRequestForm::execute( Bureaucrat const & executor ) const
{
	bool ret;

	ret = Form::checkRequirements(executor);
	if (ret == true)
	{
		srand(time(0));
		std::cout << "My name is Brainny the Brain Surgeon\n"
		<< "The thing between your ears is mine muahahaha!\n"
		<< "Brrrrr......brrrrr......brrrrr......\n";
		if (rand() % 2 == 0)
		{
			std::cout << "Yes! A new brain has been added to my collection\n"
			<< this->_target << " has been robotomized successfully!\n";
		}
		else
		{
			std::cout << "No! I failed to get my squishy little brain from "
			<< this->_target << std::endl;
		}
	}
	return (ret);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */

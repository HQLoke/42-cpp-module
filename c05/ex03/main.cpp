#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	Intern	pam;
	Form	*formZ;

	formZ = pam.makeForm("presidential pardon", "dwight");
	if (formZ != NULL)
		std::cout << *formZ << std::endl;
	delete formZ;

	formZ = pam.makeForm("robotomy request", "dwight");
	if (formZ != NULL)
		std::cout << *formZ << std::endl;
	delete formZ;

	formZ = pam.makeForm("shrubbery creation", "dwight");
	if (formZ != NULL)
		std::cout << *formZ << std::endl;
	delete formZ;

	formZ = pam.makeForm("I want to fire someone", "dwight");
	if (formZ != NULL)
		std::cout << *formZ << std::endl;
	delete formZ;
	
	return (0);
}

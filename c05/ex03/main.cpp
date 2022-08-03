#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	Intern nani;
	Form *heh;

	heh = nani.makeForm("presidential pardon", "bob");
	// std::cout << *heh;
	delete heh;
	return (0);
}

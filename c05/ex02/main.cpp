#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	ShrubberyCreationForm form("What");
	Bureaucrat person("James", 1);
	Bureaucrat person2("Hoho", 1);

	form.beSigned(person);
	person2.executeForm(form);
	return (0);
}

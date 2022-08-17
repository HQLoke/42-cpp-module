#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	PresidentialPardonForm	formA("ALIBABA");
	RobotomyRequestForm		formB("BRAINIAC");
	ShrubberyCreationForm	formC("EARTH4EVER");

	Bureaucrat	microboss("James", 24);
	Bureaucrat	miniboss("Michael", 3);

	std::cout << "|-------------------------------------------|" << std::endl
			  << "|       Presidential form signed by    	  |" << std::endl
			  << "|          low grade bureaucrat             |" << std::endl
			  << "|-------------------------------------------|" << std::endl;
	std::cout << formA << std::endl;
	formA.beSigned(microboss);
	microboss.executeForm(formA);
	miniboss.signForm(formA);
	std::cout << formA << std::endl;
	formA.execute(microboss);
	formA.execute(miniboss);

	std::cout << "|---------------------------------------------------|" << std::endl
		      << "|       Execute robotomy form without signing       |" << std::endl
			  << "|---------------------------------------------------|" << std::endl;
	std::cout << formB << std::endl;
	formB.execute(microboss);
	formB.execute(miniboss);
	formB.beSigned(microboss);
	formB.beSigned(miniboss);
	std::cout << formB << std::endl;
	formB.execute(miniboss);

	std::cout << "|--------------------------------------------|" << std::endl
		      << "|       Execute shrubbery form normally      |" << std::endl
			  << "|--------------------------------------------|" << std::endl;
	std::cout << formC << std::endl;
	formC.beSigned(microboss);
	formC.execute(miniboss);
	formC.beSigned(microboss);
	formC.execute(miniboss);
	
	return (0);
}

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat	assistant("Karen", 42);
	Bureaucrat	manager("Pepper", 6);

	Form		carform("car license registration", false, 13, 13);
	// Form		trial1("car license registration", 0, -1, 1);  // GradeTooHigh
	// Form		trial2("car license registration", 0, 151, 1); // GradeTooLow
	// Form		trial3("car license registration", 0, 1, -1);  // GradeTooHigh
	// Form		trial4("car license registration", 0, 1, 151); // GradeTooLow

	std::cout << "|-----------------------|" << std::endl;
	std::cout << "|       Assistant       |" << std::endl;
	std::cout << "|-----------------------|" << std::endl;
	std::cout << assistant << std::endl;
	std::cout << carform << std::endl;
	assistant.signForm(carform);
	std::cout << carform << std::endl;
	

	std::cout << "|--------------------|" << std::endl;
	std::cout << "|       Manager      |" << std::endl;
	std::cout << "|--------------------|" << std::endl;
	std::cout << manager << std::endl;
	std::cout << carform << std::endl;
	manager.signForm(carform);
	std::cout << carform << std::endl;
	
	return (0);
}

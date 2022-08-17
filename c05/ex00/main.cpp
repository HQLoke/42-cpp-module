#include "Bureaucrat.hpp"

int main(void)
{
	// Bureaucrat a("NAJIB", -44444); // GradeTooHighException
	// Bureaucrat b("ROSMAH", 44444); // GradeTooLowException
	Bureaucrat c("NOBODY", 42);

	c.setGrade(10);
	std::cout << "Current grade: " << c.getGrade() << std::endl;
	c.gradeIncrement(9);
	std::cout << "Current grade: " << c.getGrade() << std::endl;

	try
	{
		c.gradeIncrement(1);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		c.gradeDecrement(150);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "Current grade: " << c.getGrade() << std::endl;

	return (0);
}

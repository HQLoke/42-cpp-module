#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat unknown("Bob", 55);
	Bureaucrat stranger("Frank", 1);
	Form sample("Car registration", false, 5, 5);

	std::cout << unknown << sample;
	unknown.signForm(sample);
	std::cout << unknown << sample;

	std::cout << "\n\n";

	std::cout << stranger << sample;
	stranger.signForm(sample);
	std::cout << stranger << sample;
	return (0);
}

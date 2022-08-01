#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat wtf(1, "WTF");
	wtf.setGrade(10);
	wtf.gradeIncrement(9);
	std::cout << wtf.getGrade() << std::endl;
	return (0);
}

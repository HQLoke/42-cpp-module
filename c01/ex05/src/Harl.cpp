#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

/*
 * Must explicitly use scope resolution operator (::) for name of member function
 * when taking its address.
 * https://stackoverflow.com/questions/52934718/c-calling-functions-from-an-array-of-function-pointers
 */
void	Harl::complain(std:: string level)
{
	const char	*levels[] = {"DEBUG", "ERROR", "INFO", "WARNING"};
	const int	num_level = sizeof(levels) / sizeof(levels[0]);
	void		(Harl::*func[])(void) = {&Harl::_debug, &Harl::_error, &Harl::_info,
										 &Harl::_warning};
	int			i;

	i = -1;
	while (++i < num_level)
	{
		if (level.compare(levels[i]) == 0)
		{
			(this->*func[i])();
			return ;
		}
	}
	if (i == num_level)
		std::cout << "????? WTF ARE YOU TALKING ABOUT ?????\n";
}

void	Harl::_debug(void)
{
	std::cout << "I love having extra bacon for my 7XL=double cheese-triple-"
			  << "pickle-special-ketchup burger. I really do!\n";
}

void	Harl::_info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You "
	          << "didn't put enough bacon in my burger! If you did, I wouldn't "
			  << "be asking for more!\n";
}

void	Harl::_warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I've been "
			  << "coming for years whereas you started working here since last "
			  << "month\n";
}

void	Harl::_error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

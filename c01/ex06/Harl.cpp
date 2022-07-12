/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:32:31 by hloke             #+#    #+#             */
/*   Updated: 2022/07/12 12:23:54 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

//? Constructor & Destructor
Harl::Harl(){}
Harl::~Harl(){}

//? Public Methods
void Harl::complain(std::string level)
{
	const char	*levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	const int	num_level = sizeof(levels) / sizeof(levels[0]);
	int			i;

	i = -1;
	while (++i < num_level)
	{
		if (level.compare(levels[i]) == 0)
			break ;
	}
	switch (i)
	{
		case 0:
			_debug();
		case 1:
			_info();
		case 2:
			_warning();
		case 3:
			_error();
		default:
			;
	}
	if (i == num_level)
		std::cout << "[ Probably complaining about insignificant problems. ]\n";
}

//? Private Methods

void Harl::_debug(void)
{
	std::cout << "[ DEBUG ]\n";
	std::cout << "I love having extra bacon for my 7XL=double cheese-triple-"
	          << "pickle-special-ketchup burger. I really do!\n\n";
}

void Harl::_info(void)
{
	std::cout << "[ INFO ]\n";
	std::cout << "I cannot believe adding extra bacon costs more money.\n";
	std::cout << "You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n\n";
}

void Harl::_warning(void)
{
	std::cout << "[ WARNING ]\n";
	std::cout << "I think I deserve to have some extra bacon for free.\n";
	std::cout << "I've been coming for years whereas you started working here since last month.\n\n";
}

void Harl::_error(void)
{
	std::cout << "[ ERROR ]\n";
	std::cout << "This is unacceptable! I want to speak to the manager now.\n\n";
}

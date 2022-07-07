/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:38:26 by hloke             #+#    #+#             */
/*   Updated: 2022/07/07 17:56:45 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int	main(void)
{
	PhoneBook	myNicePhone;
	std::string	command;
	
	while (true)
	{
		command = getStringInput("Enter a command ( ADD | SEARCH | EXIT ): ");
		if (command.compare("ADD") == 0)
			myNicePhone.addContactInfo();
		else if (command.compare("SEARCH") == 0)
			myNicePhone.displayPhoneBook();
		else if (command.compare("EXIT") == 0)
			break ;
	}	
	return (0);
}

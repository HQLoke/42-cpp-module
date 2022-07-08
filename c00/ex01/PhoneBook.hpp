/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 10:22:11 by hloke             #+#    #+#             */
/*   Updated: 2022/07/08 10:54:52 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iomanip>
# include <iostream>
# include <string>
# include <stdlib.h>
# include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook();
		PhoneBook(const PhoneBook &p1);
		~PhoneBook();
		
		void	addContactInfo();
		void	displayPhoneBook();

	private:
		int		_contactCount;
		Contact	_contactList[8];
		
		void	_putColumnStr(std::string string, int width);
		void	_getContactInfo();
};

std::string	getStringInput(const char *prompt);

#endif

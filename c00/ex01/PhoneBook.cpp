/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 10:22:06 by hloke             #+#    #+#             */
/*   Updated: 2022/07/08 10:52:28 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	_contactCount = 0;
}

PhoneBook::PhoneBook(const PhoneBook &p1)
{
	(void)p1;
}

PhoneBook::~PhoneBook(){}

/*
 * Given a column,
 * Put the string in a given width space and right-justified.
 * Truncate the string if string length is more than 10.
 */ 
void PhoneBook::_putColumnStr(std::string string, int width)
{
	if (string.length() >= 10)
	{
		string = string.substr(0, 9);
		string.append(".");
	}
	std::cout << "|" << std::setw(width) << string;
}

/*
 * Returns 1 if string contains non-digit character.
 */
static bool isNumber(const std::string str)
{
	for (size_t i = 0; i < str.length(); i += 1)
	{
		if (isdigit(str[i]) != 1)
			return (false);
	}
	return (true);
}

void PhoneBook::_getContactInfo()
{
	std::string	temp;
	int			index;
	
	do
	{
		temp = getStringInput("Enter index 0-7 for contact info: ");
		if (isNumber(temp) == true)
			index = stoi(temp, 0, 10);
	} while (isNumber(temp) != true || index < 0 || index > 7);
	std::cout << "First Name: " << _contactList[index].firstName << std::endl;
	std::cout << "Last Name: " << _contactList[index].lastName << std::endl;
	std::cout << "Nickname: " << _contactList[index].nickname << std::endl;
	std::cout << "Phone Number: " << _contactList[index].phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << _contactList[index].darkestSecret << std::endl;
}

/*
 * Prompt the user for information to put into a contact
 */
void PhoneBook::addContactInfo()
{
	if (_contactCount != 8)
		_contactCount += 1;
	for (int i = _contactCount - 1; i > 0; i -= 1)	
		_contactList[i] = _contactList[i - 1];
	_contactList[0].firstName = getStringInput("First Name: ");
	_contactList[0].lastName = getStringInput("Last Name: ");
	_contactList[0].nickname = getStringInput("Nickname: ");
	_contactList[0].phoneNumber = getStringInput("Phone Number: ");
	_contactList[0].darkestSecret = getStringInput("Darkest Secret: ");
}

/*
 * Display the phonebook in a table format
 */
void PhoneBook::displayPhoneBook()
{
	std::cout << std::string(45, '-') << std::endl;
	std::cout << "|   Index  |First Name| Last Name| Nickname |" << std::endl;
	std::cout << std::string(45, '-') << std::endl;
	for (int i = 0; i < 8; i += 1)
	{
		_putColumnStr(std::to_string(i), 10);
		_putColumnStr(_contactList[i].firstName, 10);
		_putColumnStr(_contactList[i].lastName, 10);
		_putColumnStr(_contactList[i].nickname, 10);
		std::cout << "|" << std::endl;
	}
	std::cout << std::string(45, '-') << std::endl;
	_getContactInfo();
}

/*
 * Prompt the user to enter a string as input
 * Keep prompting the user if string length is zero
 */ 
std::string getStringInput(const char *prompt)
{
	std::string temp;

	std::cout << prompt;
	std::getline(std::cin, temp);
	while (temp.size() <= 0)
	{
		if (std::cin.eof())
			exit (1);
		std::cout << prompt;
		std::getline(std::cin, temp);
	}
	return (temp);
}
